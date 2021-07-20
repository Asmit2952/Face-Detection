#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////// License Plate Detector ////////////////////

void main() {

	VideoCapture cap(0);
	Mat img;

	CascadeClassifier faceCascade;
	faceCascade.load("haarcascade_frontalface_default.xml");

	if (faceCascade.empty())
	{
		cout << "XML File  not loaded" << endl;
	}

	vector<Rect> faces;

	while (true) {

		cap.read(img);

		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 2);
		}

		imshow("Image", img);
		waitKey(1);
	}
}

