#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	//�½�videoCapture
	VideoCapture capture;
	//����Ƶ�ļ�
	capture.open("F:/opencv/InputImg/������_�˶�.mp4");
	if (!capture.isOpened()) {
		printf("����Ƶʧ�ܣ�");
		return -1;
	}
	//��ȡԭ��Ƶ��֡��
	double fps = capture.get(CV_CAP_PROP_FPS);
	printf("FPS:%f", fps);
	Mat frame, gray, thres, canny_output,dst;
	namedWindow("video demo", CV_WINDOW_AUTOSIZE);
	//��ȡÿһ֡��Ƶ ������frame��
	while (capture.read(frame)) {
		//ת��Ϊ�Ҷ�ͼ��
		cvtColor(frame, gray, CV_BGR2GRAY);
		//��˹ģ����ȥ�����
		blur(gray, gray, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
		//��ֵ����
		threshold(gray, thres, 54, 255, 0);
		//��������ȥ�������ĵ����� �������� (��ά)
		vector<vector<Point>> contours;
		//��������������˽ṹ��
		vector<Vec4i> hierachy;
		//canny��Ե���
		Canny(thres, canny_output, 62, 62 * 2, 3, false);
		//��������
		//���������󷵻ص��Ƕ�ά�ĵ����� Point��ʾ���ֳ���������λ�ƵĴ�С
		findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
		//��ʼ��dst
		dst = Mat::zeros(thres.size(), thres.type());
		RNG rng(12345);
		for (size_t i = 0; i < contours.size(); i++) {
			//���������������ɫ ���������ɫ
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			//������ Point��ʾ���ֳ���������λ�ƵĴ�С
			drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
		}
		imshow("video demo", dst);

		//ÿ100������ͣһ��
		char c = waitKey(1);
		if (c == 27) {
			break;
		}
	}
	//�ͷ���Դ
	capture.release();
	waitKey(0);
	return 0;
}