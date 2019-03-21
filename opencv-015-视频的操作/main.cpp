#include <opencv2\opencv.hpp>
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
	//��ȡԭͼ���size
	Size size = Size(capture.get(CV_CAP_PROP_FRAME_WIDTH), capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	//��ʼ��writer
	VideoWriter writer("F:/opencv/OutputImg/w_demo.avi", -1, 5,size ,false);
	Mat frame,gray,thres;
	namedWindow("video demo",CV_WINDOW_AUTOSIZE);
	//��ȡÿһ֡��Ƶ ������frame��
	while (capture.read(frame)) {
		//ת��Ϊ�Ҷ�ͼ��
		cvtColor(frame, gray, CV_BGR2GRAY);
		//��ֵ����
		threshold(gray, thres, 54, 255, 0);
		imshow("video demo", thres);
		//д��ͼ��
		writer.write(thres);
		//ÿ100������ͣһ��
		char c = waitKey(50);
		if (c == 27) {
			break;
		}
	}
	//�ͷ���Դ
	capture.release();
	writer.release();
	waitKey(0);
	return 0;
}