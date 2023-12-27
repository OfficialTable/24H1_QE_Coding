#include "shapes.h"
#include <cstdio>

// Fill in here
Shape::Shape(int x, int y) {
	x_pos = x;
	y_pos = y;
}

void Shape::DrawSelf() {
	printf("Draw Shape at (%d, %d)", x_pos, y_pos);
}

void Point::DrawSelf() {
	printf("Draw Point at (%d, %d)\n", x_pos, y_pos);
}

void Line::DrawSelf() {
	printf("Draw Line at (%d, %d)\n", x_pos, y_pos);
}

void Triangle::DrawSelf() {
	printf("Draw Triangle at (%d, %d)\n", x_pos, y_pos);
}

void Quadrilateral::DrawSelf() {
	printf("Draw Quadrilateral at (%d, %d)\n", x_pos, y_pos);
}

void Equilateral::DrawSelf() {
	printf("Draw Equilateral at (%d, %d)\n", x_pos, y_pos);
}

void Isosceles::DrawSelf() {
	printf("Draw Isosceles at (%d, %d)\n", x_pos, y_pos);
}

void Scalene::DrawSelf() {
	printf("Draw Scalene at (%d, %d)\n", x_pos, y_pos);
}

void Rectangle::DrawSelf() {
	printf("Draw Rectangle at (%d, %d)\n", x_pos, y_pos);
}

void Square::DrawSelf() {
	printf("Draw Square at (%d, %d)\n", x_pos, y_pos);
}
