#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace cv;
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

String Int2String(int iUniqueName){
	stringstream ss;
	ss << iUniqueName;
	return ss.str();
}

int main(){
	String ImgFormat;
	cout<<"Format of image: ";
	cin>>ImgFormat;

	VideoCapture capture;
	capture.open("bouncingBall.avi");

	if(!capture.isOpened()){
		cout<<"Video failed to open";
		return -1;
	}

	Mat frame;
	int iUniqueName = 0;
	double percentage = 0.0;

	while(capture.get(CV_CAP_PROP_POS_FRAMES) < capture.get(CV_CAP_PROP_FRAME_COUNT)-1){
		// take frame by frame with each iteration and save that frame
		// into the mat object
		capture.read(frame);

		// create a unique name for each iteration
		String sUniqueName = Int2String(iUniqueName);

		// save the mat object as the picture in the directory we want with that unique name
		String fileName =  "C:/Users/DELL/Desktop/Video2Frames/" + sUniqueName + ImgFormat;
		imwrite(fileName, frame);

		// increment the iUniqueName
		iUniqueName++;
		
		// display the output
		percentage = ( iUniqueName / (capture.get(CV_CAP_PROP_FRAME_COUNT)-1) ) * 100;
		for(int i = 0; i<(int)percentage; i+=3){
			cout<<".";
		}
		cout<<percentage<<"%"<<endl;
	}
	capture.release();

	return 0;
}
