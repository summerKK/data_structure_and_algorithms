//
// Created by 陈思贝 on 2019/12/23.
//

#include <cstring>
#include <iostream>

using namespace std;

int Index(char const *S, char const *L) {
    int sLen = strlen(S);
    int lLen = strlen(L);
    int i = 0;
    int j = 0;
    while (i < sLen && j < lLen) {
        if (S[i] == L[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == lLen) {
        return i - j;
    }

    return 0;
}

int main() {
    char const *ch1 = "hello,world";
    char const *ch2 = "world";
    cout << Index(ch1, ch2) << endl;
}

