
/*ͼ����̬ѧ�Ĳ���-������״��һϵ��ͼ��������ĺϼ�
��̬ѧ�������ĸ�������������ʴ�����ͣ�������
*/
/*
���� ������ê��ֵ�滻 ͼ���򱳾�����
��ʴ ����С��ê��ֵ�滻 ������ͼ��ʴ
*/
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
Mat src, dst;
char output_window[] = "ouput img";
int element_size = 3;
int max_size = 21;
//����callbard�ĺ���
void CallBar(int, void *);
int main(int argc, char **argv) {
	src = imread("F:/opencv/InputImg/Сè.png");
	if (!src.data) {
		cout << "��ʧ��" << endl;
		return -1;
	}
	namedWindow("input img", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);


	namedWindow(output_window, CV_WINDOW_AUTOSIZE);
	//���������� ��һ������д���ƣ��ڶ���дҪ���õĴ��ڣ�������ΪҪ���б仯��ֵ�ĵ�ַ�����ĸ�д�仯�������ֵ�������дҪ���Ƶĺ���ע��˺������봫�루int �� void*��
	createTrackbar("element size", output_window, &element_size, max_size, CallBar);
	//����һ��callbar�ĺ���
	CallBar(0, 0);
	
	waitKey(0);
	return 0;
}

void CallBar(int, void*) {
	int s = element_size * 2 + 1;
	Mat structElement = getStructuringElement(MORPH_RECT, Size(s, s), Point(-1, -1));
	//�������Ͳ���
	//dilate(src, dst, structElement, Point(-1, -1), 1);
	//���и�ʴ����
	erode(src, dst, structElement, Point(-1, -1), 1);
	imshow(output_window, dst);
}