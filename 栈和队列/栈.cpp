//
// Created by 陈思贝 on 2019/12/6.
//
#include <iostream>

using namespace std;

#define StackSize 100
typedef char DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

void InitStack(SeqStack *s) {
    s->top = -1;
}

int StackEmpty(SeqStack *s) {
    return s->top == -1;
}

int StackFull(SeqStack *s) {
    return s->top == StackSize - 1;
}

void push(SeqStack *s, DataType x) {
    if (StackFull(s)) {
        printf("stack overflow");
    } else {
        s->top += 1;
        s->data[s->top] = x;
    }
}

DataType Pop(SeqStack *s) {
    if (StackEmpty(s)) {
        printf("stack underflow");
        exit(0);
    } else {
        return s->data[s->top--];
    }
}

DataType GetTop(SeqStack *s) {
    if (StackEmpty(s)) {
        printf("stack empty");
        exit(0);
    } else {
        return s->data[s->top];
    }
}

int symmetry(char str[]) {
    SeqStack s;
    int j, k, i = 0;
    InitStack(&s);
    // 计算字符串长度
    while (str[i] != '\0') i++;
    for (int j = 0; j < i / 2; ++j) {
        push(&s, str[j]);
    }
    // 后一般字符在字符串的起始位置
    k = (i + 1) / 2;
    for (int l = k; l < i; ++l) {
        if (str[l] != Pop(&s)) {
            return 0;
        }
    }
    return 1;
}

void conversion(int N, int d) {
    SeqStack s;
    InitStack(&s);
    while (N) {
        push(&s, N % d);
        N = N / d;
    }

    while (!StackEmpty(&s)) {
        DataType i = Pop(&s);
        printf("%d", i);
    }
}

int main() {
//    SeqStack *s = (SeqStack *) malloc(sizeof(SeqStack));
//    s->top = 10;
//    InitStack(s);
//    push(s, 'h');
//    push(s, 'e');
//    push(s, 'l');
//    push(s, 'l');
//    push(s, 'o');
//    for (int i = 0; i < 5; ++i) {
//        cout << Pop(s) << endl;
//    }

    // p69 3.2.2 字符串回文判断
    char s[] = "abccba";
    if (symmetry(s) == 1) {
        cout << "字符串对称" << endl;
    } else {
        cout << "字符串不对称" << endl;
    }

    // p70 进制转换
    conversion(8000, 2);
}
