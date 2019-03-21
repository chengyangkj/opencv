#include <opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main() {
	//新建videoCapture
	VideoCapture capture;
	//打开视频文件
	capture.open("F:/opencv/InputImg/外走廊_人多.mp4");
	if (!capture.isOpened()) {
		printf("打开视频失败！");
		return -1;
	}
	//获取原视频的帧数
	double fps = capture.get(CV_CAP_PROP_FPS);
	printf("FPS:%f", fps);
	Mat frame, gray, thres, canny_output,dst;
	namedWindow("video demo", CV_WINDOW_AUTOSIZE);
	//读取每一帧视频 并存入frame里
	while (capture.read(frame)) {
		//转换为灰度图像
		cvtColor(frame, gray, CV_BGR2GRAY);
		//高斯模糊，去掉噪点
		blur(gray, gray, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
		//阈值处理
		threshold(gray, thres, 54, 255, 0);
		//定义容器去存放输出的点坐标 轮廓对象 (二维)
		vector<vector<Point>> contours;
		//定义容器存放拓扑结构层
		vector<Vec4i> hierachy;
		//canny边缘检测
		Canny(thres, canny_output, 62, 62 * 2, 3, false);
		//发现轮廓
		//发现轮廓后返回的是二维的点坐标 Point表示发现出来的轮廓位移的大小
		findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
		//初始化dst
		dst = Mat::zeros(thres.size(), thres.type());
		RNG rng(12345);
		for (size_t i = 0; i < contours.size(); i++) {
			//定义绘制轮廓的颜色 随机生成颜色
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			//画轮廓 Point表示发现出来的轮廓位移的大小
			drawContours(dst, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
		}
		imshow("video demo", dst);

		//每100毫秒暂停一次
		char c = waitKey(1);
		if (c == 27) {
			break;
		}
	}
	//释放资源
	capture.release();
	waitKey(0);
	return 0;
}