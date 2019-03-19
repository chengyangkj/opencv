
#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main(int argc,char**argv)
{
	Mat src = imread("F:\\opencv\\InputImg\\h4.jpg",IMREAD_UNCHANGED);//,IMREAD_GRAYSCALE作为灰度图像加载进来
	if (src.empty()) {
		cout << "打开错误" << endl;
		return -1;
	}
	namedWindow("opencv setup window", CV_WINDOW_AUTOSIZE);  //创建opencv窗口 AUTOSIZE自动改变窗口大小，不能人为干预
	imshow("opencv setup demo", src);  //显示图像
	namedWindow("output window ", CV_WINDOW_AUTOSIZE);
	Mat outout_image;
	cvtColor(src, outout_image, CV_BGR2GRAY); //转换图像到另一个色彩空间 转换为灰度
	imshow("output window", outout_image);
	imwrite("F:/opencv/OutputImg/opencv001.png", outout_image); //保存图片
	waitKey(0);
	return 0;
}

