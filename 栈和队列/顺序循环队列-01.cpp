//
// Created by 陈思贝 on 2019/12/23.
//

#include <iostream>

using namespace std;

#define MAX_SIZE 5
typedef int DATA_TYPE;

typedef struct {
    DATA_TYPE data[MAX_SIZE];
    int front;
    int rear;
} SeqList;

void InitSeqList(SeqList *list) {
    list->front = 0;
    list->rear = 0;
}

int QueueLen(SeqList list) {
    return (list.rear - list.front + MAX_SIZE) % MAX_SIZE;
}

void EnQueue(SeqList *list, DATA_TYPE x) {
    if ((list->rear + 1) % MAX_SIZE == list->front) {
        printf("stack overflow");
        exit(0);
    }
    list->data[list->rear] = x;
    list->rear = (list->rear + 1) % MAX_SIZE;
}

void DeQueue(SeqList *list, DATA_TYPE *x) {
    if (list->rear == list->front) {
        printf("stack empty");
        exit(0);
    }
    *x = list->data[list->front];
    list->front = (list->front + 1) % MAX_SIZE;
}

int main() {
    SeqList list;
    int i;
    InitSeqList(&list);
    EnQueue(&list, 1);
    EnQueue(&list, 2);
    EnQueue(&list, 3);
    EnQueue(&list, 4);
    DeQueue(&list, &i);
    DeQueue(&list, &i);
    DeQueue(&list, &i);
    EnQueue(&list, 5);
    EnQueue(&list, 6);

    DeQueue(&list, &i);
    cout << i << endl;
    DeQueue(&list, &i);
    cout << i << endl;
    DeQueue(&list, &i);
    cout << i << endl;
    DeQueue(&list, &i);
    cout << i << endl;
    DeQueue(&list, &i);
    cout << i << endl;
}