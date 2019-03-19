#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat src, dst;
	src = imread("F:/opencv/InputImg/h3.jpg");
	if (src.empty()) cout << "图像打开失败！";
	char input_win[] = "input img";
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	imshow(input_win, src);

	int height = src.rows;
	int width = src.cols;
	float alpha = 1.2; //对比度
	float bete = 100; //亮度
	dst = Mat::zeros(src.size(), src.type());  //创建空图像
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (src.channels() == 3) {
				float b = src.at<Vec3b>(row, col)[0]; //3f 为b g r
				float g = src.at<Vec3b>(row, col)[1]; //3f 为b g r
				float r = src.at<Vec3b>(row, col)[2]; //3f 为b g r
				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(alpha*b + bete);  //saturate_cast<uchar> 确保数据在范围内
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(alpha*g + bete);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(alpha*r + bete);
			}
		}
	}
	namedWindow(input_win, CV_WINDOW_AUTOSIZE);
	imshow("change img", dst);
	waitKey(0);
}