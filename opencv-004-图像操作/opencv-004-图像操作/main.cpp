#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src, gray_src;
	src = imread("F:/opencv/InputImg/h4.jpg");
	if (src.empty()) cout << "图像打开失败" << endl;
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input img", src);
	cvtColor(src, gray_src, CV_BGR2GRAY);  //改变为单通道
	int width = gray_src.cols;
	int height = gray_src.rows;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int gray=gray_src.at<uchar>(row, col); //读取像素值
			gray_src.at<uchar>(row, col) = 255 - gray;//反差图像
		}
	}
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("反差图像", gray_src);  //单通道反差
	//多通道反差
	Mat dst;
	dst.create(src.size(), src.type());
	height = src.rows;
	width = src.cols;
	int channels = src.channels();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (channels == 1) {  //单通道
			int gray = gray_src.at<uchar>(row, col); //读取像素值
					gray_src.at<uchar>(row, col) = 255 - gray;//反差图像
			}
			else if (channels == 3) {
				int r = src.at<Vec3b>(row, col)[0];   //vec3b 读取成3个 byte图像
				int g= src.at<Vec3b>(row, col)[1];
				int b = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - r;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - b;
			}
		}
	}
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("多通道反差图像", dst);  //多通道反差
	//调用系统api 进行反差
	bitwise_not(src, dst);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("多通道反差图像", dst);  //多通道反差
	waitKey(0);
}