
#include "/usr/local/installed/opencv/modules/cudabgsegm/include/opencv2/cudabgsegm.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>
 
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main(int argc, char **argv){
	Mat frame; 
	Mat foreground;	// 前景图片
	VideoCapture capture(argv[1]);
 
	if (!capture.isOpened())
	{
		return 0;
	}
 
	namedWindow("Extracted Foreground");
	namedWindow("Source Video");
	// 混合高斯物体
	BackgroundSubtractorMOG mog;
	bool stop(false);
	while (!stop)
	{
		if (!capture.read(frame))
		{
			break;
		}
		// 更新背景图片并且输出前景
		mog(frame, foreground, 0.01);
		// 输出的前景图片并不是2值图片，要处理一下显示  
		threshold(foreground, foreground, 128, 255, THRESH_BINARY_INV);
		// show foreground
		imshow("Extracted Foreground", foreground);
		imshow("Source Video", frame);
		if (waitKey(10) == 27)
		{
			stop = true;
		}
	}
}

