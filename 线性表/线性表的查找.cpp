//
// Created by 陈思贝 on 2019/12/1.
//
#include <iostream>

using namespace std;

#define ListSize 100
typedef int DateType;
typedef struct {
    DateType data[ListSize];
    int length;
} SeqList;

void MaxMin(SeqList L, DateType *max, DateType *min, int *k, int *j) {
    int i;
    *max = L.data[0];
    *min = L.data[0];
    *k = *j = 0;
    for (i = 0; i < L.length; ++i) {
        if (*max < L.data[i]) {
            *max = L.data[i];
            *k = i;
        }

        if (*min > L.data[i]) {
            *min = L.data[i];
            *j = i;
        }
    }
}

int main() {
    SeqList list = {10, 20, 30, 40, 50, 60, 70, .length=7};
    DateType max;
    DateType min;
    int k;
    int j;
    MaxMin(list, &max, &min, &k, &j);
    cout << "最大数:" << max << " 下标:" << k << endl;
    cout << "最小数:" << min << " 下标:" << j << endl;
}
