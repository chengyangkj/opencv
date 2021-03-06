#include <opencv2\opencv.hpp>
#include <iostream>
#include <string.h>
using namespace cv;
using namespace std;

//定义训练结果的目录
String fileName = "F:/opencv/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
//定义模型对象
CascadeClassifier face_classifier;
int main() {
	//加载模型
	if (!face_classifier.load(fileName)) {
		printf("加载模型失败");
		return -1;
	}
	VideoCapture capture(0);
	Mat fram;
	Mat gray;
	while (capture.read(fram))
	{
		//转换为灰度图像
		cvtColor(fram , gray, COLOR_BGR2GRAY);
		//直方图均衡化 
		equalizeHist(gray, gray);
		//定义矩形容器 将检测的结果放入 
		vector<Rect> faces;
		//检测图像 Size表示最小接受的对象的大小
		face_classifier.detectMultiScale(gray, faces, 1.2, 3, 0, Size(24, 24));
		//在结果上画矩形
		for (size_t t = 0; t < faces.size(); t++) {
			rectangle(gray, faces[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
		}
		namedWindow("detect faces", CV_WINDOW_AUTOSIZE);
		imshow("detect faces", fram);
		char c = waitKey(50);
		//当输入的按键为ESC时退出
		if (c == 27) {
			break;
		}
	}
	
	waitKey(0);
	return 0;
}