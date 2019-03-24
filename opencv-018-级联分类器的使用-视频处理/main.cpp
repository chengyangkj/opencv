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
	VideoCapture capture(0);
	Mat fram;
	Mat gray;
	while (capture.read(fram))
	{
		//ת��Ϊ�Ҷ�ͼ��
		cvtColor(fram , gray, COLOR_BGR2GRAY);
		//ֱ��ͼ���⻯ 
		equalizeHist(gray, gray);
		//����������� �����Ľ������ 
		vector<Rect> faces;
		//���ͼ�� Size��ʾ��С���ܵĶ���Ĵ�С
		face_classifier.detectMultiScale(gray, faces, 1.2, 3, 0, Size(24, 24));
		//�ڽ���ϻ�����
		for (size_t t = 0; t < faces.size(); t++) {
			rectangle(gray, faces[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
		}
		namedWindow("detect faces", CV_WINDOW_AUTOSIZE);
		imshow("detect faces", fram);
		char c = waitKey(50);
		//������İ���ΪESCʱ�˳�
		if (c == 27) {
			break;
		}
	}
	
	waitKey(0);
	return 0;
}