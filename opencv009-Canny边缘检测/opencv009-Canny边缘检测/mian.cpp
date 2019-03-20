//Canny 算法介绍 常用边缘检测算法
//1.高斯模糊 Gaussianblur/blur 降低噪声,把细微的点去掉
//2.灰度转换  cvtColor
//3.计算梯度  sobel/scharr
//4.非最大信号映制   边缘的信号强，对非边缘的信号进行印制
//5.高低阈值输出二值图像  大于高阈值T2的保留 低于低阈值T1的丢弃 从高于高阈值的像素出发，凡是大于T1而且相互连接的都保留，最终输出二值图像
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using  namespace cv;

int main() {

	return 0;
}