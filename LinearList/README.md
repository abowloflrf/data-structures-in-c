# 线性表
## 抽象数据类型
- `InitList(*L)`:初始化操作,建立一个空的线性表L
- `ListEmpty(L)`:判断线性表L是否为空
- `ClearList(*L)`:将线性表清空
- `GetElem(L,i,*e)`:将线性表L中位置为i的数赋值给e
- `LocateELem(L,e)`:在线性表L中查找数值为e的元素,若找到则返回元素的序号,否则返回0
- `ListInsert(*L,i,e)`:在线性表L中的i位置插入数据e
- `ListDelete(*L,i,e)`:删除线性表L中i位置的元素,并返回该元素给e
- `ListLength(L)`:返回线性表L的长度
### 顺序表
### 单向链表
### 静态链表
### 循环链表
### 双向链表