//
// Created by 陈思贝 on 2019/12/28.
//
#include <iostream>

using namespace std;

typedef char DATA_TYPE;

typedef enum {
    Link, Thread
} PointerTag;

// 二叉树线索存储节点结构
typedef struct BiTNode {
    DATA_TYPE data;
    struct BiTNode *lChild, *rChild;
    PointerTag lflag;
    PointerTag rflag;
} BiTNode, *BiTree;

BiTree pre;
// 中序遍历第一个节点
BiTree inorderFirst;
// 中序遍历最后一个节点
BiTree inorderLast;

void CreateBiTree(BiTree *T) {
    char data;
    scanf("%c", &data);
    if (data == '#') {
        *T = nullptr;
    } else {
        *T = (BiTree) malloc(sizeof(BiTNode));
        (*T)->data = data;
        (*T)->lflag = Link;
        (*T)->rflag = Link;
        CreateBiTree(&(*T)->lChild);
        CreateBiTree(&(*T)->rChild);
    }
}

// 中序遍历进行中序线索化
void InThreading(BiTree T) {
    if (T == nullptr) {
        return;
    }
    // 查找当前节点左节点
    InThreading(T->lChild);
    if (inorderFirst == nullptr) {
        inorderFirst = T;
    }
    inorderLast = T;
    // 中序遍历最开始查找的节点是最做叶子节点,所在判断 lChild,rChild的程序要在 InThreading(T->lChild);和InThreading(T->rChild);之间
    if (T->lChild == nullptr) {
        // 当程序第一次走到这的时候,T表示的是最左叶子节点,它的前趋节点为null
        T->lflag = Thread;
        T->lChild = pre;
    }
    // !!注意 这里判断的是前趋节点 pre,pre是上一层的节点.
    // 判断上一层的右子节点是否为null,如果为null把rChild指向当前节点(前趋节点)
    if (pre != nullptr && pre->rChild == nullptr) {
        pre->rflag = Thread;
        pre->rChild = T;
    }
    // 把当前节点赋值给 pre,以供下次使用
    pre = T;
    InThreading(T->rChild);
}

void InorderTraverse_Thr(BiTree T) {
    // T是头节点
    BiTree P = T->lChild;
    while (T != P) {
        // while循环找出左叶子节点
        while (P->lflag == Link) {
            P = P->lChild;
        }
        // 输出数据
        cout << P->data;
        // 当 P->rflag == Thread的时候代码当前节点有后继节点
        while (P->rflag == Thread && P->rChild != T) {
            // 把T赋值给后继节点
            P = P->rChild;
            cout << P->data;
        }
        // 上面 while (P->rflag == Thread) 的结束条件为: while (P->rflag == Link),此时把T赋值给右子节点
        P = P->rChild;
    }
}

int main() {
    BiTree tree;
    CreateBiTree(&tree);

    cout << "中序遍历进行中序线索化" << endl;
    InThreading(tree);
    cout << "中序遍历进行中序线索化" << endl;

    cout << "中序遍历第一个节点:" << inorderFirst->data << endl;
    cout << "中序遍历最后一个节点:" << inorderLast->data << endl;

    // 添加头节点
    BiTree head = (BiTree) malloc(sizeof(BiTNode));
    // head的lflag指向第一个节点,rflag指向最后一个节点
    head->lflag = Link;
    head->rflag = Thread;
    head->rChild = inorderLast;
    head->lChild = tree;
    inorderFirst->lChild = head;
    inorderFirst->lflag = Thread;
    inorderLast->rChild = head;
    inorderLast->rflag = Thread;

    cout << "中序遍历二叉线索树" << endl;
    InorderTraverse_Thr(head);
    cout << endl;
    cout << "中序遍历二叉线索树" << endl;
}

