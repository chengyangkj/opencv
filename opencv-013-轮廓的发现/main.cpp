//轮廓是基于图像边缘提取得基础上去寻找轮廓 所以边缘提取的阈值选定会影响最终轮廓发现的结果
//步骤
//输入图像转换为灰度图像 cvtColor
//发现轮廓findContours
//绘制轮廓drawContours
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

Mat src, dst;
const char* output_win = "findcontours-demo";
int threshold_value = 100;
int threshold_max = 255;
RNG rng;
void Demo_Contours(int, void*);
int main(int argc, char** argv) {
	src = imread("F:/opencv/InputImg/man3.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input-image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow("input-image", src);
	//转换为灰度图像
	cvtColor(src, src, CV_BGR2GRAY);

	const char* trackbar_title = "Threshold Value:";
	createTrackbar(trackbar_title, output_win, &threshold_value, threshold_max, Demo_Contours);
	Demo_Contours(0, 0);

	waitKey(0);
	return 0;
}

void Demo_Contours(int, void*) {
	Mat canny_output;
	//定义容器去存放输出的点坐标 轮廓对象 (二维)
	vector<vector<Point>> contours;
	//定义容器存放拓扑结构层
	vector<Vec4i> hierachy;
	//canny边缘检测
	Canny(src, canny_output, threshold_value, threshold_value * 2, 3, false);
	//发现轮廓
	//发现轮廓后返回的是二维的点坐标 Point表示发现出来的轮廓位移的大小
	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//初始化dst
	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++) {
		//定义绘制轮廓的颜色 随机生成颜色
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//画轮廓 Point表示发现出来的轮廓位移的大小
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	imshow(output_win, dst);
}
