#include <stdio.h>

int multi(int i, int j) {
    if (j == 1) {                  // 中止條件
        printf("%d*%d=%d\n", i, j, i * j);
        return 0;
    } else {
        multi(i, j - 1);           // 每一步輸入參數減一
        printf("%d*%d=%d\n", i, j, i * j);  // 每一步輸出
    }
    return 0;
}

int main() {
    multi(1, 9);                   // 開始條件
    return 0;
}
