#include "Union.h"

Status equal(ElemType a, ElemType b)
{
    return a == b ? TRUE : FALSE;
}

void Union(SqList *La, SqList *Lb)
{
    int length_a, length_b;
    ElemType e;
    length_a = La->length;
    length_b = Lb->length;
    for (int i = 1; i <= length_a; ++i)
    {
        e = La->elem[i];
        if (!LocateElem(*Lb, e, equal))
        {
            ListInsert(Lb, ++length_b, e);
        }
    }
}