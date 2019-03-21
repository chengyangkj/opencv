//�����ǻ���ͼ���Ե��ȡ�û�����ȥѰ������ ���Ա�Ե��ȡ����ֵѡ����Ӱ�������������ֵĽ��
//����
//����ͼ��ת��Ϊ�Ҷ�ͼ�� cvtColor
//��������findContours
//��������drawContours
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

Mat src, dst;
const char* output_win = "findcontours-demo";
int threshold_value = 100;
int threshold_max = 255;
RNG rng;
void Demo_Contours(int, void*);
int main(int argc, char** argv) {
	src = imread("F:/opencv/InputImg/man3.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input-image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow("input-image", src);
	//ת��Ϊ�Ҷ�ͼ��
	cvtColor(src, src, CV_BGR2GRAY);

	const char* trackbar_title = "Threshold Value:";
	createTrackbar(trackbar_title, output_win, &threshold_value, threshold_max, Demo_Contours);
	Demo_Contours(0, 0);

	waitKey(0);
	return 0;
}

void Demo_Contours(int, void*) {
	Mat canny_output;
	//��������ȥ�������ĵ����� �������� (��ά)
	vector<vector<Point>> contours;
	//��������������˽ṹ��
	vector<Vec4i> hierachy;
	//canny��Ե���
	Canny(src, canny_output, threshold_value, threshold_value * 2, 3, false);
	//��������
	//���������󷵻ص��Ƕ�ά�ĵ����� Point��ʾ���ֳ���������λ�ƵĴ�С
	findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	//��ʼ��dst
	dst = Mat::zeros(src.size(), CV_8UC3);
	RNG rng(12345);
	for (size_t i = 0; i < contours.size(); i++) {
		//���������������ɫ ���������ɫ
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//������ Point��ʾ���ֳ���������λ�ƵĴ�С
		drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
	}
	imshow(output_win, dst);
}
