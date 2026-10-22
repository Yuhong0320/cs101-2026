#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1f, 1.2f, 1.3f};
    int ra[3];
    char rb[4];
    float rc[3];
    int i;

    /* 寫入：一定要用 "wb" */
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("cannot open file\n");
        return 1;
    }
    fwrite(a, sizeof(a), 1, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    fclose(fp);

    /* 讀取：用 "rb"，順序和大小要跟寫入時一樣 */
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("cannot open file\n");
        return 1;
    }
    fread(ra, sizeof(ra), 1, fp);
    fread(rb, sizeof(rb), 1, fp);
    fread(rc, sizeof(rc), 1, fp);
    fclose(fp);

    for (i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("%c ", rb[i]);
    }
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf("%f ", rc[i]);
    }
    printf("\n");

    return 0;
}
