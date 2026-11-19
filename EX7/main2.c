#include <stdio.h>
#include <string.h>

#define NUM_BOOKS 6
#define TITLE_LEN 64

typedef struct Books {
    int id;
    int price;
    char title[TITLE_LEN];
} book_t;

/* 計算並輸出所有書籍總價 */
void total_price(book_t books[], int n)
{
    int i, total = 0;
    for (i = 0; i < n; i++)
        total += books[i].price;
    printf("Total price: %d\n", total);
}

/* 輸出所有書籍資料 */
void list_books(book_t books[], int n)
{
    int i;
    printf("%-4s %-8s %s\n", "Id", "Price", "Title");
    for (i = 0; i < n; i++)
        printf("%-4d %-8d %s\n", books[i].id, books[i].price, books[i].title);
}

int main(void)
{
    book_t books[NUM_BOOKS] = {
        {1, 1000, "All the Light We Cannot See"},
        {2,  300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4,  550, "Killers of the Flower Moon"},
        {5,  870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    /* 將書籍資料寫入 Book.bin */
    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟 Book.bin\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), NUM_BOOKS, fp);
    fclose(fp);

    list_books(books, NUM_BOOKS);
    total_price(books, NUM_BOOKS);
    return 0;
}
