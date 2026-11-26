#include <stdio.h>
#include <string.h>

typedef struct movie {
    char name[32];
    int ranking;
} movie_t;

void fill_movie(movie_t* m) {
    strcpy(m->name, "BE ALL YOU CAN BE!");   // Arrow 用法
    m->ranking = 1;                          // Arrow 用法
}

int main() {
    movie_t mymovie;
    fill_movie(&mymovie);   // 傳入 struct 的 address
    printf("name = %s\n", mymovie.name);
    printf("ranking = %d\n", mymovie.ranking);
    return 0;
}
