#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <algorithm>  
#define Max 50010 // 最大n限制  
#define Inf 1000000010 // 无穷大  
using namespace std;  
typedef struct Point{   
    int x;  
    int y;  
}point;  
point node[Max];  
int n;  
int det(int x1,int y1,int x2,int y2){ // 叉积  
    return x1*y2-x2*y1;  
}  
int cross(point A,point B,point C,point D){ // AB叉积CD  
    return det(B.x-A.x,B.y-A.y,D.x-C.x,D.y-C.y);  
}  
int dis(point A,point B){ // AB之间距离的平方  
    return (B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y);  
}  
/*int cmp(const void *s,const void *t){ // 与qsor对应的排序cmp函数，注意返回值为1时则要交换，为-1时不交换，为0时不确定（避免为0情况） 
    point a=(*(point*)s); 
    point b=(*(point*)t); 
    int temp=cross(node[0],a,node[0],b);  
    if(temp>0) // 若为逆时针方向，则不交换 
        return -1; 
    else if(temp==0) // 若共线，则距离极点近的靠前（注意这里处理上避免了0） 
        return dis(node[0],a)-dis(node[0],b); 
    else // 若为顺时针方向，要交换 
        return 1; 
}*/  
bool cmp(const point s,const point t){ // sort函数排序要快于qsort,故尽量用sort排序，本题两者的排序时间分别为110MS（sort) 、125MS(qsort)  
    //point a=(*(point*)s);    // true则不交换，false则交换，也要注意sort的常见用法  
    //point b=(*(point*)t);  
    int temp=cross(node[0],s,node[0],t);  
    if(temp>0)  
        return true;  
    else if(temp==0)  
        return dis(node[0],s)<dis(node[0],t);//dis(node[0],a)-dis(node[0],b);  
    else  
        return false;  
}  
int main(){  
    scanf("%d",&n);  
    int i,k,index=0;  
    node[0].x=Inf,node[0].y=Inf; //初始化横、纵坐标均为正无穷，方便求最左（优先级1）最下（优先级2）的点，也可求最下最左的点作为极点  
    for(i=1;i<=n;i++){  
        scanf("%d%d",&node[i].x,&node[i].y);  
        if(node[i].x<node[index].x)  
            index=i;  
        else if(node[i].x==node[index].x){  
            if(node[i].y<node[index].y)  
                index=i;  
        }  
    }  
    node[0]=node[index]; // 赋值记录极点  
    //qsort(node+1,n,sizeof(point),cmp);  
    sort(node+1,node+1+n,cmp); // 以极点为基准，按极角从小到大排序  
    node[n+1]=node[0]; // 为求凸包，使得为一整圈（首尾相连）  
    k=3; // 从第四个点开始扫描  
    for(i=4;i<=n+1;i++){  
        while(cross(node[k-1],node[k],node[k],node[i])<0) // 若扫描发现方向为顺时针，则向后退  
            k--;  
        node[++k]=node[i]; // 若为逆时针或共线，则向前进  
    }  
    int max_dis=-Inf; // 初始化最大值我负无穷  
    for(i=1;i<k;i++)  
        for(int j=i+1;j<k;j++){  
            int temp=dis(node[i],node[j]);  
            if(temp>max_dis) // 求最大值  
                max_dis=temp;  
        }  
    printf("%d\n",max_dis); // 输出最大值  
    return 0;  
}  
  