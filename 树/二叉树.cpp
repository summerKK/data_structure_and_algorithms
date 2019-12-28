#include <iostream>

using namespace std;

typedef char DATA_TYPE;
// 二叉链表的结构定义
typedef struct BiTNode {
    DATA_TYPE data;
    struct BiTNode *lChild, *rChild;
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
        CreateBiTree(&(*T)->lChild);
        // 给右子树赋值
        CreateBiTree(&(*T)->rChild);
    }
}

// 前序遍历
void PreorderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    printf("%c", T->data);
    PreorderTraverse(T->lChild);
    PreorderTraverse(T->rChild);
}

// 中序遍历
void InorderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    InorderTraverse(T->lChild);
    printf("%c", T->data);
    InorderTraverse(T->rChild);
}

// 后序遍历
void PostorderTraverse(BiTree T) {
    if (T == nullptr) {
        return;
    }
    PostorderTraverse(T->lChild);
    PostorderTraverse(T->rChild);
    printf("%c", T->data);
}

int main() {
    BiTree tree = (BiTree) malloc(sizeof(BiTNode));

    // ab#d##c## (输入的节点要是一个满二叉树)
    // 前序简历二叉树
    CreateBiTree(&tree);
    cout << "二叉树前序输出" << endl;
    PreorderTraverse(tree);
    cout << endl;
    cout << "二叉树前序输出" << endl;

    cout << "二叉树中序输出" << endl;
    InorderTraverse(tree);
    cout << endl;
    cout << "二叉树中序输出" << endl;

    cout << "二叉树后序输出" << endl;
    PostorderTraverse(tree);
    cout << endl;
    cout << "二叉树后序输出" << endl;

}