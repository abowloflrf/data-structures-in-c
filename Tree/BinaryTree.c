//
// Created by ruofeng on 2018/2/3.
//
#include <stdio.h>
#include <stdlib.h>

//二叉树节点的数据结构
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild; /* 左右孩子指針 */
}BiTNode,*BiTree;

//向二叉树添加节点的函数，返回一个指向节点的指针
BiTree newNode(int data){
    //新节点分配内存空间
    BiTree node=(BiTree)malloc(sizeof(BiTNode));
    //新节点的数据赋值
    node->data=data;
    //新节点的左右子节点都是默认为空
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}

int main(){

    //         tree
    //         ----
    //          9    <-- root
    //       /   \
    //     7     8
    //    /
    //   6

    BiTree root=newNode(9);
    root->rchild=newNode(8);
    root->lchild=newNode(7);
    root->lchild->lchild=newNode(6);

    return 0;
}