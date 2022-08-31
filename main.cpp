#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void main() {

	VideoCapture cap(0);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	Mat img;


	while (true) {
		cap.read(img);

		vector<Rect> faces;

		faceCascade.detectMultiScale(img, faces, 1.3, 5);

		cout << faces.size() << endl;

		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
			rectangle(img, Point(0, 0), Point(250, 70), Scalar(50, 50, 255), FILLED);
			putText(img, to_string(faces.size()) + " Face Found", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 255, 255), 1);
		}


		imshow("Image", img);
		waitKey(1);


	}
}