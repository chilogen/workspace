/*
*point inclusion in polygon test
*even work if some edge no straight
*algorithm:
*calc how much degree does the polygon rotate relate to the point
*if it is 360 degree,the point in the polygon
*if it is 180 degree,the point on the edge
*if it is 0	  degree,the point out of the polygon
*to avoid the accuracy in calc cos and sin,we use a ray that y=querypoint.y,
*just we need to do is calc how much time does the polygon's edge through the
*ray.And if it throught form down to up,cnt++,otherwise,cnt--
*if cnt equare to zero,the point out of the polygon
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point
{
	double x,y;
};


point polygon[5000];

int main()
{
	ll n,i,j,cnt;
	double k,b,x1,y1,x2,y2;
	cout<<"give the num of the polygon vertex :"<<endl;
	cin>>n;
	cout<<"and the give the vertex's coordinate clockwise or counterclockwise"<<endl;
	for(i=1;i<=n;i++)
		cin>>polygon[i].x>>polygon[i].y;
	cout<<"give the point which you want to query:"<<endl;
	cin>>polygon[0].x>>polygon[0].y;

	cnt=0;
	y1=polygon[0].y;

	for(i=1;i<=n;i++)
	{
		j=i+1;
		if(j>n)	j=1;
		x2=polygon[j].x-polygon[i].x;
		y2=polygon[j].y-polygon[i].y;

		if(x2==0)
		{
			cout<<"not accept a line parallel to the x-axis"<<endl;
			return 0;
		}
		if(y2==0)
		{
			cout<<"nor accept a line parallel to the y-axis"<<endl;
			return 0;
		}
		k=y2/x2;	b=polygon[i].y-k*polygon[i].x;
		
		x1=(y1-b)/k;

		if((x1-polygon[i].x)*(x1-polygon[j].x)<0)
		{
			if(polygon[i].y<y1)	cnt++;
			else cnt--;
		}
	}

	if(cnt!=0)	cout<<"the point in polygon"<<endl;
	else cout<<"the point out of polygon"<<endl;
	return 0;
}