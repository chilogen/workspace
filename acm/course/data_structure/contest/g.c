#include<stdio.h>
#include<string.h>
void mul(char a[],char b[],char c[])
{
	int lena=strlen(a),lenb=strlen(b);
	int i,j,k;
	int ta[20000],tb[20000],tc[2000]={0};
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
        char b[1000];
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
	char a[20000],b[20000],c[1000];
	b[0]='1';
	int i=0,j;
	scanf("%s",a);
	if(strlen(a)==1&&a[0]=='1') {printf("1"); return 0;}
	if(strlen(a)==1&&a[0]=='0') {printf("0"); return 0;}
	while(strcmp(a,b))
	{
		i++;
		if(i>6000) break;
		spil(i,c);
		mul(b,c,b);
	}
	printf("%d",i);
	return 0;
}