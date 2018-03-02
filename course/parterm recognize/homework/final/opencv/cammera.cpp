#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat imag;
	bool pause=false;
	char c;
	namedWindow("cammera",0);
	VideoCapture a(0);
	while(1)
	{
		c=waitKey(30);
		switch (c)
		{
			case 27 :return 0;
			case 112:pause=!pause;
		}
		if(!pause)
		{
			a>>imag;
			imshow("cammera",imag);
		}
	}
	return 0;
}