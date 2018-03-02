#**c**语言指针

1. 指针与结构体
	
* 代码


		#include<stdio.h>
		struct abc
		{
			int a;
			int b;
		};
		
		int main（）
		{
			void *p;
			struct abc m[2];
			m[0].a=1;
			m[0].b=2;
			m[1].a=3;
			m[1].b=4;
			p=&m;
			printf("%d %d",*(int *)p,*(int *)(p+1)); //输出结果为1 2
			printf("%d",*(int *)(p+sizeof(struct abc)*1));//输出结果为3
		}

* 结论
> *  结构体变量每个元素在内存中的地址是连续的
> * 数组在内存中的地址是连续的
> * int *p; p+1=(void *)p+1*sizeof(int);