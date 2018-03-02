#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
{
	struct tree *left,*right;
};

struct tree root;

void ita(long int x,char *a)
{
	int i=31,j,len;
	for(j=0;j<32;j++)
		a[j]='0';
	while(x>1)
	{
		j=x%2;
		a[i]='0'+j;
		x=x/2;
		i--;
	}
	if(x!=0) a[i]='0'+x;
	a[32]='\0';
	return ;
}

void ati(long int *x,char *a)
{
	int i=31;
	long int j=1;
	*x=0;
	while(i>=0)
	{
		*x=*x+(a[i]-'0')*j;
		j=j*2;
		i--;
	}
}

struct tree * new()
{
	struct tree *p=(struct tree *)malloc(sizeof(struct tree));
	return p;
}

void add(long int x)
{
	char a[33];
	ita(x,a);
	int i;
	struct tree *p=&root;
	for(i=0;i<32;i++)
	{
		if(a[i]=='0') 
		{
			if(p->left==NULL)	p->left=new();
			p=p->left;
		}
		else
		{
			if(p->right==NULL)	p->right=new();
			p=p->right;
		}
	}
}


long int query(long int x)
{
	char a[33],b[33];
	struct tree *p=&root;
	ita(x,a);
	int i=0;
	for(i=0;i<32;i++)
	{
		if(a[i]=='1')
		{
			if(p->left!=NULL)	
			{
				p=p->left;
				b[i]='1';
			}
			else	
			{
				p=p->right;  
				b[i]='0';	
			}
		}
		else
		{
			if(p->right!=NULL)	
			{
				p=p->right; 
				b[i]='1';  
			}
			else	
			{
				p=p->left;  
				b[i]='0';  
			}
		}

	}
	ati(&x,b);
	return x;
}

int main()
{
	int n,m;
	int i,k;
	long int j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&j);
		add(j);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%ld",&j);
		printf("%ld\n",query(j));
	}
	return 0;
}