#include "Electronics.h"

// Fill in here
#include <stdio.h>

/*-------------------- Electronics --------------------*/
/*** Constructor ***/
Electronics::Electronics(float aSize) {
    size = aSize;
}

/*** Accessors ***/
void Electronics::SetSize(float aSize) {
    size = aSize;
}

float Electronics::GetSize(void) {
    return(size);
}

float Electronics::Price(void) {
    return(size);
}

/*-------------------- TV --------------------*/
float TV::Price(void) {
    return(Electronics::Price() * 1.8);
}

void TV::PrintSelf() {
    printf("It is a TV, Size=%.0f, Price=%.0f \n", size, Price());
}

/*-------------------- Cellphon --------------------*/
float Cellphone::Price(void) {
    return(Electronics::Price() * 0.7);
}

void Cellphone::PrintSelf() {
printf("It is a Cellphone, Size=%.0f, Price=%.0f \n", size, Price());
}

/*-------------------- Computer --------------------*/
float Computer::Price(void) {
    return(Electronics::Price() * 0.6);
}

void Computer::PrintSelf() {
    printf("It is a Computer, Size=%.0f, Price=%.0f \n", size, Price());
}

/*-------------------- Laptop --------------------*/
void Laptop::AddGPU(Computer *aGPU) {
    if (nGPU == 0)
       GPU1 = aGPU;
    else
       GPU2 = aGPU;
   nGPU++;
}

float Laptop::Price(void) {
    if (nGPU == 0){
        return(Computer::Price());
    }
    else {
        return(Computer::Price() * 2);
    }
}

float Laptop::TotalPrice(void){
    float GPUPrice1 = 0;
    float GPUPrice2 = 0;

    if (nGPU == 0){
        GPUPrice1 = 0;
        GPUPrice2 = 0;
    }
    else if (nGPU == 1){
        GPUPrice1 = GPU1->Price();
        GPUPrice2 = 0;
    }
    else {
        GPUPrice1 = GPU1->Price();
        GPUPrice2 = GPU2->Price();
    }
    return(Price() + GPUPrice1 + GPUPrice2);
}

void Laptop::PrintSelf() {
    printf("It is a Laptop with %d GPU(s), Size=%.0f, Price=%.0f, Total Price=%.0f \n", nGPU, size, Price(), TotalPrice());
}