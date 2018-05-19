#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
struct cmp
{
    bool operator ()(int &a,int &b)
    {
        return a>b;
    }
};
int main()
{
    int n,a[20000];
    int c,d,i;
    int ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)    scanf("%d",&a[i]);
    priority_queue<int,vector<int>,cmp>q;
    for(i=0;i<n;i++)
        q.push(a[i]);
    while(q.size()>1)
    {
        c=q.top();
        q.pop();
        d=q.top();
        q.pop();
        ans=ans+c+d;
        q.push(c+d);
    }
    printf("%d",ans);
    return 0;
}