#include <opencv2\opencv.hpp>
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
	//获取原图像的size
	Size size = Size(capture.get(CV_CAP_PROP_FRAME_WIDTH), capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	//初始化writer
	VideoWriter writer("F:/opencv/OutputImg/w_demo.avi", -1, 5,size ,false);
	Mat frame,gray,thres;
	namedWindow("video demo",CV_WINDOW_AUTOSIZE);
	//读取每一帧视频 并存入frame里
	while (capture.read(frame)) {
		//转换为灰度图像
		cvtColor(frame, gray, CV_BGR2GRAY);
		//阈值处理
		threshold(gray, thres, 54, 255, 0);
		imshow("video demo", thres);
		//写入图像
		writer.write(thres);
		//每100毫秒暂停一次
		char c = waitKey(50);
		if (c == 27) {
			break;
		}
	}
	//释放资源
	capture.release();
	writer.release();
	waitKey(0);
	return 0;
}