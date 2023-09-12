#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct SqList
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList(SqList *L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType *e);

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status ListInsert(SqList *L, int i, ElemType e);

void ListTraverse(SqList L, void(Visit)(ElemType));
#endif