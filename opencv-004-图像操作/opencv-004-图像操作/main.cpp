#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	Mat src, gray_src;
	src = imread("F:/opencv/InputImg/h4.jpg");
	if (src.empty()) cout << "ͼ���ʧ��" << endl;
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input img", src);
	cvtColor(src, gray_src, CV_BGR2GRAY);  //�ı�Ϊ��ͨ��
	int width = gray_src.cols;
	int height = gray_src.rows;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int gray=gray_src.at<uchar>(row, col); //��ȡ����ֵ
			gray_src.at<uchar>(row, col) = 255 - gray;//����ͼ��
		}
	}
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("����ͼ��", gray_src);  //��ͨ������
	//��ͨ������
	Mat dst;
	dst.create(src.size(), src.type());
	height = src.rows;
	width = src.cols;
	int channels = src.channels();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (channels == 1) {  //��ͨ��
			int gray = gray_src.at<uchar>(row, col); //��ȡ����ֵ
					gray_src.at<uchar>(row, col) = 255 - gray;//����ͼ��
			}
			else if (channels == 3) {
				int r = src.at<Vec3b>(row, col)[0];   //vec3b ��ȡ��3�� byteͼ��
				int g= src.at<Vec3b>(row, col)[1];
				int b = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - r;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - b;
			}
		}
	}
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("��ͨ������ͼ��", dst);  //��ͨ������
	//����ϵͳapi ���з���
	bitwise_not(src, dst);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("��ͨ������ͼ��", dst);  //��ͨ������
	waitKey(0);
}