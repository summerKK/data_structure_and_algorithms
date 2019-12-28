#include <iostream>

using namespace std;

//
// Created by 陈思贝 on 2019/12/10.
//
typedef char DatType;
typedef struct stacknode {
    DatType data;
    struct stacknode *next;
} StackNode;

typedef StackNode *LinkStack;

int StackEmpty(LinkStack top) {
    return top == nullptr;
}

// &top :top是一个指针变量,最后 top = p 如果传递的是 LinkStack top 将不能修改外部top的值
LinkStack Push(LinkStack &top, DatType x) {
    StackNode *p;
    p = (StackNode *) malloc(sizeof(StackNode));
    p->data = x;
    p->next = top;
    top = p;
    return top;
}

LinkStack Pop(LinkStack &top, DatType *x) {
    StackNode *p = top;
    if (StackEmpty(top)) {
        printf("stack empty");
        exit(0);
    } else {
        *x = p->data;
        top = p->next;
        free(p);
        return top;
    }
}

DatType GetTop(LinkStack top) {
    if (StackEmpty(top)) {
        printf("statck empty");
        exit(0);
    } else {
        return top->data;
    }
}

int main() {
    LinkStack s = (StackNode *) malloc(sizeof(StackNode));
    Push(s, 'a');
    Push(s, 'b');
    char *c = (char *) malloc(sizeof(char));
    Pop(s, c);
    cout << c << endl;
    cout << GetTop(s) << endl;
}

