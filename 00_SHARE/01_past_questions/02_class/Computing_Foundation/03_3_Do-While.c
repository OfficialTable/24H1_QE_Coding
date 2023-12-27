#include <stdio.h>

int main(void) {
    printf("while statement\n");
    int x = 0;
    while (x<10) {
        printf("  %d\n", x);
        x += 1;
    }

    printf("Do-while statement\n");
    int y = 0;
    do {
        printf("  %d\n", y);
        y += 1;
    } while (y<10);

}