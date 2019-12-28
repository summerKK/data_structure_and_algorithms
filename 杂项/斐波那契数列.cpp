//
// Created by 陈思贝 on 2019/12/22.
//
#include <iostream>

using namespace std;

int fibo1(int num) {
    int a[num + 1];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i <= num; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[num];
}

int fibo2(int num) {
    if (num < 2) {
        return num;
    }
    return fibo2(num - 1) + fibo2(num - 2);
}

int main() {
    cout << "fibo1:" << fibo1(5) << endl;
    cout << "fibo2:" << fibo2(5) << endl;
}

