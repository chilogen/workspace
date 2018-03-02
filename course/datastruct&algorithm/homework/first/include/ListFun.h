#ifndef LIST_FUN
#define LIST_FUN

Status List_Init(ListPtr *L);

inline void List_Destory(ListPtr L);

inline void List_Clear(ListPtr L);

inline int List_Empty(ListPtr L);

inline long List_Size(ListPtr L);

Status List_Retrive(ListPtr L,long pos,long *value);

Status List_Locate(ListPtr L,long value,long *pos);

Status List_Insert(ListPtr L,long pos,long value);

Status List_Delete(ListPtr L,long pos);

Status List_Prior(ListPtr L,long pos,long *value);

Status List_Next(ListPtr L,long pos,long *value);

Status List_Resize(ListPtr L,long size);


#endif