//
// Created by ruofeng on 2017/9/13.
//
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5
typedef int Status;

//栈的数据结构
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top;//栈顶位置，如此处定义MAXSIZE为5，则top为5时不能进行进栈操作
}SqStack;

//初始化一个空栈
Status InitStack(SqStack *S)
{
    S->top=-1;
    return OK;
}

//判断栈空
Status StackEmpty(SqStack S)
{
    if(S.top==-1)
        return TRUE;
    else
        return FALSE;
}

//打印栈的内容
void PrintStack(SqStack S)
{
    if(StackEmpty(S))
        printf("Empty Stack!\n");
    for (int i = 0; i <= S.top; ++i) {
        printf("%d\n",S.data[i]);
    }
}


//进栈
Status Push(SqStack *S, SElemType e)
{
    if(S->top==MAXSIZE-1){//栈满
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}

//出栈
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top==-1) {//栈空
        return ERROR;
    }
    *e=S->data[S->top];
    S->top--;
    return OK;
}

int main()
{
    SqStack stack;
    InitStack(&stack);
    Push(&stack,123);
    Push(&stack,234);
    Push(&stack,678);
    PrintStack(stack);

    int pop_var;
    Pop(&stack,&pop_var);
    PrintStack(stack);
    return 0;
}
