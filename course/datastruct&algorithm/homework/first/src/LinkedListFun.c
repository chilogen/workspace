#include "../include/LinkedList.h"
#include "../include/Status.h"
#include <stdio.h>
#include <stdlib.h>

Status SingleListRetrive(SingleListPtr L,long pos,long * value)
{
	SingleListPtr p=L;
	long i=0;
	while(i<pos)
	{
		if(!(p->next))	return range_error;
		p=p->next;
		i++;
	}
	*value=p->data;
	return success;
}

Status SingleListLocate(SingleListPtr L,long value,long * pos)
{
	SingleListPtr p=L->next;
	long i=1;
	while(p)
	{
		if(p->data==value)
		{
			*pos=i;
			return	success;
		}
		p=p->next;
		i++;
	}
	return fail;
}

//Status SingleListSetPostion(SingleListPtr L,long pos,SingleListPtr ptr)

Status SingleListInsert(SingleListPtr L,long pos,long value)
{
	SingleListPtr p=L,q;
	q=(SingleListPtr)malloc(sizeof(SingleList));
	q->data=value;
	long i=0;
	pos--;
	while(i<pos)
	{
		if(!p->next)	return range_error;
		p=p->next;
		i++;
	}
	q->next=p->next;
	p->next=q;
	return success;
}

//Status SingleListRemove(SingleListPtr L,long pos)

Status SingleListCreate(SingleListPtr *L,long * array,long len)
{
	long i=0;
	(*L)=(SingleListPtr)malloc(sizeof(SingleList));
	if(!(*L))	return memfail;
	SingleListPtr p=*L,q;
	while(i<len)
	{
		q=(SingleListPtr)malloc(sizeof(SingleList));
		if(!q)	return memfail;
		q->data=array[i];
		p->next=q;
		p=q;
		i++;
	}
	return success;
}

//Status SingleListInit(SingleListPtr L)

Status SingleListDestory(SingleListPtr L)
{
	free(L);
	return success;
}

Status SingleListClear(SingleListPtr L)
{
	SingleListPtr p=L;
	while(p)
	{
		p->data=0;
		p=p->next;
	}
	return success;
}
/*
Status SingleListPrior(SingleListPtr L,long pos,long *value)

Status SingleListNext(SingleListPtr L,long pos,long *value)
*/
inline int SingleListEmpty(SingleListPtr L)
{
	if(L)	return 0;
	else return 1;
}
/*
long SingleListSize(SingleListPtr L)


Status DoubleListRetrive(DoubleListPtr L,long pos,long * value)

Status DoubleListLocate(DoubleListPtr L,long value,long * pos)

Status DoubleListSetPostion(DoubleListPtr L,long pos,DoubleListPtr ptr)

Status DoubleListInsert(DoubleListPtr L,long pos,long value)

Status DoubleListRemove(DoubleListPtr L,long pos)

Status DoubleListCreate(DoubleListPtr L,long * array,long len)

Status DoubleListInit(DoubleListPtr L)

Status DoubleListDestory(DoubleListPtr L)

Status DoubleListClear(DoubleListPtr L)

Status DoubleListPrior(DoubleListPtr L,long pos,long *value)

Status DoubleListNext(DoubleListPtr L,long pos,long *value)

inline bool DoubleListEmpty(DoubleListPtr L)

long DoubleListSize(DoubleListPtr L)
*/
void SingleListPrint(SingleListPtr L)
{
	SingleListPtr p=L;
	p=p->next;
	while(p)
	{
		printf("%ld ",p->data);
		p=p->next;
	}
	printf("\n");
}