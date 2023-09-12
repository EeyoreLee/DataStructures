#include <stdio.h>
#include "SqList.h"
#include "Union.h"

void PrintElem(ElemType e)
{
    printf("%d", e);
}

int main(void)
{
    SqList La, Lb;
    InitList(&La);
    InitList(&Lb);
    ElemType elem_a[5] = {1, 2, 3, 4, 5};
    ElemType elem_b[7] = {1, 2, 3, 6, 7, 8, 9};
    for (int i = 1; i <= 5; ++i)
    {
        ListInsert(&La, i, elem_a[i - 1]);
    }
    for (int i = 1; i <= 7; ++i)
    {
        ListInsert(&Lb, i, elem_b[i - 1]);
    }
    printf("La: ");
    ListTraverse(La, PrintElem);
    printf("\n");
    printf("Lb: ");
    ListTraverse(Lb, PrintElem);
    printf("\n");
    Union(&La, &Lb);
    printf("union{La, Lb}: ");
    ListTraverse(Lb, PrintElem);
    printf("\n");
    return 0;
}