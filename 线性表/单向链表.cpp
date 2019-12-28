//
// Created by 陈思贝 on 2019/12/1.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef int DataType;

typedef struct node {
    // 节点数据域
    DataType data;
    // 节点指针域
    struct node *next;
} ListNode;

typedef ListNode *LinkList;

// 头插入法建表
LinkList createListF() {
    // 定义一个指向节点的指针变量
    LinkList head;
    // 定义单向链表的头指针
    ListNode *p;
    char ch;
    head = nullptr;
    ch = getchar();
    while (ch != '\n') {
        p = (ListNode *) malloc(sizeof(ListNode));
        p->data = ch;
        p->next = head;
        head = p;
        ch = getchar();
    }
    return head;
}

// 尾插入法链表
LinkList createListR() {
    LinkList head, rear;
    ListNode *p;
    head = rear = nullptr;
    char ch;
    ch = getchar();
    while (ch != '\n') {
        p = (ListNode *) malloc(sizeof(ListNode));
        p->data = ch;
        p->next = rear;
        if (head == nullptr) head = p;
        rear = p;
        ch = getchar();
    }

    if (rear != nullptr) rear->next = nullptr;
    return head;
}

// 尾插入法链表优化版
LinkList createListR1() {
    // 申请头节点,head的data指为null,next指向下一个节点
    LinkList head = (ListNode *) malloc(sizeof(ListNode));
    head->data = 0;
    ListNode *p, *r;
    DataType ch;
    // 尾指针初始指向头节点
    r = head;
    while ((ch = getchar()) != '\n') {
        p = (ListNode *) malloc(sizeof(ListNode));
        p->data = ch;
        // while循环第一次的时候 r,head指针指向的是同一块内存地址,所以head.next = p
        r->next = p;
        // r = p, 此时 r,p指针指向的是同一块内存地址.r,head的内存地址已经不一样
        r = p;
    }
    r->next = nullptr;

    return head;
}

/**
 * 按位置查找节点
 * @param head 头节点
 * @param i 需要查找的第i个元素
 * @return
 */
ListNode *getNodei(LinkList head, int i) {
    ListNode *p;
    // head节点为空节点,所以从1开始
    int j = 1;
    p = head->next;
    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }
    if (j == i) {
        return p;
    } else {
        return nullptr;
    }
}

/**
 * 按值查找节点
 * @param head
 * @param k
 * @return
 */
ListNode *locateNodeK(LinkList head, DataType k) {
    ListNode *p;
    p = head->next;
    while (p != nullptr && p->data != k) {
        p = p->next;
    }
    return p;
}

void InsertList(LinkList head, int i, DataType x) {
    ListNode *p, *n;
    int j = 0;
    p = head;
    // 获取第 i - 1的节点
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        printf("ERROR\n");
        return;
    } else {
        n = (ListNode *) malloc(sizeof(ListNode));
        n->data = x;
        // 此时的p指向 i -1 的节点
        n->next = p->next;
        p->next = n;
    }
}

/**
 * 删除第 i 个节点
 *
 * @param head
 * @param i
 * @return
 */
DataType DeleteList(LinkList head, int i) {
    ListNode *p, *s;
    DataType x;
    int j = 0;
    p = head;
    // 拿到第 i - 1 的节点
    while (p != nullptr && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == nullptr) {
        printf("位置错误\n");
        exit(0);
    } else {
        // 删除的节点
        s = p->next;
        // p 的next节点直接指向 i + 1 的节点
        p->next = s->next;
        x = s->data;
        // 释放资源
        free(s);
        return x;
    }
}

/**
 * p55 例2.5
 *
 * @param a
 * @param b
 */
void split(LinkList a, LinkList b) {
    ListNode *p, *s, *r;
    // p 指向头节点(a->next是开始节点)
    p = a->next;
    // s 指向链表的头节点,当 s->next = p;间接等于 a->next = p;
    s = a;
    // r 指向链表的头节点,当 r->next = p;间接等于 b->next = p;
    r = b;
    while (p != nullptr) {
        s->next = p;
        // s总是指向链表的最后一个节点
        s = p;
        p = p->next;
        if (p) {
            r->next = p;
            // r总是指向链表的最后一个节点
            r = p;
            p = p->next;
        }
    }
    s->next = r->next = nullptr;
}

/**
 * p55 例2.6
 *
 * @param La
 * @param Lb
 * @param Lc
 * @return
 */
LinkList MergeList(LinkList La, LinkList Lb) {
    ListNode *pa, *pb, *pc;
    LinkList Lc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;
    while (pa != nullptr && pb != nullptr) {
        if (pa->data > pb->data) {
            pc->next = pb;
            // pc 总是指向最后一个节点,pc->next = pb;pc = pb,下次循环的时候 pc = 上次的pc->next
            pc = pb;
            pb = pb->next;
        } else {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
    }
    // 当 pa | pb 有一个为 null后 while循环就终止,这里插入链表的剩余部分
    pc->next = pa != nullptr ? pa : pb;

    return Lc;
}

/**
 * 打印链表
 *
 * @param head
 */
void printList(LinkList head) {
    ListNode *p;
    p = head;
    while (p != nullptr) {
        if (p->data > 0) {
            cout << (char) p->data;
        }
        p = p->next;
    }
    cout << endl;
}

int main() {
    // 头插入法
//    LinkList list = createListF();
//    cout << (char) list->data;

    // 尾插入法
//    LinkList list = createListR();
//    cout << (char) list->data;

    // 尾插入法2
//    LinkList list = createListR1();
//    cout << (char) list->next->data;

    // 按位置查找节点
//    LinkList list = createListR1();
//    ListNode *head = getNodei(list, 5);
//    if (head != nullptr) {
//        cout << (char) head->data << endl;
//    } else {
//        cout << "未找到节点" << endl;
//    }

    // 按值查找节点
//    LinkList list = createListR1();
//    ListNode *node = locateNodeK(list, (int) ',');
//    if (node != nullptr) {
//        cout << (char) node->data << endl;
//    } else {
//        cout << "未找到节点" << endl;
//    }

    // 插入节点
//    LinkList head = createListR1();
//    InsertList(head, 5, (DataType) '!');
//    printList(head);
//    ListNode *node = getNodei(head, 5);
//    if (node != nullptr) {
//        cout << (char) node->data << endl;
//    } else {
//        cout << "未找到节点" << endl;
//    }

    // 删除节点
//    LinkList head = createListR1();
//    DeleteList(head, 5);
//    printList(head);

    // p55 例2.5
    // 申请头节点,head的data指为null,next指向下一个节点
//    LinkList linkA = createListR1();
//    LinkList linkB = (ListNode *) malloc(sizeof(ListNode));
//    split(linkA, linkB);
//    printList(linkA);
//    printList(linkB);

    // p56 例2.6
    LinkList linkA = createListR1();
    LinkList linkB = createListR1();
    LinkList linkC = MergeList(linkA, linkB);
    printList(linkC);
}

