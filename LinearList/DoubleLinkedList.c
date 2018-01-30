//
// Created by ruofeng on 2017/9/9.
//
#include <stdio.h>
#include <malloc.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef int ElemType;
typedef struct DulNode
{
    ElemType data;
    struct DulNode *prior;
    struct DulNode *next;
}DulNode ,*DuLinkList;

/*初始化一个空的双向链表*/
Status InitList(DuLinkList *L)
{
    *L=(DuLinkList)malloc(sizeof(DulNode));      //产生一个头结点并使L指向这个头结点
    if (!(*L))
        return ERROR;       //储存空间分配失败
    //将其设为空链表，其前驱后继都指向自己
    (*L)->next=*L;
    (*L)->prior=*L;
    return OK;
}

/*随机创建一个长度为n的双向链表*/
void CreateList(DuLinkList *L,int n)
{
    DuLinkList p,Head;
    int i;
    srand(time(0));

    for(i=0;i<n;i++){
        p=(DuLinkList)malloc(sizeof(DulNode));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        p->prior=*L;
        p->next->prior=p;
        (*L)->next=p;
    }
}
