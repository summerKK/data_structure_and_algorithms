#include <iostream>

using namespace std;

typedef char DATA_TYPE;
typedef struct Node {
    DATA_TYPE data;
    Node *prior;
    Node *next;
} DoubleNode;

typedef DoubleNode *DoubleLinkList;

DoubleLinkList createLinkList() {
    DoubleLinkList head, rear, p, prior;
    DATA_TYPE ch;
    head = (DoubleNode *) malloc(sizeof(DoubleNode));
    head->next = nullptr;
    rear = head;
    prior = nullptr;
    while ((ch = getchar()) != '\n') {
        p = (DoubleNode *) malloc(sizeof(DoubleNode));
        p->data = ch;
        p->next = nullptr;
        rear->next = p;
        rear->prior = prior;
        prior = rear;
        rear = p;
    }

    // 双向循环链表
    rear->next = head;

    return head;
}

void printLinkList(DoubleLinkList p) {
    DoubleNode *head = p->next;
    while ((p = p->next) && p->next != head) {
        cout << p->data << endl;
    }
}

int main() {
    DoubleLinkList doubleLinkList;
    doubleLinkList = createLinkList();

    printLinkList(doubleLinkList);
}

