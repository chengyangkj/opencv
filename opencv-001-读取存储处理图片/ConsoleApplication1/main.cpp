
#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
using namespace std;
int main(int argc,char**argv)
{
	Mat src = imread("F:\\opencv\\InputImg\\h4.jpg",IMREAD_UNCHANGED);//,IMREAD_GRAYSCALE��Ϊ�Ҷ�ͼ����ؽ���
	if (src.empty()) {
		cout << "�򿪴���" << endl;
		return -1;
	}
	namedWindow("opencv setup window", CV_WINDOW_AUTOSIZE);  //����opencv���� AUTOSIZE�Զ��ı䴰�ڴ�С��������Ϊ��Ԥ
	imshow("opencv setup demo", src);  //��ʾͼ��
	namedWindow("output window ", CV_WINDOW_AUTOSIZE);
	Mat outout_image;
	cvtColor(src, outout_image, CV_BGR2GRAY); //ת��ͼ����һ��ɫ�ʿռ� ת��Ϊ�Ҷ�
	imshow("output window", outout_image);
	imwrite("F:/opencv/OutputImg/opencv001.png", outout_image); //����ͼƬ
	waitKey(0);
	return 0;
}

