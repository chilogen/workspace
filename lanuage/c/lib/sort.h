//data is  the data need to compare
//type_size is the compare data's size,use for pointer increase
//fun use to choose sort method,include quick sort(qsort),bool,bubble sort(bsort),stack sort(ssort),bucket sort(ksort),insert sort(isort),classfify sort(csort)
//order 0 meaning discrease,1 meaning increase
#ifndef SORT_H
#define SORT_H
#define INCREASE 1
#define DISCREASE 0

void sort(void *data,unsigned long type_size,char *fun,int order);
void qsort(void *data,unsigned long type_size)
#endif
