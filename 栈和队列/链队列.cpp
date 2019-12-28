//
// Created by 陈思贝 on 2019/12/18.
//

#include <iostream>

using namespace std;

typedef char DataType;
typedef struct qnode {
    DataType data;
    struct qnode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} LinkQueue;

// 初始化
void InitQueue(LinkQueue *queue) {
    queue->front = (QueueNode *) malloc(sizeof(QueueNode));
    queue->rear = queue->front;
    queue->rear->next = nullptr;
}

// 判断空
int QueueEmpty(LinkQueue *queue) {
    return queue->rear == queue->front;
}

//  入队列
void EnQueue(LinkQueue *queue, DataType x) {
    QueueNode *n = (QueueNode *) malloc(sizeof(QueueNode));
    n->data = x;
    n->next = nullptr;
    // queue->rear = queue->front ; queue->rear => (queue *).rear ; queue->rear = queue->front ; 指向的是同一块内存地址(同一个变量),
    // 在 InitQueue 方法里面 queue->rear = queue->front;这里 queue->rear->next = n 间接表示 queue->front->next = n
    queue->rear->next = n;
    // queue->rear = n 指向队列末尾元素的内存地址;此时 queue->front 指向的内存地址不变
    // queue->front->next = n ; queue->rear = n;
    // 当下次入队列的时候 queue->rear->next = n, queue->front->next->next = n
    queue->rear = n;
}

// 出队列
DataType DeQueue(LinkQueue *queue) {
    if (QueueEmpty(queue)) {
        printf("queue empty");
        exit(0);
    }
    // queue->front 为头指针
    QueueNode *n = queue->front->next;
    DataType data = n->data;
    // queue->front->next 头指针的下个元素指向出队列的元素的下个元素
    queue->front->next = n->next;
    // 如果取出的元素是队列的最后一个元素,要把队尾指针指向对头指针
    if (n == queue->rear) {
        queue->rear = queue->front;
        queue->front->next = nullptr;
    }
    free(n);
    return data;
}

// 取出对头元素
DataType GetFront(LinkQueue *queue) {
    if (QueueEmpty(queue)) {
        printf("queue empty");
        exit(0);
    }
    // 返回原队头元素值 queue->front 是头节点
    return queue->front->next->data;
}

int main() {
    LinkQueue linkQueue;
    InitQueue(&linkQueue);
    EnQueue(&linkQueue, 'a');
    EnQueue(&linkQueue, 'b');
    EnQueue(&linkQueue, 'c');

    cout << DeQueue(&linkQueue) << endl;
    cout << DeQueue(&linkQueue) << endl;
    cout << DeQueue(&linkQueue) << endl;

    EnQueue(&linkQueue, 'd');
    cout << DeQueue(&linkQueue) << endl;
}
