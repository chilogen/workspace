#ifndef LINKEDLISTFUN
#define LINKEDLISTFUN

#include "LinkedList.h"
#include "Status.h"

Status SingleListRetrive(SingleListPtr L,long pos,long * value);

Status SingleListLocate(SingleListPtr L,long value,long * pos);

//Status SingleListSetPostion(SingleListPtr L,long pos,SingleListPtr ptr);

Status SingleListInsert(SingleListPtr L,long pos,long value);

//Status SingleListRemove(SingleListPtr L,long pos);

Status SingleListCreate(SingleListPtr *L,long * array,long len);

//Status SingleListInit(SingleListPtr L);

Status SingleListDestory(SingleListPtr L);

Status SingleListClear(SingleListPtr L);

//Status SingleListPrior(SingleListPtr L,long pos,long *value);

//Status SingleListNext(SingleListPtr L,long pos,long *value);

//inline bool SingleListEmpty(SingleListPtr L);

/*long SingleListSize(SingleListPtr L);


Status DoubleListRetrive(DoubleListPtr L,long pos,long * value);

Status DoubleListLocate(DoubleListPtr L,long value,long * pos);

Status DoubleListSetPostion(DoubleListPtr L,long pos,DoubleListPtr ptr);

Status DoubleListInsert(DoubleListPtr L,long pos,long value);

Status DoubleListRemove(DoubleListPtr L,long pos);

Status DoubleListCreate(DoubleListPtr L,long * array,long len);

Status DoubleListInit(DoubleListPtr L);

Status DoubleListDestory(DoubleListPtr L);

Status DoubleListClear(DoubleListPtr L);

Status DoubleListPrior(DoubleListPtr L,long pos,long *value);

Status DoubleListNext(DoubleListPtr L,long pos,long *value);

inline bool DoubleListEmpty(DoubleListPtr L);

long DoubleListSize(DoubleListPtr L);*/

void SingleListPrint(SingleListPtr L);

#endif