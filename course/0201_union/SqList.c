#include <SqList.h>
Status InitList(SqList *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (L->elem == NULL)
    {
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

int ListLength(SqList L)
{
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e)
{
    if (i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType))
{
    if (L.elem == NULL)
    {
        return ERROR;
    }
    for (int i = 0; i < L.length; ++i)
    {
        if (Compare(L.elem[i + 1], e))
        {
            return i + 1;
        }
    }
    return 0;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    if (L == NULL || L->elem == NULL)
    {
        return ERROR;
    }
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    if (L->length >= L->listsize)
    {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (newbase == NULL)
        {
            exit(OVERFLOW);
        }
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType *q = &(L->elem[i - 1]);
    for (ElemType *p = L->elem[L->length - 1]; p >= q; --p)
    {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    return OK;
}

void ListTraverse(SqList L, void(Visit)(ElemType))
{
    for (int i = 0; i < L.length; ++i)
    {
        Visit(L.elem[i]);
    }
}