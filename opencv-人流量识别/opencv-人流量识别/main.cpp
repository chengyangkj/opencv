#include <opencv2\opencv.hpp>
#include <iostream>
#include <string.h> 
using namespace cv;
using namespace std;
void get_change(Mat fram);
//����ѵ�������Ŀ¼
String fileName = "F:/opencv/InputImg/people/cascade.xml";
//����ģ�Ͷ���
CascadeClassifier face_classifier;
int flag = 0;
int main() {
	//����ģ��
	if (!face_classifier.load(fileName)) {
		printf("����ģ��ʧ��");
		return -1;
	}
	VideoCapture capture;
	capture.open("F:/opencv/InputImg/people/123.mp4");
	Mat fram;
	Mat gray;
	namedWindow("detect faces", CV_WINDOW_AUTOSIZE);
	//����������� �����Ľ������ 
	vector<Rect> faces;
	while (capture.read(fram))
	{
		//ת��Ϊ�Ҷ�ͼ��
		cvtColor(fram, gray, COLOR_BGR2GRAY);
		//ֱ��ͼ���⻯ 
		equalizeHist(gray, gray);
	
		//���ͼ�� Size��ʾ��С���ܵĶ���Ĵ�С
		face_classifier.detectMultiScale(gray, faces, 1.3, 8, 0, Size(18, 18));
		//����
		Point p1 = Point(0, fram.rows / 2);   //����
		Point p2 = Point(fram.cols, fram.rows / 2);
		Scalar color = Scalar(255, 0, 255);
		line(fram, p1, p2, color, 1, LINE_8);  //����
		Point roi;
		int roi_row;
		int roi_col;
		for (size_t t = 0; t < faces.size(); t++) {
			rectangle(fram, faces[t], Scalar(0, 0, 255), 2, 8, 0);
			//��Ŀ�귶Χ��ĳ�����ظ�Ϊ��ɫ
			roi.x = faces[t].x*1.1;
			roi.y = faces[t].y*1.1;
			//cout << fram.at<Vec3b>(roi_row, roi_col)[0] << endl;
			//fram.at<Vec3b>(roi_row, roi_col)[1] = 255;
			//fram.at<Vec3b>(roi_row, roi_col)[2] = 0;
			circle(fram, roi, 3, Scalar(0, 255, 0), -3); //�������������Ϊ-1���������Ǹ�ʵ�㡣		
		}
		get_change(fram);
		imshow("detect faces", fram);
		cout << flag << endl;
		char c = waitKey(30);
		//������İ���ΪESCʱ�˳�
		if (c == 27) {
			break;
		}
	}

	waitKey(0);
	return 0;
}
void get_change(Mat fram) {
	int height = fram.rows;
	int width = fram.cols;
	int row = height / 2;
	//cout << fram.at<Vec3b>(row,3) << endl;
	for (int col = 0; col <width; col++) {
		if (fram.at<Vec3b>(row, col)[1] == 255) {
			flag++;
		}
	}
}
