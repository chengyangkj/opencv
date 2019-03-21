#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
using namespace cv;
//��ֵ�仯�������ֲ�ͬ������
Mat src, gray_src, dst;
int threshold_vlaue = 127;
int threshold_max = 255;
int type_vlaue = 2;
int type_max = 4;
const char* output_title = "binary image";
void Threshold_bar(int, void*);
int main(int argc, char** argv) {
	src = imread("F:/opencv/InputImg/man3.png");
	if (!src.data) {
		printf("��ͼ��ʧ�ܣ�");
		return -1;
	}
	//ת��Ϊ�Ҷ�ͼ��
	cvtColor(src, gray_src, CV_BGR2GRAY);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	//������ֵ�仯��С��trackbar
	createTrackbar("threshold value", output_title, &threshold_vlaue, threshold_max, Threshold_bar);
	//������ֵ���ͱ仯��trackbar
	createTrackbar("type value", output_title, &type_vlaue, type_max, Threshold_bar);
	//��ʼ��trackbar����
	Threshold_bar(0, 0);
	waitKey(0);
	return 0;
}
//�仯��ֵ��trackbar����
void Threshold_bar(int, void*) {
	threshold(gray_src, dst, threshold_vlaue, threshold_max, type_vlaue);
	imshow(output_title, dst);
}

