#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src1,src2,dst;
	src1 = imread("F:/opencv/InputImg/h4.jpg");
	src2=imread("F:/opencv/InputImg/h3.jpg");
	if (src1.empty()&& src2.empty()) cout << "ͼ���ʧ��" << endl;
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("imput", src1);
	imshow("imput", src2);
	double alpha = 0.5;// ����0.5 0-1 ֮��
	if (src1.size() == src2.size()&&src1.type() == src2.type())  //�ϳ�֮ǰҪȷ���������ͺʹ�С��ͬ
	{
		addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);
		namedWindow("output", CV_WINDOW_AUTOSIZE);
		imshow("�ϳ�ͼ��", dst);
	}
	waitKey(0);
}