#include <iostream>

using namespace std;

#define ListSize 100
typedef int DataType;
typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;

void InsertList(SeqList *L, int i, DataType x) {
    int j;
    if (i < 1 || i > L->length) {
        printf("position error");
        return;
    }
    if (L->length == ListSize) {
        printf("overflow");
        return;
    }
    for (j = L->length; j > i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = x;
    L->length++;
}

int main() {
    SeqList *a = new SeqList();
    a->length = 10;
    InsertList(a, 5, 5);
    cout << *(a->data + 4) << endl;
    cout << "hello,world" << endl;
    cout << "Summer" << endl;
    cout << "Sunny" << endl;
    cout << "你好啊" << endl;
    cout << "你好啊" << endl;
}
