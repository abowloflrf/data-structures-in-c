//
// Created by ruofeng on 2018/1/30.
//
#include <stdio.h>
#include <stdlib.h>
//链式队列节点的数据结构
typedef struct QueueNode{
    int data;
    struct QueueNode *next;
}QueueNode;
//链队列数据结构
typedef struct{
    QueueNode *front;
    QueueNode *rear;
}LinkQueue;
//初始化链式队列
LinkQueue *initQueue(){
    LinkQueue *queue=(LinkQueue*)malloc(sizeof(LinkQueue));
    queue->front=queue->rear=(QueueNode*)malloc(sizeof(QueueNode));
    queue->front->next=NULL;
    return queue;
}
//进队列
LinkQueue *intoQueue(LinkQueue *queue,int a){
    QueueNode *newNode=(QueueNode*)malloc(sizeof(QueueNode));
    newNode->data=a;
    newNode->next=NULL;
    queue->rear->next=newNode;
    queue->rear=newNode;
    return queue;
}
LinkQueue *leaveQueue(LinkQueue *queue){
    if (queue->rear==queue->front){
        printf("Empty Queue!\n");
        return queue;
    }else{
        //声明一个节点node
        QueueNode *node;
        //使此节点指向队列的第一个元素
        node=queue->front->next;
        //让原队列的头节点指向node节点的下一个元素，即指向了队列的第二个元素
        queue->front->next=node->next;
        //若删除节点后node指向的是queue的尾节点，则表示队列空
        if(queue->rear==node)
            queue->front=queue->rear;
        return queue;
    }
}
int main(){
    LinkQueue *queue=initQueue();
    queue=intoQueue(queue,12);
    queue=intoQueue(queue,23);
    queue=intoQueue(queue,54);
    queue=intoQueue(queue,1);
    queue=leaveQueue(queue);
    queue=leaveQueue(queue);
    return 0;
}