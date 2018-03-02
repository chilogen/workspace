#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct list1
{
	struct list1 * next;
	long data;
}SingleList;

typedef struct list2
{
	struct list2 * prior,* next;
	long data;
}DoubleList;

typedef SingleList * SingleListPtr;

typedef DoubleList * DoubleListPtr;


#endif