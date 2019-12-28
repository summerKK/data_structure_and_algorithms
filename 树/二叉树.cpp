#include <iostream>

using namespace std;

typedef char DATA_TYPE;
// 二叉链表的结构定义
typedef struct BiTNode {
    DATA_TYPE data;
    struct BiTNode *lChildren, *rChildren;
} BiTNode, *BiTree;

// 前序建立一个二叉树
void CreateBiTree(BiTree *T) {
    char ch;
    // 读入字符
    scanf("%c", &ch);
    // `#`代表空子树
    if (ch == '#')
        *T = nullptr;
    else {
        *T = (BiTree) malloc(sizeof(BiTNode));
        // 给T赋值
        (*T)->data = ch;
        // 给左子树赋值
        CreateBiTree(&(*T)->lChildren);
        // 给右子树赋值
        CreateBiTree(&(*T)->rChildren);
    }
}

// 前序遍历
void PreOrderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lChildren);
    PreOrderTraverse(T->rChildren);
}

// 中序遍历
void InOrderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    PreOrderTraverse(T->lChildren);
    printf("%c", T->data);
    PreOrderTraverse(T->rChildren);
}

int main() {
    BiTree tree = (BiTree) malloc(sizeof(BiTNode));

    // ab#d##c## (输入的节点要是一个满二叉树)
    // 前序简历二叉树
    CreateBiTree(&tree);
    cout << "二叉树前序输出" << endl;
    PreOrderTraverse(tree);
    cout << endl;
    cout << "二叉树前序输出" << endl;

    cout << "二叉树中序输出" << endl;
    InOrderTraverse(tree);
    cout << endl;
    cout << "二叉树中序输出" << endl;

}