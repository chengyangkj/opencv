
/*图像形态学的操作-基于形状的一系列图像处理操作的合集
形态学操作有四个基本操作：腐蚀，膨胀，开，闭
*/
/*
膨胀 以最大的锚点值替换 图像向背景膨胀
腐蚀 以最小的锚点值替换 背景向图像腐蚀
*/
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
Mat src, dst;
char output_window[] = "ouput img";
int element_size = 3;
int max_size = 21;
//定义callbard的函数
void CallBar(int, void *);
int main(int argc, char **argv) {
	src = imread("F:/opencv/InputImg/小猫.png");
	if (!src.data) {
		cout << "打开失败" << endl;
		return -1;
	}
	namedWindow("input img", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);


	namedWindow(output_window, CV_WINDOW_AUTOSIZE);
	//创建拖拉条 第一个参数写名称，第二个写要放置的窗口，第三个为要进行变化的值的地址，第四个写变化到的最大值，第五个写要控制的函数注意此函数必须传入（int ， void*）
	createTrackbar("element size", output_window, &element_size, max_size, CallBar);
	//调用一次callbar的函数
	CallBar(0, 0);
	
	waitKey(0);
	return 0;
}

void CallBar(int, void*) {
	int s = element_size * 2 + 1;
	Mat structElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	//进行膨胀操作
	//dilate(src, dst, structElement, Point(-1, -1), 1);
	//进行腐蚀操作
	erode(src, dst, structElement, Point(-1, -1), 1);
	imshow(output_window, dst);
}