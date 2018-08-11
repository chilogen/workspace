#include <bits/stdc++.h>
using namespace std;
class IntervalIntersections{
public:
	int  minLength(int x1,int y1,int x2,int y2){
		if(x1>x2){
			x1^=x2;x2^=x1;x1^=x2;
			y1^=y2;y2^=y1;y1^=y2;
		}
		if(x1==x2){
			return 0;
		}
		if(x2<=y1&&y2<=y1)return 0;
		else if(x2>y1)return x2-y1;
	}
};
int main(){
	return 0;
}