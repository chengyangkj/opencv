//BS�㷨
//--1.ͼ��ָGMM -��˹���ģ�ͣ� ���������ǳ���
//--2.����ѧϰ��KNN -k�����ڣ�
// api BackgroundSubtractorMOG2 BackgroundSubtractorKNN �����ĸ����ͣ�BackgroundSubtractor
#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	VideoCapture capture;
	capture.open("F:/opencv/InputImg/������_�˶�.mp4");
	if (!capture.isOpened()) {
		printf("��Ƶ��ʧ��");
		return -1;
	}
	Mat fram;
	Mat bsmaskpMOG2, bsmaskpKNN;
	namedWindow("inputvideo", CV_WINDOW_AUTOSIZE);
	namedWindow("MOG2", CV_WINDOW_AUTOSIZE);
	namedWindow("KNN", CV_WINDOW_AUTOSIZE);
	//����ָ������
	Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2();
	Ptr<BackgroundSubtractor> pKNN = createBackgroundSubtractorKNN();
	while (capture.read(fram)) {
		imshow("input video", fram);
		pMOG2->apply(fram, bsmaskpMOG2);
		imshow("MOG2", bsmaskpMOG2);
		pMOG2->apply(fram, bsmaskpKNN);
		imshow("KNN", bsmaskpKNN);
		char c = waitKey(50);
		if (c == 27) {
			break;
		}
	}
	capture.release();
	return 0;
}