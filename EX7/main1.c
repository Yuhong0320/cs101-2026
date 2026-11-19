#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SETS 5
#define NUMS 7
#define MAX_NUM 69

int main(void)
{
    int n, i, j, k, num, dup;
    int lotto[MAX_SETS][NUMS];
    char timebuf[64];
    time_t now;
    FILE *fp;

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SETS) {
        printf("輸入錯誤，請輸入 1 ~ %d\n", MAX_SETS);
        return 1;
    }

    srand((unsigned)time(NULL));

    /* 每組 7 個不重複數字 (01~69) */
    for (i = 0; i < n; i++) {
        for (j = 0; j < NUMS; j++) {
            do {
                num = rand() % MAX_NUM + 1;
                dup = 0;
                for (k = 0; k < j; k++) {
                    if (lotto[i][k] == num) {
                        dup = 1;
                        break;
                    }
                }
            } while (dup);
            lotto[i][j] = num;
        }
    }

    now = time(NULL);
    {
        struct tm *t = localtime(&now);
        char wd[16], mon[16];
        strftime(wd, sizeof(wd), "%a", t);
        strftime(mon, sizeof(mon), "%b", t);
        sprintf(timebuf, "%s %s %d %02d:%02d:%02d %d", wd, mon, t->tm_mday,
                t->tm_hour, t->tm_min, t->tm_sec, t->tm_year + 1900);
    }

    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", timebuf);
    for (i = 0; i < MAX_SETS; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        for (j = 0; j < NUMS; j++) {
            if (i < n)
                fprintf(fp, "%02d", lotto[i][j]);
            else
                fprintf(fp, "--");
            fprintf(fp, j < NUMS - 1 ? " " : "\n");
        }
    }
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
