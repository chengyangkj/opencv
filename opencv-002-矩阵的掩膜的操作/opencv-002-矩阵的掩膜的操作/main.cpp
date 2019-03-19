#include <opencv2\opencv.hpp>
#include <iostream>
#include <math.h>
using namespace std;
using namespace cv;
int main(int argc,char **argv)
{
	Mat src, dst; //����cv����
	src = imread("F:/opencv/InputImg/h4.jpg");
	if (!src.data) { cout << "open failed" << endl; return -1; }
	namedWindow("input window", CV_WINDOW_AUTOSIZE);
	imshow("input img", src);
	int cols = src.cols*src.channels();  //ͼ�����Ŀ�ȣ�����������ͼ�������*ͨ��������������ͨ������ÿ�����ص�������ͨ��������ֵ��
	int offsetx = src.channels(); //��ȡͼ���ͨ����
	int rows = src.rows;
	dst = Mat::zeros(src.size(), src.type());//��ʼ��Ҫ�����ͼ�����
	for (int row = 1; row < (rows - 1); row++) {  //�ӵڶ��е������ڶ��н��в���
		const uchar* current = src.ptr<uchar>(row);  //��ȡ��ǰ�е�ͷָ��
		const uchar* previous=src.ptr<uchar>(row + 1); //��ȡ��һ�е�ָ��
		const uchar* next = src.ptr<uchar>(row-1);  //��ȡ��һ�е�ָ��
		uchar *output = dst.ptr<uchar>(row); //��ȡҪ���ͼ���ÿ�е�ͷָ����ڸ�ֵ����
		for (int col = src.channels(); col < cols; col++) {  //��ÿ�н��б���
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));//���ù�ʽ�����񻯴���
		}//saturate_cast<uchar> ����������0��255֮��
	}
	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("new img", dst);
	//����2 ����ϵͳapi
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);//������ĥ��ʽ
	filter2D(src, dst, src.depth(), kernel);//����ϵͳapi������ĥ

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	imshow("api img", dst);
	waitKey(0);
	return 0;
}
