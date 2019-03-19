#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc,char **argv) {
	Mat src;
	src = imread("F:/opencv/InputImg/h4.jpg");
	if (src.empty()) {
		cout << "文件打开失败！" << endl;
		return -1;
	}
	namedWindow("input img", CV_WINDOW_AUTOSIZE);
	imshow("input", src);
	//创建一个空白的画布
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(255, 255, 255);//设置画布的颜色
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	//克隆
	Mat dst2 = src.clone();
	namedWindow("clon", CV_WINDOW_AUTOSIZE);
	imshow("CLON", dst2);
	const uchar * firstRow = src.ptr<uchar>(0); //获取第一行的地址的值
	cout << "firstrow" << *firstRow << endl;
	cout << "通道数" << src.channels() << endl;
	//输出M变量
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255)); // 2 2 行列数，8 8位 ，uc uchar， 3 三通道
	cout << "M" << endl << M << endl;
	//部分复制，完全复制
	Mat B(src); //部分复制，只复制src的头指针 指向同一个数据
	Mat src2 = src.clone(); //完全复制复制所有的数据
	Mat g;
	src.copyTo(g); //完全复制
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);  //定义小数组
	filter2D(src, dst, -1, kernel);//-1 位置代表深度 锐化操作
	Mat m2 = Mat::zeros(src.size(), src.type());  //黑色图像 zeros代表0，即为黑色
	waitKey(0);
	return 0;
}