#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc,char **argv)
{
	Mat src, dst; //定义cv变量
	src = imread("F:/opencv/InputImg/h4.jpg");
	if (!src.data) { cout << "open failed" << endl; return -1; }
	namedWindow("input window", CV_WINDOW_AUTOSIZE);
	imshow("input img", src);
	int cols = src.cols*src.channels();  //图像矩阵的宽度（列数）等于图像的列数*通道数（红绿蓝三通道）（每个像素点存的是三通道的像素值）
	int offsetx = src.channels(); //获取图像的通道数
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());//初始化要输出的图像变量
	for (int row = 1; row < (rows - 1); row++) {  //从第二行到倒数第二行进行操作
		const uchar* current = src.ptr<uchar>(row);  //获取当前行的头指针
		const uchar* previous=src.ptr<uchar>(row + 1); //获取上一行的指针
		const uchar* next = src.ptr<uchar>(row-1);  //获取下一行的指针
		uchar *output = dst.ptr<uchar>(row); //获取要输出图像的每行的头指针便于赋值操作
		for (int col = src.channels(); col < cols; col++) {  //对每列进行遍历
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));//利用公式进行锐化处理
		}//saturate_cast<uchar> 处理数据在0到255之间
	}
	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("new img", dst);
	//方法2 调用系统api
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//定义研磨方式
	filter2D(src, dst, src.depth(), kernel);//调用系统api进行研磨

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("api img", dst);
	waitKey(0);
	return 0;
}
