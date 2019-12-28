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

BiTree pre = (BiTree) malloc(sizeof(BiTNode));

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
    // 中序遍历最开始查找的节点是最做叶子节点,所在判断 lChild,rChild的程序要在 InThreading(T->lChild);和InThreading(T->rChild);之间
    if (T->lChild == nullptr) {
        // 当程序第一次走到这的时候,T表示的是最左叶子节点,它的前趋节点为null
        T->lflag = Thread;
        T->lChild = pre;
    }
    // !!注意 这里判断的是前趋节点 pre,pre是上一层的节点.
    // 判断上一层的右子节点是否为null,如果为null把rChild指向当前节点(前趋节点)
    if (pre->rChild == nullptr) {
        pre->lflag = Thread;
        pre->rChild = T;
    }
    // 把当前节点赋值给 pre,以供下次使用
    pre = T;
    InThreading(T->rChild);
}

void InorderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    if (T->lflag == Link) {
        InorderTraverse(T->lChild);
    }
    printf("%c", T->data);
    if (T->rflag == Link) {
        InorderTraverse(T->rChild);
    }
}

int main() {
    BiTree tree;
    CreateBiTree(&tree);

    cout << "中序遍历进行中序线索化" << endl;
    InThreading(tree);
    cout << "中序遍历进行中序线索化" << endl;

    cout << "二叉树中序输出" << endl;
    InorderTraverse(tree);
    cout << endl;
    cout << "二叉树中序输出" << endl;
}

