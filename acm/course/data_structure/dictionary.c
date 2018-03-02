//字典树，小写字母版本
#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct dict
{
	int flag;
	struct dict *d[26];
}*root;


void creat(char s[])
{
	struct dict *p=root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int n=s[i]-'a';
		if(p->d[n]==NULL)
		{
			p->d[n]=(struct dict*)malloc(sizeof(struct dict));
			p->d[n]->flag=1;
			p=p->d[n];
		}
		else p=p->d[n];
	}
	p->flag=-1;
}

int find(char s[])
{
	struct dict *p=root;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int n=s[i]-'a';
		if(p->d[n]==NULL) return 1;
		else p=p->d[n];
	}
	return p->flag;
}

int main()
{
	root=(struct dict*)malloc(sizeof(struct dict));
	printf("Creat:\n");
	for(int i=0;i<10;i++)
	{
		char s[10];
		scanf("%s",s);
		creat(s);
	}
	printf("Find:\n");
	for(int i=0;i<5;i++)
	{
		char s[10];
		scanf("%s",s);
		printf("%d\n",find(s));
	}
	return 0;
}
