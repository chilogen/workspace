#include "opencv2/opencv.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace cv;
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
int main()
{
	string name,path;
	int i,j,k,l;
	char command;
	Mat img[501];
	bool pause=false;
	namedWindow("show",0);
	for(i=1;i<=500;i++)
	{
		j=i2str(i,name);
		name.resize(j);
		path="../img/"+name+".bmp";
		img[i]=imread(path);
	}
	i=1;
	createTrackbar( "Vmin", "show", &i, 500, 0 );
	while(1)
	{
		command=waitKey(30);
		if(command==27)	break;
		if(command==112)	pause=!pause;
		if(!pause)
		{
			if(i==0)	i++;
			if(i>500)	pause=true;
			imshow("show",img[i]);
			i++;
		}
	}
	return 0;
}