//
// Created by ruofeng on 2017/8/21.
//
#include <stdio.h>

#define MAXSIZE 20      //����ռ����
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;     //���庯������,�������϶����״̬��
typedef int ElemType;   //˳�����Ԫ�ص���������
typedef struct
{
    ElemType data[MAXSIZE];     //����洢����Ԫ��,���Ϊmaxsize
    int length;                 //���Ա�ǰ����
}sqlist;

/*�Ƚ�������*/
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
    printf("ɾ��֮��\n");
    PrintList(&L);

    return 0;
}

/*��ʼ��һ������Ϊ0��˳���*/
Status InitList(sqlist *L)
{
    L->length=0;
    return OK;
}

/*��ӡ˳����е�����Ԫ��*/
void PrintList(sqlist *L)
{
    if (L->length==0)
        printf("Empty List!\n");
    for (int i = 0; i < L->length ; ++i) {
        printf("%d: %4d\n",i+1,L->data[i]);
    }
}

/*��ȡԪ�ز���*/
Status GetElem (sqlist L,int i,ElemType *e)
{
    if(L.length==0||i<0||i>L.length)        //�жϲ����Ƿ񸴺�����:���鳤�Ȳ�Ϊ0,ָ��i��С��0,iС�����鳤��.���򷵻ش���
        return ERROR;
    *e=L.data[i-1];
    return OK;
}

/*����Ԫ�ز���*/
Status ListInsert(sqlist *L, int i,ElemType e)
{
    int k;
    if (L->length==MAXSIZE)     //��˳���Ԫ���Ѿ��ﵽ����򷵻ش���
        return ERROR;
    if (i<1||i>L->length+1)     //���ݵĲ���i�д���
        return ERROR;
    if (i<=L->length)           //iС�ڳ���ʱ,��i���Ԫ�����κ���
    {
        for(k=L->length-1;k>=i-1;k--){
            L->data[k+1]=L->data[k];
        }
    }
    L->data[i-1]=e;     //�ƶ���Ϻ��ٸ���i��Ԫ�ظ�ֵe
    L->length++;        //˳����ȼ�һ
    return OK;
}

/*ɾ��Ԫ�ز���*/
Status ListDelete(sqlist *L, int i,ElemType *e)
{
    int k;
    if(L->length==0)        //˳�����Ϊ0���ش���
        return ERROR;
    if (i<1||i>L->length)   //ָ��ɾ��λ��i����
        return ERROR;

    *e=L->data[i-1];        //Ҫɾ����Ԫ�������e

    if (i<L->length){       //Ҫɾ����Ԫ��λ�ò������һλ,���ɾ��λ��ʼ��ÿ��Ԫ�ض���ǰ�ƶ�һλ
        for(k=i;k<L->length;k++)
            L->data[k-1]=L->data[k];
    }
    L->length--;            //˳����ȼ�һ
    return 0;
}