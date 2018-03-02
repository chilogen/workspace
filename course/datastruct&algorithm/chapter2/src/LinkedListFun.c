#include "LinkedList.h"
#include "Status.h"
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
	value=p->data;
	return success;
}

Status SingleListLocate(SingleListPtr L,long value,long * pos)
{
	SingleListPtr p=l;
	long i=0;
	while(p)
	{
		if(p.data==value)
		{
			pos=i;
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
	q.data=value;
	long i=0;
	while(i<pos)
	{
		if(!p)	return range_error;
		p=p->next;
		i++;
	}
	q->next=p->next;
	p->new=&q;
	return success;
}

//Status SingleListRemove(SingleListPtr L,long pos)

Status SingleListCreate(SingleListPtr L,long * array,long len)
{
	long i=0;
	L=(SingleListPtr)malloc(sizeof(SingleList));
	SingleListPtr p=L,q;
	while(i<len)
	{
		q=(SingleListPtr)malloc(sizeof(SingleList));
		q->data=array[i];
		p->next=&q;
		p=q;
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
inline bool SingleListEmpty(SingleListPtr L)
{
	if(p)	return false;
	else return true;
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
	while(p)
	{
		printf("%ld ",p->data);
		p=p->next;
	}
}