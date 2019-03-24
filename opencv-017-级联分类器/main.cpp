#include <opencv2\opencv.hpp>
#include <iostream>
#include <string.h>
using namespace cv;
using namespace std;

//����ѵ�������Ŀ¼
String fileName = "F:/opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
//����ģ�Ͷ���
CascadeClassifier face_classifier;
int main() {
	//����ģ��
	if (!face_classifier.load(fileName)) {
		printf("����ģ��ʧ��");
		return -1;
	}
	Mat src = imread("F:/opencv/InputImg/licai.JPG");
	if (!src.data) {
		printf("����ͼƬʧ�ܣ�");
		return -1;
	}
	Mat gray;
	//ת��Ϊ�Ҷ�ͼ��
	cvtColor(src, gray, COLOR_BGR2GRAY);
	//ֱ��ͼ���⻯ 
	equalizeHist(gray, gray);
	//����������� �����Ľ������ 
	vector<Rect> faces;
	//���ͼ�� Size��ʾ��С���ܵĶ���Ĵ�С
	face_classifier.detectMultiScale(gray, faces, 1.2, 3, 0, Size(24, 24));
	//�ڽ���ϻ�����
	for (size_t t = 0; t < faces.size(); t++) {
		rectangle(src, faces[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
	}
	namedWindow("detect faces", CV_WINDOW_AUTOSIZE);
	imshow("detect faces", src);
	waitKey(0);
	return 0;
}