//
// Created by 陈思贝 on 2019/12/22.
//

#include <iostream>

using namespace std;

#define MAXSIZE 100
typedef int DATA_TYPE;
typedef struct {
    DATA_TYPE data[MAXSIZE];
    int top1;
    int top2;
} StackList;

void InitStackList(StackList &s) {
    s.top1 = -1;
    s.top2 = MAXSIZE;
}

void push(StackList &s, DATA_TYPE x, int stackNum) {
    if (s.top1 + 1 == s.top2) {
        printf("stack overflow");
        exit(0);
    }
    if (stackNum == 1) {
        s.data[++s.top1] = x;
    } else {
        s.data[--s.top2] = x;
    }
}

void pop(StackList &s, DATA_TYPE *x, int stackNum) {
    if (stackNum == 1) {
        if (s.top1 == -1) {
            printf("stack empty");
            exit(0);
        }
        *x = s.data[s.top1--];
    }

    if (stackNum == 2) {
        if (s.top2 == MAXSIZE) {
            printf("stack empty");
            exit(0);
        }
        *x = s.data[s.top2++];
    }

}

int main() {
    StackList stackList;
    InitStackList(stackList);
    int i;
    push(stackList, 1, 1);
    push(stackList, 2, 1);
    push(stackList, 3, 1);
    pop(stackList, &i, 1);
    cout << i << endl;
    pop(stackList, &i, 1);
    cout << i << endl;
    pop(stackList, &i, 1);
    cout << i << endl;

    int j;
    push(stackList, 100, 2);
    push(stackList, 99, 2);
    push(stackList, 98, 2);
    pop(stackList, &j, 2);
    cout << j << endl;
    pop(stackList, &j, 2);
    cout << j << endl;
    pop(stackList, &j, 2);
    cout << j << endl;
}