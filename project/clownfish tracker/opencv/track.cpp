#include "opencv2/opencv.hpp"
#include <string>
using namespace std;
using namespace cv;
bool pause=true;
int Time=1;
Mat img[501];
Rect trackrec;
char command;
int hbinNum = 16;
float hranges[] = {0,180};
const float* phranges = hranges;
int i2str(int num,string &s)
{
	string ts;
	string::iterator a;
	string::reverse_iterator b;
	int i,j=0;;
	while(num!=0)
	{
		i=num%10;
		j++;
		num/=10;
		ts.push_back('0'+i);
	}
	s.resize(j);
	b=ts.rbegin();	a=s.begin();
	while(b!=ts.rend())
	{
		s.insert(a,*b);
		a++;
		b++;
	}
	return j;
}
void initrec()
{
	trackrec.x=129;	trackrec.y=53;
	trackrec.width=51;
	trackrec.height=63;
}
void process()
{
	int i,j,k,l,a[2]={0};
	Mat imag,hsv,hue,mask,backproj,hist;
	Rect trackwindow;
	string name,path;

	initrec();
	for(i=1;i<=500;i++)
	{
		j=i2str(i,name);
		name.resize(j);
		path="../img/"+name+".bmp";
		imag=imread(path);
		cvtColor(imag,hsv,CV_BGR2HSV);
		inRange(hsv, Scalar(0,30,10),Scalar(180,256,256),mask);
		hue.create(hsv.size(), hsv.depth());
		mixChannels(&hsv,1,&hue,1,a,1);
		if(i==1)
		{
			Mat roi(hue,trackrec),maskroi(mask,trackrec);
			calcHist(&roi,1,0,maskroi,hist,1,&hbinNum,&phranges);  
			normalize(hist, hist, 0, 255, CV_MINMAX);
			trackwindow=trackrec;

		}
		calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
		backproj &= mask;
		meanShift(backproj, trackwindow, TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));
		rectangle(imag,Point(trackwindow.x,trackwindow.y),Point(trackwindow.x+ \
			trackwindow.width,trackwindow.y+trackwindow.height),Scalar(0,0,255),1,CV_AA);
		img[i]=imag;
	}

}
void show()
{
	if(Time==0)	Time++;
	if(Time>500)	{pause=true;	return;}
	imshow("Track",img[Time]);
	Time++;
}
int main()
{
	namedWindow("Track",0);
	createTrackbar("Time","Track",&Time,500,0);
	process();
	while(1)
	{
		command=waitKey(30);
		if(command==27)	break;
		if(command==112)	pause=!pause;
		if(!pause)
			show();
	}
	return 0;
}