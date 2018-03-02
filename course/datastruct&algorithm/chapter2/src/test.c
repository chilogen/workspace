#include "list.h"
#include "fun.h"
#include <stdio.h>

int main()
{
	ListPtr p;
	List_Init(&p);
	printf("%ld\n%ld\n",p->length,p->size);
	List_Insert(p,1,10);
	List_Insert(p,1,10);
	List_Insert(p,1,10);
	long a;
	Status status;
	status=List_Prior(p,2,&a);
	if(status!=success)	printf("error");
	else printf("%ld\n",a);
	status=List_Prior(p,1,&a);
	if(status!=success)	printf("error");
	else printf("%ld\n",a);
	return 0;
}