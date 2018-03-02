#include "../include/list.h"
#include "../include/Status"
#include <stdlib.h>

Status List_Init(ListPtr *L)
{
	(*L)=NULL;
	(*L)=(ListPtr)malloc(sizeof(List));
	if(L==NULL)	return fatal;
	(*L)->data=NULL;
	(*L)->data=(long*)malloc(sizeof(long)*101);
	if((*L)->data==NULL)	return fatal;
	(*L)->size=100;
	(*L)->length=0;
	return success;
}

inline void List_Destory(ListPtr L){free(L);}

inline void List_Clear(ListPtr L){L->length=0;}

inline int List_Empty(ListPtr L){return L->length==0;}

inline long List_Size(ListPtr L){return L->length;}

Status List_Retrive(ListPtr L,long pos,long *value)
{
	if(pos>L->length||pos<1)	return range_error;
	(*value)=L->data[pos];
	return success;
}

Status List_Locate(ListPtr L,long value,long *pos)
{
	long i;
	for(i=1;i<=L->length;i++)
	{
		if(L->data[i]==value)
		{
			*pos=i;
			return success;
		}
	}
	return fail;
}

Status List_Insert(ListPtr L,long pos,long value)
{
	if(L->length==L->size)	return overflow;
	if(pos>L->length+1||pos<1)	return range_error;
	L->length++;
	long i;
	for(i=L->length;i>pos;i--)
		L->data[i]=L->data[i-1];
	L->data[pos]=value;
	return success;
}

Status List_Delete(ListPtr L,long pos)
{
	if(pos>L->length||pos<1)	return range_error;
	L->length--;
	long i;
	for(i=pos;i<=L->length;i++)
		L->data[i]=L->data[i+1];
	return success;
}

Status List_Prior(ListPtr L,long pos,long *value)
{
	if(pos<2||pos>L->length)	return fail;
	*value=L->data[pos-1];
	return success;
}

Status List_Next(ListPtr L,long pos,long *value)
{
	if(pos<1||pos>=L->length)	return fail;
	*value=L->data[pos+1];
	return success;
}

Status List_Resize(ListPtr L,long size)
{

}