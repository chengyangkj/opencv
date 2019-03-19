#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int thresh = 130;
int max_count = 255;
void Harris_Demo(int, void *);
const char* output_title = "input img";
Mat gray_src, src;
int main(int argc, char **argv) {

	src = imread("F:/opencv/InputImg/h4.jpg");
	if (src.empty()) { cout << "文件打开失败！"; return -1; }
	namedWindow("input img", CV_WINDOW_AUTOSIZE);
	imshow("input img", src);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	cvtColor(src, gray_src, COLOR_BGR2GRAY);  //转换图像
	createTrackbar("Threshod:", output_title, &thresh, max_count, Harris_Demo); //定义拖拉框
	Harris_Demo(0,0);
	waitKey(0);
	return 0;
}
void Harris_Demo(int, void*) {
	Mat dst, norm_dst, normScaleDst;
	dst = Mat::zeros(gray_src.size(), CV_32FC1);
	int blockSize = 2;
	int keySize = 3;
	double k = 0.04;
	cornerHarris(gray_src, dst, blockSize, keySize, k, BORDER_DEFAULT);  //调用角点检测函数
	normalize(dst, norm_dst, 0, 255, NORM_MINMAX, CV_32FC1, Mat());  //把图像规划到0-225之间
	convertScaleAbs(norm_dst, normScaleDst);

	Mat resultImg = src.clone();
	for (int row = 0; row < resultImg.rows; row++) {
		uchar* currentRow = normScaleDst.ptr(row);
		for (int col = 0; col < resultImg.cols; col++) {
			int value = (int)*currentRow;
			if (value > thresh) {
				circle(resultImg, Point(col, row), 2, Scalar(0, 0, 255), 2, 8, 0);
			}
			currentRow++;
		}
	}

	imshow(output_title, resultImg);
}