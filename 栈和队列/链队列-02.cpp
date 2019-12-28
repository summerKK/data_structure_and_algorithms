//
// Created by 陈思贝 on 2019/12/23.
//
#include <iostream>

using namespace std;

typedef int DATA_TYPE;

typedef struct Node {
    DATA_TYPE data;
    Node *next;
} Link, *LinkPtr;

typedef struct {
    LinkPtr front, rear;
} SeqList;

SeqList *InitList() {
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    list->front = (LinkPtr) malloc(sizeof(Link));
    list->front->next = nullptr;
    list->rear = list->front;

    return list;
}

void EnQueue(SeqList *list, DATA_TYPE x) {
    LinkPtr p = (LinkPtr) malloc(sizeof(Link));
    p->data = x;
    p->next = nullptr;
    list->rear->next = p;
    list->rear = p;
}

void DeQueue(SeqList *list, DATA_TYPE *x) {
    if (list->front == list->rear) {
        printf("queue empty");
        exit(0);
    }
    LinkPtr p = list->front->next;
    *x = p->data;
    list->front->next = p->next;

    if (list->rear == p) {
        list->rear = list->front;
    }
    free(p);
}

int main() {
    int x;
    SeqList *list = InitList();
    EnQueue(list, 1);
    EnQueue(list, 2);
    EnQueue(list, 3);

    DeQueue(list, &x);
    cout << x << endl;
    DeQueue(list, &x);
    cout << x << endl;
    DeQueue(list, &x);
    cout << x << endl;
    DeQueue(list, &x);
    cout << x << endl;
}

