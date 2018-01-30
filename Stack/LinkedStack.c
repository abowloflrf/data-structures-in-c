//
// Created by ruofeng on 2018/1/30.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack *next;
} Stack;

Stack *push(Stack *stack, int a) {
    //新建一个栈节点并分配内存空间
    Stack *line=(Stack*)malloc(sizeof(stack));
    //新建的栈节点数据为a
    line->data=a;
    //将新节点的下一个指向旧的栈顶
    line->next=stack;
    stack=line;
    return stack;
}

Stack *pop(Stack *stack){
    if(stack){
        stack=stack->next;
        return stack;
    }else{
        printf("Empty Stack\n");
    }
    return stack;
}

int main(){
    Stack *stack=NULL;
    stack=push(stack,1);
    stack=push(stack,2);
    stack=push(stack,32);
    stack=pop(stack);
    stack=pop(stack);
    return 0;
}