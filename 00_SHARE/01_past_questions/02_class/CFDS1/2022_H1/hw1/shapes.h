#pragma once

// Fill in here
class Shape {
    public:
    Shape(int x, int y);
    int x_pos, y_pos;
    virtual void DrawSelf();
};

class Point : public Shape{
    public:
    Point(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Line : public Shape{
    public:
    Line(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Triangle : public Shape{
    public:
    Triangle(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Equilateral : public Triangle{
    public:
    Equilateral(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Isosceles : public Triangle{
    public:
    Isosceles(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Scalene : public Triangle{
    public:
    Scalene(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Quadrilateral : public Shape{
    public:
    Quadrilateral(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Rectangle : public Quadrilateral{
    public:
    Rectangle(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};

class Square : public Quadrilateral{
    public:
    Square(int x, int y);
    int x_pos, y_pos;
    void DrawSelf();
};