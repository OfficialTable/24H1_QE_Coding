#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

// Fill in here
Shape::Shape(int x, int y){
    x_pos = x;
    y_pos = y;
}

void Shape::DrawSelf(){
    printf("Draw Shape at (%d, %d) \n", x_pos, y_pos);
}

Point::Point(int x, int y):Shape(x, y){
    x_pos = x;
    y_pos = y;
}
void Point::DrawSelf(){
    printf("Draw Point at (%d, %d) \n", x_pos, y_pos);
    }

Line::Line(int x, int y):Shape(x, y){
    x_pos = x;
    y_pos = y;
}
void Line::DrawSelf(){
    printf("Draw Line at (%d, %d) \n", x_pos, y_pos);
    }

Triangle::Triangle(int x, int y):Shape(x, y){
    x_pos = x;
    y_pos = y;
}
void Triangle::DrawSelf(){
   printf("Draw Triangle at (%d, %d) \n", x_pos, y_pos);
    }

Equilateral::Equilateral(int x, int y):Triangle(x, y){
    x_pos = x;
    y_pos = y;
}
void Equilateral::DrawSelf(){
    printf("Draw Equilateral at (%d, %d) \n", x_pos, y_pos);
    }

Isosceles::Isosceles(int x, int y):Triangle(x, y){
    x_pos = x;
    y_pos = y;
}
    void Isosceles::DrawSelf(){
    printf("Draw Isosceles at (%d, %d) \n", x_pos, y_pos);
    }

Scalene::Scalene(int x, int y):Triangle(x, y){
    x_pos = x;
    y_pos = y;
}
    void Scalene::DrawSelf(){
    printf("Draw Scalene at (%d, %d) \n", x_pos, y_pos);
    }

Quadrilateral::Quadrilateral(int x, int y):Shape(x, y){
    x_pos = x;
    y_pos = y;
}
    void Quadrilateral::DrawSelf(){
    printf("Draw Quadrilateral at (%d, %d) \n", x_pos, y_pos);
    }


Rectangle::Rectangle(int x, int y):Quadrilateral(x,y){
    x_pos = x;
    y_pos = y;
}
    void Rectangle::DrawSelf(){
    printf("Draw Rectangle at (%d, %d) \n", x_pos, y_pos);
    }

Square::Square(int x, int y):Quadrilateral(x,y){
    x_pos = x;
    y_pos = y;
}
    void Square::DrawSelf(){
    printf("Draw Square at (%d, %d) \n", x_pos, y_pos);
    }

