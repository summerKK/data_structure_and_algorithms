#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//
// Created by 陈思贝 on 2019/12/2.
//
typedef int DataType;
typedef struct node {
    DataType data;
    struct node *next;
} ListNode;

typedef ListNode *LinkList;

LinkList createLinkList() {
    LinkList head = (ListNode *) malloc(sizeof(ListNode));
    head->data = 0;
    ListNode *p, *r;
    // 尾指针指向头节点
    r = head;
    DataType ch;
    while ((ch = getchar()) != '\n') {
        p = (ListNode *) malloc(sizeof(ListNode));
        p->data = ch;
        r->next = p;
        // r 始终指向最后一个节点
        r = p;
    }
    // 循环指针,尾部指向头部
    r->next = head;

    return head;
}

/**
 *  p57 例2.7
 * @param list
 * @param x
 */
void InsertList(LinkList list, DataType x) {
    // s 要插入的节点,q 指向当前节点,p 指向插入位置的前趋节点
    ListNode *s, *p, *q;
    s = (ListNode *) malloc(sizeof(ListNode));
    s->data = x;
    p = list;
    // q 指向开始节点
    q = p->next;
    // p -> s -> q
    while (q->data > x && q != list) {
        // p 指向 q 的前趋节点
        p = p->next;
        // q 指向当前节点
        q = p->next;
    }
    p->next = s;
    s->next = q;
}

void printLink(LinkList list) {
    ListNode *p;
    p = list->next;
    // 当 head == 当前节点的时候.循环链表遍历结束
    while (p != list) {
        if (p->data > 0) {
            cout << (char) p->data;
        }
        p = p->next;
    }
    cout << endl;
}

int main() {
//    LinkList list = createLinkList();
//    printLink(list);

    // p57 例2.7
    LinkList list = createLinkList();
    InsertList(list, (char) '5');
    printLink(list);
}

