#include "camInterface.hpp"
#include <boost/filesystem.hpp>
#include <iostream>
#include "util/util.hpp"

CamInterface::CamInterface(){};

void CamInterface::setWindowName(string windowName){
    this->windowName = windowName;
}
int CamInterface::getNextFile(){
    string p = this->filePath;
    string id = "0";
    vector<int> nextIdVec;
    int nextId = 0;
 
    if (boost::filesystem::is_directory(p) && !boost::filesystem::is_empty(p)){
        boost::filesystem::directory_iterator end_iter;
        for (boost::filesystem::directory_iterator dir_itr(p);dir_itr != end_iter;++dir_itr){
            id = dir_itr->path().filename().string();
            util::removePngFormat(id);
            int temp = nextId;          
            nextIdVec.push_back(stoi(id));
        }
    }else{
        return nextId;
    }
    nextId = *max_element(nextIdVec.begin(), nextIdVec.end());
    return nextId+1;
}

void CamInterface::setFilePath(string filePath){
    this->filePath = filePath;
}

string CamInterface::getFilePath(){
    return this->filePath;
}

void CamInterface::setMorePictures(bool morePictures){
    this->morePictures = morePictures;
}
    
bool CamInterface::getMorePictures(){
    return this->morePictures;
}


int CamInterface::openVideoCapture(bool recognize) {
	// Load the cascade
    if (!face_cascade.load(face_cascade_name)){
        printf("--(!)Error loading\n");
        return (-1);
    }

    VideoCapture capture; 
    Mat frame, image;
 
    // PreDefined trained XML classifiers with facial features
    CascadeClassifier cascade, nestedCascade; 
    double scale=1;

    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video
    capture.open(0);

    int recognizedCount = 0;

    if( capture.isOpened() )
    {
        // Capture frames from video and detect faces
        cout << "Face Detection Started...." << endl;
        int countPictures = 0;
        while(1)
        {
            capture >> frame;
            if( frame.empty() )
                break;
            Mat frame1 = frame.clone();
            
            bool save = false;
            char s = (char)waitKey(10);

            // Press s to save a picture
            if(s == 's' || s == 'S' ){
                save = true;
            } 

            //return the croped image of face to be tested
            Mat imgTest = detectAndDisplay(frame,save,countPictures,recognize);

            //save only 10 images
            if(countPictures == 10 && !recognize){
               break;
            }

            if(recognize){
                bool isRecognized = false;
                if(!imgTest.empty()){
                    isRecognized = this->recognizeFace(imgTest);
                   
                    if(isRecognized){
                        recognizedCount++;
                    }else{
                        recognizedCount--;
                    }

                    if(recognizedCount >= 15){
                        return 1;
                    }else if(recognizedCount < -15){
                        return -1;
                    }
                }
            }
            
            char c = (char)waitKey(10);
            // Press q to exit from window
            if( c == 27 || c == 'q' || c == 'Q' ){
                break;
            }

        }
    }else{
        cout<<"Could not Open Camera";
    }

}

// Function detectAndDisplay
Mat CamInterface::detectAndDisplay(Mat frame, bool save, int &countPictures,bool recognize){
    std::vector<Rect> faces;
    Mat frame_gray;
    Mat crop;
    Mat res;
    Mat gray;
    string text;
    stringstream sstm;

    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    // Set Region of Interest
    cv::Rect roi_b;
    cv::Rect roi_c;

    size_t ic = 0; // ic is index of current element
    int ac = 0; // ac is area of current element

    size_t ib = 0; // ib is index of biggest element
    int ab = 0; // ab is area of biggest element

    // Iterate through all current elements (detected faces)
    for (ic = 0; ic < faces.size(); ic++) {
        roi_c.x = faces[ic].x;
        roi_c.y = faces[ic].y;
        roi_c.width = (faces[ic].width);
        roi_c.height = (faces[ic].height);

        ac = roi_c.width * roi_c.height; // Get the area of current element (detected face)

        roi_b.x = faces[ib].x;
        roi_b.y = faces[ib].y;
        roi_b.width = (faces[ib].width);
        roi_b.height = (faces[ib].height);

        ab = roi_b.width * roi_b.height; // Get the area of biggest element, at beginning it is same as "current" element

        if (ac > ab) {
            ib = ic;
            roi_b.x = faces[ib].x;
            roi_b.y = faces[ib].y;
            roi_b.width = (faces[ib].width);
            roi_b.height = (faces[ib].height);
        }

        crop = frame(roi_b);
        resize(crop, res, Size(168, 192), 0, 0, INTER_LINEAR); // This will be needed later while saving images
        cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

        // Form a fileName and save
        if(save){
            if(countPictures < 10){
                countPictures++;
                this->saveAndEqualizeImage(gray);
            }
        }

        Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
        Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
        rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
    }

    // Show image
    //sstm << "Crop area size: " << roi_b.width << "x" << roi_b.height << " Filename: " << filePath;
    
    if(recognize){
        sstm << "Reconhecendo o rosto, aguarde um instante..."; 
    }else{
        sstm << "Aperte <S> 10 vezes para salvar o rosto detectado!"<<"Foto: "<< this->getNextFile(); 
    }

    text = sstm.str();

    putText(frame, text, cvPoint(30, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 0, 255), 1, CV_AA);
    imshow("original", frame);

    if (!crop.empty()){
        imshow("detected", crop);
        Mat recognized; 
        resize(crop, res, Size(168, 192), 0, 0, INTER_LINEAR);
        crop.copyTo(recognized);
        return recognized;
    }else{
        destroyWindow("detected");
    }
}

bool CamInterface::recognizeFace(Mat imgTest){
    
    vector<Mat> images = this->getPersonImages();
    vector<int> labels = this->getImagesLabel();
    Mat grayTest;

    //transform imgTest to grayScale
    cvtColor(imgTest,grayTest,CV_BGR2GRAY,1);

    //equalize images histogram
    Ptr<CLAHE> clahe = createCLAHE();
    Mat cl1;
    clahe->setClipLimit(4);
    clahe->apply(grayTest,grayTest);

    Ptr<LBPHFaceRecognizer> model = LBPHFaceRecognizer::create(2,16);
    
    model->setThreshold(126.0);
    model->train(images, labels);
    int predictedLabel = model->predict(grayTest);
    
    if(predictedLabel == -1){
        return false;
    }else{
        return true;
    }
}

vector<Mat> CamInterface::getPersonImages(){

    vector<Mat> personImages;
    vector<string> filenames;
       
    this->readFileNames(filenames); 
    for(size_t i = 0; i < filenames.size(); ++i){
        personImages.push_back(imread(this->filePath+"/"+filenames[i], 0));
    }
    return personImages;
}

vector<int> CamInterface::getImagesLabel(){
    string p = this->filePath;
    vector<string> filenames;
    vector<int> imagesLabel;
    string label = "0";
    
    this->readFileNames(filenames);
    for(size_t i = 0; i < filenames.size(); ++i){
        label = filenames[i];
        util::removePngFormat(label);
        imagesLabel.push_back(stoi(label));
    }
    std::sort(imagesLabel.begin(),imagesLabel.end());
    return imagesLabel;
}

void CamInterface::readFileNames(vector<string> &filenames){
    string p = this->filePath;
    
    if (boost::filesystem::is_directory(p) && !boost::filesystem::is_empty(p)){
        boost::filesystem::directory_iterator end_iter;
        for (boost::filesystem::directory_iterator dir_itr(p);dir_itr != end_iter;++dir_itr){
            filenames.push_back(dir_itr->path().filename().string());
        }
        std::sort(filenames.begin(),filenames.end());
    }

}

void CamInterface::saveAndEqualizeImage(Mat &gray){
    stringstream ssfn;
    string fileToSave = this->getFilePath();
    ssfn << this->getNextFile() << ".png";
    fileToSave += "/"+ssfn.str();

    //equalize images histogram
    Ptr<CLAHE> clahe = createCLAHE();
    Mat cl1;
    clahe->setClipLimit(4);
    clahe->apply(gray,gray);
    imwrite(fileToSave, gray);
}
