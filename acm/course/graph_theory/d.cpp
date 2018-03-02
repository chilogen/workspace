#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct cmp
{
	bool operator()(const int &a,const int &b)
	{return a>b;}
};
queue <int> ans;
priority_queue <int,vector <int>,cmp> zero;
char s[1000][201];
int len[1000];
int gra[26][26]={0};
int deg[26]={0};
int minum(int i,int j)
{
	if(i<j)	return i;
	else return j;
}
void add(char *s1,char *s2,int i)
{
	int le=minum(len[i],len[i+1]),j;
	for(j=0;j<le;j++)
	{
		if(s1[j]!=s2[j])
		{
			int k=s1[j]-'a',l=s2[j]-'a';
			if(!gra[k][l])	{gra[k][l]=1;	deg[l]++;}
			return ;
		}
	}
	if(le==len[i+1]&&le!=len[i])	deg[0]++;
}
int main()
{
	int n,i,j,k;
	freopen("abc","r",stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
	}
	for(i=0;i<n-1;i++)
	{
		add(s[i],s[i+1],i);
	}
	for(i=0;i<26;i++)
	{
		if(deg[i]==0)	zero.push(i);
	}
	while(!zero.empty())
	{
		i=zero.top();
		ans.push(i);
		zero.pop();
		for(j=0;j<26;j++)
		{
			if(gra[i][j])
			{
				gra[i][j]=0;
				deg[j]--;
				if(deg[j]==0)	zero.push(j);
			}
		}
	}
	for(i=0;i<26;i++)
	{
		if(deg[i]!=0)
		{
			printf("-1");
			return 0;
		}
	}
	while(!ans.empty())
	{
		printf("%c",ans.front()+'a');
		ans.pop();
	}
	fclose(stdin);
	return 0;
}
