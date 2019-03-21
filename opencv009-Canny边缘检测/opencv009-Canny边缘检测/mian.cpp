//Canny 算法介绍 常用边缘检测算法
//1.高斯模糊 Gaussianblur/blur 降低噪声,把细微的点去掉
//2.灰度转换  cvtColor
//3.计算梯度  sobel/scharr
//4.非最大信号映制   边缘的信号强，对非边缘的信号进行印制
//5.高低阈值输出二值图像 一般高阈值是低阈值的3倍 大于高阈值T2的保留 低于低阈值T1的丢弃 从高于高阈值的像素出发，凡是大于T1而且相互连接的都保留，最终输出二值图像
//canny api包括第3,4,5步

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using  namespace cv;
Mat src, dst, gray_src;
//低阈值和高阈值
int t1_value = 50;
int max_value = 255;
const char* output_title = "Canny result";
void Canny_Demo(int, void*);
int main() {
	src = imread("F:/opencv/InputImg/man2.png");
	if (!src.data) {
		printf("打开图片失败！");
		return -1;
	}
	char Input_title[] = "input_img";
	namedWindow(Input_title, CV_WINDOW_AUTOSIZE);
	imshow(Input_title, src);
	namedWindow(output_title);
	//将输入图像转为灰度图像
	
	cvtColor(src, gray_src, CV_BGR2GRAY);
	createTrackbar("Canny value:", output_title, &t1_value, max_value, Canny_Demo);
	waitKey(0);
	return 0;
}

void Canny_Demo(int, void*) {
	Mat edge_output;
	//高斯模糊，去掉噪点
	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	//Canny处理 填入高低阈值 高阈值是低阈值的三倍
	Canny(gray_src, edge_output, t1_value, t1_value * 3, 3,false);
	//原色轮廓
	imshow("原色轮廓", edge_output);
	//原色取反轮廓
	imshow("原色取反轮廓", ~edge_output);
	//使用copyTo获取彩色轮廓 edge_output为无色轮廓
	dst.create(src.size(), src.type());
	src.copyTo(dst,edge_output);
	imshow(output_title, dst);
}