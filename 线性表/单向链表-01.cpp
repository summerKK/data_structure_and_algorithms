//
// Created by 陈思贝 on 2019/12/19.
//

#include <iostream>

using namespace std;

typedef char DataType;
typedef struct node {
    DataType data;
    node *next;
} Node;

typedef Node *LinkList;

// 头插发
void createLinkHead(LinkList *L) {
    LinkList p;
    char ch;
    while ((ch = getchar()) != '\n') {
        p = (Node *) malloc(sizeof(Node));
        p->data = ch;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

// 尾插发
void createLinkTail(LinkList *L) {
    LinkList p, r;
    char ch;
    r = *L;
    while ((ch = getchar()) != '\n') {
        p = (Node *) malloc(sizeof(Node));
        p->data = ch;
        r->next = p;
        r = p;
    }
    r->next = nullptr;
}

void getNode(LinkList linkList, int i, DataType *x) {
    Node *p;
    int j = 0;
    p = linkList->next;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p) {
        printf("not found");
        exit(0);
    }
    *x = p->data;
}

void insertNode(LinkList linkList, int i, DataType x) {
    Node *p;
    int j = 1;
    p = linkList;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p) {
        printf("overflow");
        exit(0);
    }
    Node *s = (Node *) malloc(sizeof(Node));
    s->data = x;
    s->next = p->next;
    p->next = s;
}

// 释放链表
void clearLink(LinkList linkList) {
    LinkList p, q;
    p = linkList->next;
    while (p) {
        // 赋值给一个中间变量
        q = p->next;
        // 释放节点
        free(p);
        // 继续循环链表
        p = q;
    }
    linkList->next = nullptr;
}

void printLinkList(LinkList linkList) {
    Node *p = linkList->next;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}

int main() {
    Node *linkList = (Node *) malloc(sizeof(Node));
//    createLinkHead(&linkList);
    createLinkTail(&linkList);
//    clearLink(linkList);

    printLinkList(linkList);

    char *c = (char *) malloc(sizeof(char));
    getNode(linkList, 2, c);
    cout << "get node:" << c << endl;

    cout << "插入新节点" << endl;
    insertNode(linkList, 2, 'a');
    printLinkList(linkList);
}

