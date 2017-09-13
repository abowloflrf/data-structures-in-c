//
// Created by ruofeng on 2017/9/13.
//
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;//栈1的栈顶
    int top2;//另一头，栈2栈顶
    //若top1+1==top2则表示栈满，中间部分为两栈共享空间
}ShStack;

//入栈
Status Push(ShStack *S,SElemType e,int stackNumber)
{
    if(S->top1=1==S->top2)//共享栈满
        return ERROR;
    if(stackNumber==1)
        S->data[++S->top1]==e;
    else if(stackNumber==2)
        S->data[--S->top2]=e;
    return OK;
}

//出栈
Status Pop(ShStack *S,SElemType *e, int stackNumber)
{
    if(stackNumber==1){
        if(S->top1==-1)//栈1为空
            return ERROR;
        *e=S->data[S->top1--];
    }else if(stackNumber==2){
        if(S->top2==MAXSIZE)
            return ERROR;
        *e=S->data[S->top2++];
    }
    return OK;
}
