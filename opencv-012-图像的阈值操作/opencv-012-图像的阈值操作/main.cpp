#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
//阈值变化共有五种不同的类型
Mat src, gray_src, dst;
int threshold_vlaue = 127;
int threshold_max = 255;
int type_vlaue = 2;
int type_max = 4;
const char* output_title = "binary image";
void Threshold_bar(int, void*);
int main(int argc, char** argv) {
	src = imread("F:/opencv/InputImg/man3.png");
	if (!src.data) {
		printf("打开图像失败！");
		return -1;
	}
	//转换为灰度图像
	cvtColor(src, gray_src, CV_BGR2GRAY);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	//创建阈值变化大小的trackbar
	createTrackbar("threshold value", output_title, &threshold_vlaue, threshold_max, Threshold_bar);
	//创建阈值类型变化的trackbar
	createTrackbar("type value", output_title, &type_vlaue, type_max, Threshold_bar);
	//初始化trackbar函数
	Threshold_bar(0, 0);
	waitKey(0);
	return 0;
}
//变化阈值的trackbar函数
void Threshold_bar(int, void*) {
	threshold(gray_src, dst, threshold_vlaue, threshold_max, type_vlaue);
	imshow(output_title, dst);
}

