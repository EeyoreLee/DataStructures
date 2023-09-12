#include "MergeList.h"
SqList MergeList(SqList La, SqList Lb)
{
    SqList Lc;
    InitList(&Lc);
    int i, j;
    i = 0;
    j = 0;
    int n = 0;
    while (i < La.length && j < Lb.length)
    {
        if (La.elem[i] <= Lb.elem[j])
        {
            ListInsert(&Lc, ++n, La.elem[i]);
            i++;
        }
        else
        {
            ListInsert(&Lc, ++n, Lb.elem[j]);
            j++;
        }
    }
    if (i < La.length)
    {
        for (; i < La.length; ++i)
        {
            ListInsert(&Lc, ++n, La.elem[i]);
        }
    }
    if (j < Lb.length)
    {
        for (; j < Lb.length; ++j)
        {
            ListInsert(&Lc, ++n, Lb.elem[j]);
        }
    }
    return Lc;
}