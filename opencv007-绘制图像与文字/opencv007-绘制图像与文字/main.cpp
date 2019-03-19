#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
Mat bgImg;
void MyLines();
void MyRectangle();
void MyCircle();
int main() {
	bgImg = imread("F:/opencv/InputImg/h4.jpg");
	if (!bgImg.data) {
		cout << "打开失败" << endl;
		return -1;
	}
	MyLines();
	namedWindow("LineImg", CV_WINDOW_AUTOSIZE);
	imshow("InPutImg", bgImg);
	MyRectangle();
	MyCircle();
	putText(bgImg, "hello opencv", Point(200, 300), CV_FONT_BLACK, 1.0, Scalar(0, 255, 255), 1, 8);
	namedWindow("RectangleImg", CV_WINDOW_AUTOSIZE);
	imshow("RectangleImg", bgImg);
	waitKey(0);
	return 0;
}
void MyLines() {
	Point p1 = Point(20, 30);   //坐标
	Point p2;
	p2.x = 300;
	p2.y = 300;
	Scalar color = Scalar(0, 0, 255);
	line(bgImg, p1, p2, color, 1, LINE_8);  //画线
}
void MyRectangle() {
	Rect rect = Rect(200, 100, 300, 300);  //矩形坐标
	Scalar color = Scalar(0, 0, 255);
	rectangle(bgImg, rect, color, 2, LINE_8);
}
void MyCircle() {
	Scalar color = Scalar(0, 255, 255);
	Point center = Point(bgImg.rows / 2, bgImg.cols / 2);
	circle(bgImg, center, 150,color);
}