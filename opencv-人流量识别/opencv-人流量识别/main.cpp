#include <opencv2\opencv.hpp>
#include <iostream>
#include <string.h> 
using namespace cv;
using namespace std;
void get_change(Mat fram);
//定义训练结果的目录
String fileName = "F:/opencv/InputImg/people/cascade.xml";
//定义模型对象
CascadeClassifier face_classifier;
int flag = 0;
int main() {
	//加载模型
	if (!face_classifier.load(fileName)) {
		printf("加载模型失败");
		return -1;
	}
	VideoCapture capture;
	capture.open("F:/opencv/InputImg/people/123.mp4");
	Mat fram;
	Mat gray;
	namedWindow("detect faces", CV_WINDOW_AUTOSIZE);
	//定义矩形容器 将检测的结果放入 
	vector<Rect> faces;
	while (capture.read(fram))
	{
		//转换为灰度图像
		cvtColor(fram, gray, COLOR_BGR2GRAY);
		//直方图均衡化 
		equalizeHist(gray, gray);
	
		//检测图像 Size表示最小接受的对象的大小
		face_classifier.detectMultiScale(gray, faces, 1.3, 8, 0, Size(18, 18));
		//画线
		Point p1 = Point(0, fram.rows / 2);   //坐标
		Point p2 = Point(fram.cols, fram.rows / 2);
		Scalar color = Scalar(255, 0, 255);
		line(fram, p1, p2, color, 1, LINE_8);  //画线
		Point roi;
		int roi_row;
		int roi_col;
		for (size_t t = 0; t < faces.size(); t++) {
			rectangle(fram, faces[t], Scalar(0, 0, 255), 2, 8, 0);
			//将目标范围内某个像素改为绿色
			roi.x = faces[t].x*1.1;
			roi.y = faces[t].y*1.1;
			//cout << fram.at<Vec3b>(roi_row, roi_col)[0] << endl;
			//fram.at<Vec3b>(roi_row, roi_col)[1] = 255;
			//fram.at<Vec3b>(roi_row, roi_col)[2] = 0;
			circle(fram, roi, 3, Scalar(0, 255, 0), -3); //第五个参数我设为-1，表明这是个实点。		
		}
		get_change(fram);
		imshow("detect faces", fram);
		cout << flag << endl;
		char c = waitKey(30);
		//当输入的按键为ESC时退出
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
