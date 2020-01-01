//
// Created by 陈思贝 on 2020/1/1.
//
#include <iostream>

using namespace std;

#define MAX_SIZE 100
typedef char DATA_TYPE;

// 定义栈的数据结构
typedef struct StackNode {
    DATA_TYPE data;
    struct StackNode *next;
} StackNode, *StackList;

// 定义队列的数据结构
typedef struct CirQueue {
    int front, rear;
    DATA_TYPE data[MAX_SIZE];
} CirQueue;

typedef enum {
    Success, Error
} Flag;

StackList InitStack() {
    // 定义一个头指针,方便操作
    StackList head = (StackList) malloc(sizeof(StackNode));
    return head;
}

bool StackEmpty(StackList list) {
    return list == nullptr;
}

Flag Push(StackList list, DATA_TYPE x) {
    StackNode *node = (StackList) malloc(sizeof(StackNode));
    node->data = x;
    // head -> (第一个节点)
    // head -> (当前节点) -> (第一个节点)
    // 把头指针的下一个节点(链表的第一个节点)赋值给next
    node->next = list->next;
    list->next = node;
    return Success;
}

DATA_TYPE Pop(StackList list) {
    if (StackEmpty(list)) {
        return Error;
    }
    // list是头节点,list->next是第一个节点
    StackNode *node = list->next;
    DATA_TYPE x = node->data;
    // head -> node1 -> node2
    // head -> node2(node1->next)
    list->next = list->next->next;
    free(node);
    return x;
}

DATA_TYPE GetStackTop(StackList list) {
    if (StackEmpty(list)) {
        return Error;
    }
    return list->next->data;
}

void InitCirQueue(CirQueue *Q) {
    Q->front = Q->rear = 0;
}

bool CirQueueEmpty(CirQueue *Q) {
    return Q->front == Q->rear;
}

bool CirQueueFull(CirQueue *Q) {
    return (Q->rear + 1) % MAX_SIZE == Q->front;
}

Flag EnCirQueue(CirQueue *Q, DATA_TYPE x) {
    if (CirQueueFull(Q)) {
        printf("queue overflow");
        return Error;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAX_SIZE;

    return Success;
}

DATA_TYPE DeCirQueue(CirQueue *Q) {
    DATA_TYPE x;
    if (CirQueueEmpty(Q)) {
        printf("queue empty");
        return Error;
    }
    x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;

    return x;
}

DATA_TYPE GetTopCirQueue(CirQueue *Q) {
    if (CirQueueEmpty(Q)) {
        printf("queue empty");
        exit(0);
    }
    return Q->data[Q->front];
}

// 返回运算符运算等级
int Priority(DATA_TYPE data) {
    switch (data) {
        case '(':
        case '#':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }

    return -1;
}

// 中缀表达式转后缀表达式
void CTPostExp(CirQueue *Q) {
    // 初始化栈
    StackList stackList = InitStack();
    DATA_TYPE s, t;
    // 添加`#`表示栈的结束符
    Push(stackList, '#');
    do {
        s = getchar();
        switch (s) {
            case ' ':
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                // 数字进队列
                EnCirQueue(Q, s);
                break;
            case '(':
                // 如果遇到 '(' 就加入栈
                Push(stackList, s);
                break;
            case ')':
            case '#':
                do {
                    // 当遇到 ')' 栈里面肯定已经有 '(' 了,把 括号内的数字输出
                    t = Pop(stackList);
                    // 过滤 '(' 和 '#' 结束符
                    if (t != '(' && t != '#') {
                        // 把运算符入队列
                        EnCirQueue(Q, t);
                    }
                } while (t != '(' && t != '#');
                break;
            case '+':
            case '-':
            case '/':
            case '*':
                // 当前的运算符号优先级小于栈区的优先级.把栈区的符号放入队列中
                while (Priority(s) <= Priority(GetStackTop(stackList))) {
                    t = Pop(stackList);
                    EnCirQueue(Q, t);
                }
                Push(stackList, s);
        }
    } while (s != '#');
}

// 后缀表达式计算
int CPostExp(CirQueue Q) {
    StackList list = InitStack();
    DATA_TYPE ch;
    int x, y;
    while (!CirQueueEmpty(&Q)) {
        ch = DeCirQueue(&Q);
        if (ch >= '0' && ch <= '9') {
            // ch - '0' 转换为数字
            Push(list, ch - '0');
        } else {
            y = Pop(list);
            x = Pop(list);
            switch (ch) {
                case '*':
                    Push(list, y * x);
                    break;
                case '/':
                    Push(list, x / y);
                    break;
                case '-':
                    Push(list, x - y);
                    break;
                case '+':
                    Push(list, x + y);
                    break;
            }
        }
    }
    return GetStackTop(list);
}

int main() {
    StackList head0 = InitStack();
    StackList head1 = InitStack();
    Push(head0, 'a');
    Push(head0, 'b');
    Push(head0, 'c');
    Push(head0, 'd');

    cout << Pop(head0) << endl;

    CirQueue queue;
    InitCirQueue(&queue);
    EnCirQueue(&queue, 'a');
    EnCirQueue(&queue, 'b');

    cout << endl;
    cout << DeCirQueue(&queue) << endl;
    cout << DeCirQueue(&queue) << endl;

    // 中缀表达式转后缀表达式
    CirQueue queue1;
    InitCirQueue(&queue1);

    DATA_TYPE t;
    // 9-(2+4*7)/5+3#
    CTPostExp(&queue1);
    int result = CPostExp(queue1);
    cout << result << endl;
}



