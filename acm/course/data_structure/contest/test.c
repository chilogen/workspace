#include<stdio.h>
#include<string.h>
void mul(char a[],char b[],char c[])
{
	int lena=strlen(a),lenb=strlen(b);
	int i,j,k;
	int ta[500000],tb[500000],tc[500000]={0};
	for(i=0;i<lena;i++)
	{
		ta[i]=a[lena-i-1]-'0';
	}
	for(j=0;j<lenb;j++)
	{
		tb[j]=b[lenb-j-1]-'0';
	}
	for(i=0;i<lena;i++)
	{
		for(j=0;j<lenb;j++)
		{
			tc[i+j]+=ta[i]*tb[j];
		}
	}
	for(i=0;i<=lena+lenb-2;i++)
	{
		tc[i+1]+=tc[i]/10;
		tc[i]=tc[i]%10;
	}
	if(tc[lena+lenb-1]==0) k=2;
	else k=1;
	for(i=0;i<lena+lenb-k+1;i++)
	{
		c[lena+lenb-i-k]='0'+tc[i];
	}
}

void spil(int i,char a[])
{
        int j=0;
        char b[500000];
        while(i/10!=0)
        {
                b[j]='0'+i%10;
                j++;
                i=i/10;
        }
        b[j]='0'+i;
        for(i=0;i<=j;i++)
        {
                a[j-i]=b[i];
        }
}

int main()
{
	char a[500000],c[500000];
	int i,j;
	a[0]='1';
	for(i=1;i<500000;i++)
		a[i]='\0';

	scanf("%d",&i);
	while(i!=1)
	{
		for(j=0;j<500000;j++)	c[j]='\0';
		spil(i,c);
		mul(a,c,a);
		i--;
	}
	printf("%s",a);
	return 0;
}