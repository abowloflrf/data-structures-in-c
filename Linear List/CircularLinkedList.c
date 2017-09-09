//
// Created by ruofeng on 2017/9/8.
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
//数据结构与单向链表一样
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

/*初始化一个空的单向链表*/
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));      //产生一个头结点并使L指向这个头结点
    if (!(*L))
        return ERROR;       //储存空间分配失败
    (*L)->next=NULL;        //将其设为空链表
    return OK;
}

/*随机创建一个长度为n的单向链表*/
void CreateList(LinkList *L,int n)
{
    LinkList p;
    int i;
    srand(time(0));

    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}

/*打印单向链表中的所有元素*/
void PrintList(LinkList *L)
{
    LinkList p=(*L)->next;
    int index=1;
    while(p){       //p不是尾节点则打印该节点数据
        printf("%2d: %4d\n",index,p->data);
        p=p->next;      //p指向下一个节点继续打印
        index++;
    }
}

/*由已知的单向链表建立L的num位置建立循环链表，即头指针指向num位置元素*/
Status BuildCircularLinkedList(LinkList *L,int num)
{
    int i=0;
    LinkList cur=*L;
    LinkList tail=NULL;

    //检查参数num与L是否有效
    if(num<=0||L==NULL)
        return ERROR;
    //检查num是否在L的长度内
    for (i = 0; i < num; ++i) {
        if(cur==NULL){
            return ERROR;
        }
        cur=cur->next;
    }

    tail=cur;
    while (tail->next)
    {
        tail=tail->next;
    }
    tail->next=cur;
    return OK;
}

/*判断链表L中是否有环*/
int hasLoop(LinkList L)
{
    LinkList p=L;
    LinkList q=L;

    while (p!=NULL&&q!=NULL&&q->next!=NULL)
    {
        p=p->next;//p每次往后指一个
        if(q->next!=NULL)
            q=q->next->next;//q每次往后指两个
        //printf("p:%d, q:%d\n",p->data,q->data);
        if(q==p)//q比往前指的快，若链表中有环，则q和p必定会相遇
            return 1;
    }
    return 0;
}

int main()
{
    LinkList list;
    InitList(&list);
    CreateList(&list,10);
    PrintList(&list);
    BuildCircularLinkedList(&list,5);
    hasLoop(list);
    return 0;
}
