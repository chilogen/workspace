#include <bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
const double pi=acos(-1);
complex<double>a[maxn];
int b[maxn];
void FFT(complex<double> x[],int n,int p){
	int i,j,k,t,m;
    for (i=0,t=0;i<n;i++){
        if (i>t) swap(x[i],x[t]);
        for (int j=n>>1;(t^=j)<j;j>>=1);
    }
    for (m=2;m<=n;m<<=1){
        complex<double>       wn(cos(p*2*pi/m),sin(p*2*pi/m));
        for (i=0;i<n;i+=m){
            complex<double> w(1,0),u;
            k=m>>1;
            for (j=0;j<k;j++,w*=wn){
                u=x[i+j+k]*w;
                x[i+j+k]=x[i+j]-u;
                x[i+j]=x[i+j]+u;
            }
        }
    }
}
int n,m;
int main(){
	int i,j,k;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(i=0,a[0]=1,k=0;i<n;i++){
		scanf("%d",&j);
		k=max(k,j);
		a[j]=1;
	}
	n=1;k<<=1;
	while(n<k)n<<=1;
	FFT(a,n,1);
	for(i=0;i<n;i++)a[i]=a[i]*a[i];
	FFT(a,n,-1);
	for(i=0,b[0]=0;i<n;i++)b[i]=a[i].real()/n+0.5;
	scanf("%d",&m);
	for(i=0,k=0;i<m;i++){
		scanf("%d",&j);
		if(b[j]>0)k++;
	}
	printf("%d\n",k);
	return 0;
}