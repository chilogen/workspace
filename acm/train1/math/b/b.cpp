#include <bits/stdc++.h>
using namespace std;
const double PI=3.1415926535898;
class cir
{
public:
	double x,y,r;
};
double getdist(cir &a,cir &b)
{
	double dis;
	return	dis=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	int T;
	double dis,area1,area2,the1,the2,area;
	cir a,b;
	cin>>T;
	while(T--)
	{
		cin>>a.x>>a.y>>a.r>>b.x>>b.y>>b.r;
		dis=getdist(a,b);
		if(dis>=a.r+b.r)
		{
			cout<<"0.000000"<<endl;
			continue;
		}
		if(dis<=max(a.r,b.r)-min(a.r,b.r))
		{
			printf("%.6lf\n",PI*min(a.r,b.r)*min(a.r,b.r));
			continue;
		}
		the1=acos((a.r*a.r+dis*dis-b.r*b.r)/(2*a.r*dis))/PI*180;
		the2=acos((b.r*b.r+dis*dis-a.r*a.r)/(2*b.r*dis))/PI*180;
		area1=(the1/180)*PI*a.r*a.r;	area2=(the2/180)*PI*b.r*b.r;
		area=area1+area2-a.r*dis*sin(PI*(the1/180));
		printf("%.6lf\n",area);
	}
	return 0;
}