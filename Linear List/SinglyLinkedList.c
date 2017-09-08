//
// Created by ruofeng on 2017/8/21.
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
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

Status InitList(LinkList *L);
Status GetElem(LinkList L,int i,ElemType *e);
Status ListInsert(LinkList *L,int i,ElemType e);
Status ListDelete(LinkList *L,int i,ElemType *e);
Status ClearList(LinkList *L);
void CreateList(LinkList *L,int n);
void PrintList(LinkList *L);

int main(){
    LinkList L;
    InitList(&L);
    CreateList(&L,5);
    PrintList(&L);
    ElemType e;
    GetElem(L,2,&e);
    printf("Get: %d\n",e);
    ListInsert(&L,3,123);
    printf("After insert:\n");
    PrintList(&L);
    ListDelete(&L,4,&e);
    printf("After delete element: %d\n",e);
    PrintList(&L);
    return 0;
}

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

/*返回单向链表L中第i个元素并储存到e中*/
Status GetElem(LinkList L,int i,ElemType *e)
{
    if(L->next==NULL){
        printf("Empty list!\n");
        return OK;
    } else {
        LinkList p;
        p=L->next;
        int j;
        j = 1;
        while(p&&j<i){      //使p指向要找的第i个节点
            p=p->next;
            ++j;
        }
        if(!p||j>i)     //若该节点为空则返回错误
            return ERROR;
        *e=p->data;     //节点存在则将节点中的数据赋值给e
        return OK;
    }

}

/*向单向链表L的i个元素位置插入元素e*/
Status ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList p,s;       //p为定位的节点,s为插入节点
    p=*L;
    int j;
    j=1;
    while(p&&j<i){      //将p指向链表L所需要插入的位置i
        p=p->next;
        j++;
    }
    if(!p||j>i)         //若得p为空节点则返回错误
        return ERROR;
    s=(LinkList)malloc(sizeof(Node));       //将s节点赋空间
    s->data=e;      //要插入的数值e赋值到节点s中以供插入
    s->next=p->next;    //修改指向关系以插入s到p前面
    p->next=s;
    return OK;
}

/*删除单向链表L中第i个节点并将删除节点的数据返回给e*/
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    LinkList p,q;       //p为定位节点,q为辅助节点
    p=*L;
    int j=1;
    while(p->next&&j<i){    //p指向要删除的节点
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i)
        return ERROR;
    q=p->next;      //q指向p的下一个节点
    p->next=q->next;    //
    *e=q->data;
    free(q);
    return OK;
}

/*清空单向链表*/
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while(p){       //只要p指向的不是尾节点则执行释放
        q=p->next;  //辅助节点q指向p的下一个
        free(p);    //释放p节点
        p=q;        //成功释放节点后p再指向原下一个节点
    }
    (*L)->next=NULL;//释放完毕后将L的头结点的next指向空
    return OK;
}


