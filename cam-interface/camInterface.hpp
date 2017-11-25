#ifndef _CAMINTERFACE_HPP
#define _CAMINTERFACE_HPP
 
// Include required header files from OpenCV directory
#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>
 
using namespace std;
using namespace cv;


class CamInterface{
protected:
    string face_cascade_name = "/opt/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
    string windowName;
    CascadeClassifier face_cascade;
    int fileNumber;
    bool morePictures = false;
    string filePath;
public:
    CamInterface();

    void setWindowName(string windowName);
    int getNextFile();
    void setFilePath(string filePath);
    string getFilePath();
    void setMorePictures(bool morePictures);
    bool getMorePictures();



    int openVideoCapture();
    void detectAndDisplay(Mat frame, bool save, int &countPictures);

};
#endif
