#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {                  // 剩一個，把 disk 1 搬到 to
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);   // 第1步：n-1 盤搬到 aux，用 to 當輔助
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);  // 第2步：第 n 盤搬到 to
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);   // 第3步：n-1 盤從 aux 搬到 to，用 from 當輔助
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');  // A, B and C are names of rods
    return 0;
}
