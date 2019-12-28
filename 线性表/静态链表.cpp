//
// Created by 陈思贝 on 2019/12/19.
//

#include <iostream>

using namespace std;

const int MAXSIZE = 100;
typedef int DATA_TYPE;
typedef struct {
    DATA_TYPE data;
    int cur;
} StaticLinkList[MAXSIZE];

int Malloc_SLL(StaticLinkList staticLinkList) {
    int i = staticLinkList[0].cur;
    if (staticLinkList[0].cur) {
        // 当前i是要返回的游标,所以staticLinkList[0].cur记录下个游标的位置
        staticLinkList[0].cur = staticLinkList[i].cur;
    }
    return i;
}

int ListLength(StaticLinkList staticLinkList) {
    int i, j;
    i = staticLinkList[MAXSIZE - 1].cur;
    j = 0;
    while (i) {
        i = staticLinkList[i].cur;
        j++;
    }

    return j;
}

void Free_SLL(StaticLinkList staticLinkList, int k) {
    // 删除的节点的游标指向 当前链表的空闲位置
    staticLinkList[k].cur = staticLinkList[0].cur;
    // 把当前链表的游标指向k的下标
    staticLinkList[0].cur = k;
}

void InsertPosLink(StaticLinkList staticLinkList, int i, DATA_TYPE x) {
    int j, l;
    l = MAXSIZE - 1;
    if (i < 1 || i > ListLength(staticLinkList) + 1) {
        printf("位置错误");
        exit(0);
    }
    j = Malloc_SLL(staticLinkList);
    if (j) {
        // 找到第 i - 1 的位置
        for (int k = 1; k <= i - 1; ++k) {
            // l指向最后一个元素
            // l 第一次循环的值是 MAXSIZE - 1,第一次循环通过数组最后一个游标确定循环的开始位置
            l = staticLinkList[l].cur;
        }
        staticLinkList[j].data = x;
        staticLinkList[j].cur = staticLinkList[l].cur;
        staticLinkList[l].cur = j;
    }
}

void DeleteList(StaticLinkList staticLinkList, int i) {
    int j, k;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(staticLinkList) + 1) {
        printf("位置错误");
        exit(0);
    }
    // 找到第 i - 1的节点
    for (int l = 1; l <= i - 1; ++l) {
        k = staticLinkList[k].cur;
    }
    // 删除节点的游标
    j = staticLinkList[k].cur;
    // 把k的游标指向 j的游标(j的下个元素的下标)
    staticLinkList[k].cur = staticLinkList[j].cur;
    Free_SLL(staticLinkList, j);
}

void InitList(StaticLinkList staticLinkList) {
    for (int i = 0; i < MAXSIZE; ++i) {
        // 每个元素的游标指向他相邻的元素
        staticLinkList[i].cur = i + 1;
    }
    //  数组最后一个元素记录第一个被插入元素的下标,相当于头节点
    staticLinkList[MAXSIZE - 1].cur = 0;
}

void printLinkList(StaticLinkList staticLinkList) {
    int p = staticLinkList[MAXSIZE - 1].cur;
    while (staticLinkList[p].cur != 0) {
        cout << staticLinkList[p].data << endl;
        p = staticLinkList[p].cur;
    }
}

int main() {
    StaticLinkList staticLinkList;
    InitList(staticLinkList);
    int i;
    for (i = 1; i < 10; ++i) {
        InsertPosLink(staticLinkList, i, i);
    }

    InsertPosLink(staticLinkList, 2, 100);
    InsertPosLink(staticLinkList, 2, 100);

    DeleteList(staticLinkList, 2);

    printLinkList(staticLinkList);
}



