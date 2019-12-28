//
// Created by 陈思贝 on 2019/12/22.
//

#include <iostream>

using namespace std;

typedef int DATA_TYPE;
typedef struct Node {
    DATA_TYPE data;
    Node *next;
} Node, *LinkStackList;

typedef struct StackLinkList {
    LinkStackList top;
    int count;
} StackLinkList;


void Push(StackLinkList *s, DATA_TYPE x) {
    LinkStackList p = (LinkStackList) malloc(sizeof(Node));
    p->data = x;
    p->next = s->top;
    s->top = p;
    ++s->count;
}

DATA_TYPE Pop(StackLinkList *s) {
    if (s->count == 0) {
        printf("stack empty");
        exit(0);
    }
    LinkStackList p = s->top;
    DATA_TYPE data = s->top->data;
    s->top = s->top->next;
    free(p);
    --s->count;

    return data;
}

int main() {
    StackLinkList list = {.count=0};
    Push(&list, 1);
    Push(&list, 2);
    Push(&list, 3);

    cout << Pop(&list) << endl;
    cout << Pop(&list) << endl;
    cout << Pop(&list) << endl;
    cout << Pop(&list) << endl;
}
