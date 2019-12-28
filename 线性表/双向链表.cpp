#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//
// Created by 陈思贝 on 2019/12/3.
//
typedef int DataType;
typedef struct dlnode {
    DataType data;
    struct dlnode *prior, *next;
} DLNode;
typedef DLNode *DlLinkList;

DlLinkList CreateDLLinkList() {
    // r 指向尾节点, p 当前节点, prior 前趋节点
    DlLinkList head, prior, p, r;
    // 头节点
    head = (DLNode *) malloc(sizeof(DLNode));
    head->data = 0;
    head->prior = nullptr;
    // r指向头节点,当 r->next = p,间接等于 head->next = p;
    r = head;
    // 初始化的时候 前趋节点为null
    prior = nullptr;
    DataType ch;
    while ((ch = getchar()) != '\n') {
        // 创建一个节点
        p = (DLNode *) malloc(sizeof(DLNode));
        // 给节点赋值
        p->data = ch;
        // 第一次循环的时候 r = head,也就是  head->next = p;
        r->next = p;
        r->prior = prior;
        // 记住前趋节点
        prior = r;
        // r的next节点为p,r=p相当于 r = r的下个节点,下次循环的时候r->next 就相当于 当前的 r->next->next
        r = p;
    }

    // 双向循环链表
    r->next = head;

    return head;
}

/**
 *  打印链表
 * @param dlLinkList
 */
void printDlLinkList(DlLinkList dlLinkList) {
    DLNode *p;
    p = dlLinkList->next;
    // 当 p == dlLinkList 相当于已经
    while (p != dlLinkList) {
        if (p->data > 0) {
            cout << (char) p->data;
        }
        p = p->next;
    }
    cout << endl;
}

/**
 * 插入节点
 *
 * @param p
 * @param x
 */
void DlInsert(DLNode *p, DataType x) {
    // pre前趋节点,p当前节点
    DLNode *pre, *s;
    s = (DLNode *) malloc(sizeof(DLNode));
    s->data = x;
    pre = p->prior;
    pre->next = s;
    p->prior = s;
    s->prior = pre;
    s->next = p;
}

/**
 * 删除节点
 *
 * @param p
 */
void DlDelete(DLNode *p) {
    DlLinkList pre, next;
    pre = p->prior;
    next = p->next;
    pre->next = next;
    next->prior = pre;
    free(p);
}

int main() {
    // 创建节点
//    DlLinkList dlLinkList = CreateDLLinkList();
//    printDlLinkList(dlLinkList);
//    // hello,world  dlLinkList->next->next->prior->data = h
//    cout << (char) dlLinkList->next->next->prior->data << endl;

    // 插入节点
//    DlLinkList dlLinkList = CreateDLLinkList();
//    // hello,world  dlLinkList->next->next = 'e'
//    DLNode *p = dlLinkList->next->next;
//    DlInsert(p, '!');
//    printDlLinkList(dlLinkList);

    // 删除节点
    DlLinkList dlLinkList = CreateDLLinkList();
    // hello,world  dlLinkList->next->next = 'e'
    DlLinkList p = dlLinkList->next->next;
    DlDelete(p);
    printDlLinkList(dlLinkList);
}


