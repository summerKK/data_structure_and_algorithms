//
// Created by 陈思贝 on 2019/12/17.
//

#include <printf.h>
#include <cstdlib>
#include <iostream>

using namespace std;

#define QueueSize 11
typedef char DataType;
typedef struct {
    DataType data[QueueSize];
    int front, rear;
} CirQueue;

// 初始化队列
void InitQueue(CirQueue &queue) {
    queue.front = 0;
    queue.rear = 0;
}

// 队列空
int QueueEmpty(CirQueue &queue) {
    return queue.front == queue.rear;
}

// 队列满
int QueueFull(CirQueue &queue) {
    // queue.rear + 1 如果等于 queue.front(如果队列满,此时queue.front = 0)
    return (queue.rear + 1) % QueueSize == queue.front;
}

// 入队列
int EnQueue(CirQueue &queue, DataType x) {
    if (QueueFull(queue)) {
        printf("queue overflow");
        exit(0);
    }
    queue.data[queue.rear] = x;
    queue.rear = (queue.rear + 1) % QueueSize;
}

// 获取头元素
DataType GetFront(CirQueue &queue) {
    if (QueueEmpty(queue)) {
        printf("queue empty");
        exit(0);
    }
    return queue.data[queue.front];
}

// 出队列
DataType DeQueue(CirQueue &queue) {
    if (QueueEmpty(queue)) {
        printf("queue empty");
        exit(0);
    }
    DataType x = queue.data[queue.front];
    queue.front = (queue.front + 1) % QueueSize;
    return x;
}

int main() {
    CirQueue queue;
    InitQueue(queue);
    EnQueue(queue, 'd');
    EnQueue(queue, 'e');
    EnQueue(queue, 'b');
    EnQueue(queue, 'g');
    EnQueue(queue, 'h');
    cout << DeQueue(queue) << endl;
    cout << DeQueue(queue) << endl;
    EnQueue(queue, 'i');
    EnQueue(queue, 'j');
    EnQueue(queue, 'k');
    EnQueue(queue, 'l');
    EnQueue(queue, 'm');
    cout << DeQueue(queue) << endl;

    EnQueue(queue, 'n');
    EnQueue(queue, 'o');
    EnQueue(queue, 'p');
    EnQueue(queue, 'q');
    EnQueue(queue, 'r');
}

