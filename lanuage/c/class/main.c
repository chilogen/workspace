#ifdef WIN32
#define clear system("cls")
#include<conio.h>
#endif

#ifdef linux
#define clear system("clear")
#endif
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int id;
	char name[20];
	char author[20];
	char publish[20];
}lib;
lib book[100];
int num=0;
void loadf(FILE *f);
void write(FILE *f);
void add();
void list();
void find();
void sort();
void disp()
{
	printf("#############################\n");
	printf("2016060107001 weisiqian\n");
	printf("#############################\n");
	printf("add----addbook\nlist----listbook\nfind----findbook\nquit----quit\n");
	printf("OR directly use add or list or find or quit\n");
	printf("#############################\n");
}
int main()
{
	char command[10];
	FILE *f=fopen("book.txt","r");
	loadf(f);
	fclose(f);
	clear;
	while(1)
	{
		disp();
		scanf("%s",command);
		if(strcmp(command,"addbook")==0) add();
		else if(strcmp(command,"list")==0) list();
		else if(strcmp(command,"find")==0) find();
		else if(strcmp(command,"quit")==0)  break;
		else printf("wrong input\n");
	}
	f=fopen("book.txt","w");
	write(f);
	fclose(f);
	return 0;
}
void sort()
{
	int i,j;
	int compare(char p[],char name[]);
	for(i=0;i<num;i++)
	{
		if(compare(book[i].name,book[num-1].name)==1)
		{
			lib temp=book[num-1];
			for(j=num-1;j>i;j--)
				book[j]=book[j-1];
			book[j]=temp;
			break;
		}
	}
}
void loadf(FILE *f)
{
	while(fscanf(f,"%d %s %s %s",&book[num].id,book[num].name,book[num].author,book[num].publish)!=EOF)
	{
		num++;
	}
	sort();
}
void write(FILE *f)
{
	int i;
	for(i=0;i<num;i++)
	{
		fprintf(f,"%d %s %s %s\n",book[i].id,book[i].name,book[i].author,book[i].publish);
	}
}
void list()
{
	clear;
	int i;
	for(i=0;i<num;i++)
        {
                printf("id:%d  name:%s  author:%s  date:%s\n",book[i].id,book[i].name,book[i].author,book[i].publish);
        }

}
void add()
{
	clear;
	printf("enter book id:\n");
	scanf("%d",&book[num].id);
	printf("enter bool name:\n");
	scanf("%s",book[num].name);
	printf("enter book author:\n");
	scanf("%s",book[num].author);
	printf("enter book publish date");
	scanf("%s",book[num].publish);
	num++;
	sort();
}
int compare(char p[],char name[])
{
	int size=strlen(name);
	int i;
	for(i=0;i<size;i++)
	{
		if(p[i]>name[i]) return 1;
		else if(p[i]<name[i]) return -1;
	}
	return 0;
}
void find()
{
	clear;
	char name[20];
	char *p;
	int size1,size2,i;
	printf("enter book name:");
	scanf("%s",name);
	size1=strlen(name);
	for(i=0;i<num;i++)
	{
		size2=strlen(book[i].name);
		if(size2<size1) continue;
		for(int j=0;j<size2-size1+1;j++)\
		{
			p=&book[i].name[j];
			if(compare(p,name)==0) printf("id:%d  name:%s  author:%s  date:%s\n",book[i].id,book[i].name,book[i].author,book[i].publish);
		}
	}
}
