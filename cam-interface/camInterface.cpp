#include "camInterface.hpp"

CamInterface::CamInterface(){};

void CamInterface::setWindowName(string windowName){
    this->windowName = windowName;
}
int CamInterface::getLastFile(){
    return 1;
}

void CamInterface::setFilePath(string filePath){
    this->filePath = filePath;
}

string CamInterface::getFilePath(){
    return this->filePath;
}

int CamInterface::openVideoCapture() {
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
    if( capture.isOpened() )
    {
        // Capture frames from video and detect faces
        cout << "Face Detection Started...." << endl;
        while(1)
        {
            capture >> frame;
            if( frame.empty() )
                break;
            Mat frame1 = frame.clone();
            detectAndDisplay(frame);
            char c = (char)waitKey(10);
         
            // Press q to exit from window
            if( c == 27 || c == 'q' || c == 'Q' ) 
                break;
        }
    }else{
        cout<<"Could not Open Camera";
    }
}

int number = 0;
// Function detectAndDisplay
void CamInterface::detectAndDisplay(Mat frame){
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
        resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // This will be needed later while saving images
        cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

        // Form a fileName

        if(number <= 1) {
	        stringstream ssfn;
	        string fileToSave = this->getFilePath();
	        ssfn << number << ".png";
	        fileToSave += "/"+ssfn.str();
            number++;
            cout<<fileToSave<<endl;
          	
            imwrite(fileToSave, gray);
        }

        Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
        Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
        rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
    }

    // Show image
    sstm << "Crop area size: " << roi_b.width << "x" << roi_b.height << " Filename: " << filePath;
    text = sstm.str();

    putText(frame, text, cvPoint(30, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 0, 255), 1, CV_AA);
    imshow("original", frame);

    if (!crop.empty())
    {
        imshow("detected", crop);
    }
    else
        destroyWindow("detected");
}