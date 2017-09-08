//
// Created by ruofeng on 2017/8/21.
//
#include <stdio.h>

#define MAXSIZE 20      //储存空间分配
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     //定义函数类型,返回如上定义的状态码
typedef int ElemType;   //顺序表中元素的数据类型
typedef struct
{
    ElemType data[MAXSIZE];     //数组存储数据元素,最大为maxsize
    int length;                 //线性表当前长度
}sqlist;

/*先进行声明*/
Status InitList(sqlist *L);
void PrintList(sqlist *L);
Status GetElem(sqlist L,int i,ElemType *e);
Status ListInsert(sqlist *L, int i,ElemType e);
Status ListDelete(sqlist *L, int i,ElemType *e);

int main() {
    sqlist L;
    InitList(&L);
    ListInsert(&L,1,4);
    ListInsert(&L,1,5);
    ListInsert(&L,1,9);
    ElemType e;
    GetElem(L,2,&e);
    PrintList(&L);
    ListDelete(&L,2,&e);
    printf("删除之后\n");
    PrintList(&L);

    return 0;
}

/*初始化一个长度为0的顺序表*/
Status InitList(sqlist *L)
{
    L->length=0;
    return OK;
}

/*打印顺序表中的所有元素*/
void PrintList(sqlist *L)
{
    if (L->length==0)
        printf("Empty List!\n");
    for (int i = 0; i < L->length ; ++i) {
        printf("%d: %4d\n",i+1,L->data[i]);
    }
}

/*获取元素操作*/
Status GetElem (sqlist L,int i,ElemType *e)
{
    if(L.length==0||i<0||i>L.length)        //判断操作是否复合条件:数组长度不为0,指定i不小于0,i小于数组长度.否则返回错误
        return ERROR;
    *e=L.data[i-1];
    return OK;
}

/*插入元素操作*/
Status ListInsert(sqlist *L, int i,ElemType e)
{
    int k;
    if (L->length==MAXSIZE)     //若顺序表元素已经达到最大则返回错误
        return ERROR;
    if (i<1||i>L->length+1)     //传递的参数i有错误
        return ERROR;
    if (i<=L->length)           //i小于长度时,将i后的元素依次后移
    {
        for(k=L->length-1;k>=i-1;k--){
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1]=e;     //移动完毕后再给第i个元素赋值e
    L->length++;        //顺序表长度加一
    return OK;
}

/*删除元素操作*/
Status ListDelete(sqlist *L, int i,ElemType *e)
{
    int k;
    if(L->length==0)        //顺序表长度为0返回错误
        return ERROR;
    if (i<1||i>L->length)   //指定删除位置i错误
        return ERROR;

    *e=L->data[i-1];        //要删除的元素输出给e

    if (i<L->length){       //要删除的元素位置不在最后一位,则从删除位开始后每个元素都向前移动一位
        for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;            //顺序表长度减一
    return 0;
}