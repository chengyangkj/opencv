//BS算法
//--1.图像分割（GMM -高斯混合模型） 处理噪声非常好
//--2.机器学习（KNN -k个近邻）
// api BackgroundSubtractorMOG2 BackgroundSubtractorKNN 两个的父类型：BackgroundSubtractor
#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	VideoCapture capture;
	capture.open("F:/opencv/InputImg/外走廊_人多.mp4");
	if (!capture.isOpened()) {
		printf("视频打开失败");
		return -1;
	}
	Mat fram;
	Mat bsmaskpMOG2, bsmaskpKNN;
	namedWindow("inputvideo", CV_WINDOW_AUTOSIZE);
	namedWindow("MOG2", CV_WINDOW_AUTOSIZE);
	namedWindow("KNN", CV_WINDOW_AUTOSIZE);
	//定义指针类型
	Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2();
	Ptr<BackgroundSubtractor> pKNN = createBackgroundSubtractorKNN();
	while (capture.read(fram)) {
		imshow("input video", fram);
		pMOG2->apply(fram, bsmaskpMOG2);
		imshow("MOG2", bsmaskpMOG2);
		pMOG2->apply(fram, bsmaskpKNN);
		imshow("KNN", bsmaskpKNN);
		char c = waitKey(50);
		if (c == 27) {
			break;
		}
	}
	capture.release();
	return 0;
}