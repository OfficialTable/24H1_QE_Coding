#include <stdio.h>
int inGlobal;

int main(void) {
    int inLocal = 5;
    int outLocalA;
    int outLocalB;
    inGlobal = 3;
    
    outLocalA = inLocal * inGlobal;
    outLocalB = inLocal & inGlobal;
    printf("outLocalA = %d, outLocalB = %d\n", outLocalA, outLocalB);
    return 0;
}