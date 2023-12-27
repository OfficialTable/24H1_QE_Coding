#include <stdio.h>

// 이상함 


// Declaration
int Watt(int n);
int Volt(int n, int m);

int main(void) {
    int a;
    int b;

    b = Watt(a);
    printf("Watt(a) = %d", b);
    
    b = Volt(a, b);
    printf("Volt(a,b) = %d", b);
} 

// Definition

int Watt(int a) {
    int w;
    w = Volt(w, 10);
    return w;
} 

int Volt(int q, int r) {

}