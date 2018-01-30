//
// Created by ruofeng on 2017/8/21.
// 静态链表：StaticLinkedList
// 数组替代指针来描述单链表
//
#include <stdio.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data;
    int cur;        //游标，相当于指针，用于存放后继元素所在数组中的下标，为0时表示无指向
}Component,StaticLinkedList[MAXSIZE];

Status InitList(StaticLinkedList space)
{
    for (int i = 0; i < MAXSIZE-1; ++i) {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;//初始化链表长度为0
    return OK;
}

/*相当于单向链表中的malloc内存分配函数*/
int Malloc_SLL(StaticLinkedList space)
{
    //静态链表头结点中的cur存放着下一个备用数组的下标，若为0，则表示没有空闲的空间
    int i=space[0].cur;

    if(space[0].cur)
        space[0].cur=space[i].cur;

    return i;
}

/*相当于单向链表中的free释放内存函数*/
void Free_SLL(StaticLinkedList space,int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}

void printList(StaticLinkedList L)
{
    if (L[MAXSIZE-1].cur==0)
        printf("Empty List!\n");
    else{
        int index=L[MAXSIZE-1].cur;
        while(index)
        {
            printf("%d ",L[index].data);
            index=L[index].cur;
        }
        printf("\n");
    }
}

/*返回静态链表L的长度*/
int ListLength(StaticLinkedList L)
{
    int length=0;//用于计数
    int i=L[MAXSIZE-1].cur;
    while (i)//下标为0时表示已到链表尾
    {
        i=L[i].cur;
        length++;
    }
    return length;
}

/*在静态链表L中第i个元素的位置插入数据e*/
Status ListInsert(StaticLinkedList L, int i, ElemType e)
{
    int j,k,l;
    k=MAXSIZE-1;//k为最后一个元素的下标
    if(!(ListLength(L)==0&&i==1)&&(i<1||i>ListLength(L)))
    {
        return ERROR;
    }

    j=Malloc_SLL(L);//获取到空闲的下标
    if (j)//j为新元素的位置
    {
        L[j].data=e;
        for (l = 1; l <=i-1 ; ++l) {//找到i-1元素的位置
            k=L[k].cur;
        }
        L[j].cur=L[k].cur;
        L[k].cur=j;
        return OK;
    }
    return ERROR;
}

/*删除静态链表L中的第i个元素*/
Status ListDelete(StaticLinkedList L, int i)
{
    if(i<1||i>ListLength(L))
        return ERROR;

    int j,k=MAXSIZE-1;
    for (j = 1; j <= i-1; ++j) {//获取到i-1位置的元素
        k=L[k].cur;
    }
    j=L[k].cur;
    L[k].cur=L[j].cur;
    Free_SLL(L,j);
    return OK;
}

int main(){
    StaticLinkedList list;
    InitList(list);
    ListInsert(list,1,123);
    ListInsert(list,1,234);
    ListInsert(list,1,654);
    /*此时链表为[654,234,123]*/
    printList(list);
    ListDelete(list,3);
    /*删除第三个数据之后为[654,234]*/
    printList(list);
    return 0;
}