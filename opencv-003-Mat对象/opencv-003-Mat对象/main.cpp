#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc,char **argv) {
	Mat src;
	src = imread("F:/opencv/InputImg/h4.jpg");
	if (src.empty()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return -1;
	}
	namedWindow("input img", CV_WINDOW_AUTOSIZE);
	imshow("input", src);
	//����һ���հ׵Ļ���
	Mat dst;
	dst = Mat(src.size(), src.type());
	dst = Scalar(255, 255, 255);//���û�������ɫ
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	//��¡
	Mat dst2 = src.clone();
	namedWindow("clon", CV_WINDOW_AUTOSIZE);
	imshow("CLON", dst2);
	const uchar * firstRow = src.ptr<uchar>(0); //��ȡ��һ�еĵ�ַ��ֵ
	cout << "firstrow" << *firstRow << endl;
	cout << "ͨ����" << src.channels() << endl;
	//���M����
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255)); // 2 2 ��������8 8λ ��uc uchar�� 3 ��ͨ��
	cout << "M" << endl << M << endl;
	//���ָ��ƣ���ȫ����
	Mat B(src); //���ָ��ƣ�ֻ����src��ͷָ�� ָ��ͬһ������
	Mat src2 = src.clone(); //��ȫ���Ƹ������е�����
	Mat g;
	src.copyTo(g); //��ȫ����
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);  //����С����
	filter2D(src, dst, -1, kernel);//-1 λ�ô������ �񻯲���
	Mat m2 = Mat::zeros(src.size(), src.type());  //��ɫͼ�� zeros����0����Ϊ��ɫ
	waitKey(0);
	return 0;
}