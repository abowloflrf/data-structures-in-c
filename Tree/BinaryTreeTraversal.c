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
//前序遍历
void pre_order_traversal(BiTree root) {
    // Do Something with root
    printf("%d ",root->data);
    if (root->lchild != NULL)
        pre_order_traversal(root->lchild);
    if (root->rchild != NULL)
        pre_order_traversal(root->rchild);
}
//中序遍历
void in_order_traversal(BiTree root) {
    if (root->lchild != NULL)
        in_order_traversal(root->lchild);
    // Do Something with root
    printf("%d ",root->data);
    if (root->rchild != NULL)
        in_order_traversal(root->rchild);
}
//后序遍历
void post_order_traversal(BiTree root) {
    if (root->lchild != NULL)
        post_order_traversal(root->lchild);
    if (root->rchild != NULL)
        post_order_traversal(root->rchild);
    // Do Something with root
    printf("%d ",root->data);
}

int main(){

    //                 tree
    //                 ----
    //                  1    <-- root
    //                /  \
    //              2     3
    //            /  \     \
    //          4     5     6
    //              /  \
    //            7     8

    BiTree root=newNode(1);
    root->rchild=newNode(3);
    root->lchild=newNode(2);
    root->rchild->rchild=newNode(6);
    root->lchild->lchild=newNode(4);
    root->lchild->rchild=newNode(5);
    root->lchild->rchild->rchild=newNode(8);
    root->lchild->rchild->lchild=newNode(7);

    printf("Pre-Oder Traversal: ");
    pre_order_traversal(root);
    printf("\nIn-Oder Traversal: ");
    in_order_traversal(root);
    printf("\nPost-Oder traversal: ");
    post_order_traversal(root);

    return 0;
}