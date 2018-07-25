//copy from blog https://blog.csdn.net/u014609452/article/details/69647725
//add comments

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define cl(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;

const int N=35;

int n,m,C,D;
int a[N][N];

int main(){
  int T; ll K;
  scanf("%d",&T);
  while (T--){
    scanf("%lld",&K); cl(a);
    n=30,m=21; C=9,D=20;

	//将点1连到团中所有点
    for (int i=2;i<=C+1;i++)
    	a[1][i]=1;
    
	//将点2开始的点连成一个团
    for (int i=2;i<=C+1;i++)
    	for (int j=2;j<=C+1;j++)
   			a[i][j]=1;
    
	//构造连到终点的一条链
    for (int i=1;i<D;i++)
    	a[1+C+i][1+C+i+1]=1;
    
	//将点连到链上，距离终点越远，对方案数贡献越少（在小于n步的时候有可能到不了终点）
    for (int i=0;i<=19;i++){
    	for (int j=1;j<=K%C;j++)
    		a[1+j][1+C+i+1]=1;
    	K/=C;
    }

    printf("%d %d\n",n,m);
    for (int i=1;i<=n;i++,printf("\n"))
    	for (int j=1;j<=n;j++)
    		printf("%d",a[i][j]);
  }
  return 0;
}
