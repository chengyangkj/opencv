#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src1,src2,dst;
	src1 = imread("F:/opencv/InputImg/h4.jpg");
	src2=imread("F:/opencv/InputImg/h3.jpg");
	if (src1.empty()&& src2.empty()) cout << "图像打开失败" << endl;
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("imput", src1);
	imshow("imput", src2);
	double alpha = 0.5;// 参数0.5 0-1 之间
	if (src1.size() == src2.size()&&src1.type() == src2.type())  //合成之前要确认两个类型和大小相同
	{
		addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);
		namedWindow("output", CV_WINDOW_AUTOSIZE);
		imshow("合成图像", dst);
	}
	waitKey(0);
}