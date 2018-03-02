#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
	bool operator()(const int &a,const int &b)
	{return a>b;}
};
queue <int> ans;
priority_queue <int,vector <int>,cmp> zero;
char s[1000][201];
int deg[26];
int gra[26][26];
int len[1000];
int minum(int a,int b)
{
	if(a<b) return a;
	else return b;
}
void add(char *s1,char *s2,int i)
{
	int l=minum(len[i],len[i+1]),j,k;
	for(i=0;i<l;i++)
	{
		if(s1[i]!=s2[i])
		{
			j=s1[i]-'a';	k=s2[i]-'a';
			if(!gra[j][k])
			{
				gra[j][k]=1;
				deg[k]++;
			}
			return ;
		}
	}
}
int main()
{
	freopen("abc","r",stdin);
	memset(deg,0,sizeof(deg));
	memset(gra,0,sizeof(gra));
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
	}
	for(i=0;i<n-1;i++)
		add(s[i],s[i+1],i);
	for(i=0;i<26;i++)
		if(deg[i]==0)	zero.push(i);
	while(!zero.empty())
	{
		i=zero.top();
		ans.push(i);
		zero.pop();
		for(j=0;j<26;j++)
		{
			if(gra[i][j])
			{
				deg[j]--;
				gra[i][j]=0;
				if(deg[j]==0)	zero.push(j);
			}
		}
	}
	for(i=0;i<26;i++)
		if(deg[i]!=0)
		{
			printf("-1");
			return 0;
		}
	while(!ans.empty())
	{
		printf("%c",ans.front()+'a');
		ans.pop();
	}
	fclose(stdin);
	return 0;
}
