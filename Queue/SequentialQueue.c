//
// Created by ruofeng on 2018/1/30.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue{
    int data[100];
    int front;
    int rear;
}Queue;
//初始化队列
Queue *inintQueue(Queue *queue){
    Queue *newQueue=(Queue*)malloc(sizeof(queue));
    newQueue->front=0;
    newQueue->rear=0;
    queue=newQueue;
    return queue;
}
//入队
Queue *intoQueue(Queue *queue,int a){
    if (queue->rear>=99){
        printf("Queue Full!\n");
        return queue;
    }else{
        queue->data[queue->rear+1]=a;
        queue->rear++;
        return queue;
    }
}
//出队
Queue *leaveQueue(Queue *queue){
    if (queue->rear==queue->front){
        printf("Queue Empty!\n");
        return queue;
    } else{
        queue->front++;
        //或者不移动指针而将所有元素整体向前移动，代价太大，因此需要使用链表储存
        return queue;
    }
}

int main(){
    Queue *queue=NULL;
    queue=inintQueue(queue);
    queue=intoQueue(queue,3);
    queue=intoQueue(queue,5);
    queue=intoQueue(queue,7);
    queue=intoQueue(queue,123);
    queue=leaveQueue(queue);
    queue=leaveQueue(queue);
    queue=leaveQueue(queue);

}
