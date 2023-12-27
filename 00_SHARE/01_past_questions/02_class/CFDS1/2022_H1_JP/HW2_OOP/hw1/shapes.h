#pragma once

// Usually for prototype
// Fill in here
class Shape {
public:
	Shape(int x, int y);
	virtual void DrawSelf() = 0;
protected:
	int x_pos;
	int y_pos;
};

class Point : public Shape {
public:
	Point(int x, int y) : Shape(x, y) {};
	void DrawSelf();
};

class Line : public Shape {
public:
	Line(int x, int y) : Shape(x, y) {};
	void DrawSelf();
};

class Triangle : public Shape {
public:
	Triangle(int x, int y) : Shape(x, y) {};
	void DrawSelf();
};

class Quadrilateral : public Shape {
public:
	Quadrilateral(int x, int y) : Shape(x, y) {};
	void DrawSelf();
};

class Equilateral : public Triangle {
public:
	Equilateral(int x, int y) : Triangle(x, y) {};
	void DrawSelf();
};

class Isosceles : public Triangle {
public:
	Isosceles(int x, int y) : Triangle(x, y) {};
	void DrawSelf();
};

class Scalene : public Triangle {
public:
	Scalene(int x, int y) : Triangle(x, y) {};
	void DrawSelf();
};

class Rectangle : public Quadrilateral {
public:
	Rectangle(int x, int y) : Quadrilateral(x, y) {};
	void DrawSelf();
};

class Square : public Quadrilateral {
public:
	Square(int x, int y) : Quadrilateral(x, y) {};
	void DrawSelf();
};
