//Canny �㷨���� ���ñ�Ե����㷨
//1.��˹ģ�� Gaussianblur/blur ��������,��ϸ΢�ĵ�ȥ��
//2.�Ҷ�ת��  cvtColor
//3.�����ݶ�  sobel/scharr
//4.������ź�ӳ��   ��Ե���ź�ǿ���ԷǱ�Ե���źŽ���ӡ��
//5.�ߵ���ֵ�����ֵͼ�� һ�����ֵ�ǵ���ֵ��3�� ���ڸ���ֵT2�ı��� ���ڵ���ֵT1�Ķ��� �Ӹ��ڸ���ֵ�����س��������Ǵ���T1�����໥���ӵĶ����������������ֵͼ��
//canny api������3,4,5��

#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using  namespace cv;
Mat src, dst, gray_src;
//����ֵ�͸���ֵ
int t1_value = 50;
int max_value = 255;
const char* output_title = "Canny result";
void Canny_Demo(int, void*);
int main() {
	src = imread("F:/opencv/InputImg/man2.png");
	if (!src.data) {
		printf("��ͼƬʧ�ܣ�");
		return -1;
	}
	char Input_title[] = "input_img";
	namedWindow(Input_title, CV_WINDOW_AUTOSIZE);
	imshow(Input_title, src);
	namedWindow(output_title);
	//������ͼ��תΪ�Ҷ�ͼ��
	
	cvtColor(src, gray_src, CV_BGR2GRAY);
	createTrackbar("Canny value:", output_title, &t1_value, max_value, Canny_Demo);
	waitKey(0);
	return 0;
}

void Canny_Demo(int, void*) {
	Mat edge_output;
	//��˹ģ����ȥ�����
	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	//Canny���� ����ߵ���ֵ ����ֵ�ǵ���ֵ������
	Canny(gray_src, edge_output, t1_value, t1_value * 3, 3,false);
	//ԭɫ����
	imshow("ԭɫ����", edge_output);
	//ԭɫȡ������
	imshow("ԭɫȡ������", ~edge_output);
	//ʹ��copyTo��ȡ��ɫ���� edge_outputΪ��ɫ����
	dst.create(src.size(), src.type());
	src.copyTo(dst,edge_output);
	imshow(output_title, dst);
}