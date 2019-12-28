#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *next;
} Link;

Link *init() {
    Link *p = (Link *) malloc(sizeof(Link));
    return p;
}

int main() {
    Link *a, *b, *c;
    // 此时 a,b,c的指针指向同一块内存地址,也就是说当 a->data = 20 ((a*).data = 20) => b|c.data = 20((b*|c*).data = 20)
    a = b = c = init();
    a->data = 100;
    cout << b->data << endl;
    cout << c->data << endl;

    cout << endl;

    cout << b << endl;
    cout << "a,b,c指针指向的变量的内存地址:a:" << &(*a) << ",b:" << &(*b) << ",c:" << &(*c) << endl;
    // a指向新的指针,当 a->data = 20;b,c不受影响
    a = (Link *) malloc(sizeof(Link));
    // *b = *a 意思为:把b指针指向的变量的值修改为 *a的值,此时 (*a).data = 0
    *b = *a;
    cout << "a,b,c指针指向的变量的内存地址:a:" << &(*a) << ",b:" << &(*b) << ",c:" << &(*c) << endl;
    cout << "b指向的变量的内存地址:" << b << ",b的内存地址" << &b << endl;
    // (a*).data = 200;
    a->data = 200;
    // b,c指针指向变量的内存地址 指向 a指针指向变量的内存地址
    b = c = a;
    cout << "a,b,c指针指向的变量的内存地址:a:" << &(*a) << ",b:" << &(*b) << ",c:" << &(*c) << endl;
    cout << c->data << endl;
    cout << b->data << endl;
    cout << a->data << endl;
}
