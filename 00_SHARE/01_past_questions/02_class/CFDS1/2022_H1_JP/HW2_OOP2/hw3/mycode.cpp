#include <cstdlib>
#include <iostream>
#include <math.h>
#include "mycode.h"

// Fill in
Shape::Shape(float x)  {
    float x_tmp = x;
}

float Square::area(){
    float res = x_tmp * x_tmp;
    return res;
}

float Equilateral::area(){
    float res = x_tmp * x_tmp * sqrt(3.0f) / 4.0f;
    return res;
}

void Square::print(){
    printf("This is Square. Area is %f \n", area());
}

void Equilateral::print(){
    printf("This is Equilateral. Area is %f \n", area());
}

void Shape::print() {
    printf("This is Shape. Area is %f \n", area());
}
    
    