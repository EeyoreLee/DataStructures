#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
#include "MergeList.h"

void PrintElem(ElemType e)
{
    printf("%d ", e);
}

int main(void)
{
    SqList La, Lb;
    InitList(&La);
    InitList(&Lb);
    ElemType elem_a[4] = {3, 5, 8, 11};
    for (int i = 1; i <= 4; ++i)
    {
        ListInsert(&La, i, elem_a[i - 1]);
    }
    ElemType elem_b[7] = {2, 6, 8, 9, 11, 15, 20};
    for (int i = 1; i <= 7; ++i)
    {
        ListInsert(&Lb, i, elem_b[i - 1]);
    }
    printf("La: ");
    ListTraverse(La, PrintElem);
    printf("\n");
    printf("La: ");
    ListTraverse(Lb, PrintElem);
    printf("\n");
    SqList Lc = MergeList(La, Lb);
    printf("Lc: ");
    ListTraverse(Lc, PrintElem);
    printf("\n");
    return 0;
}