#pragma once

// Fill in
class Shape {
    public:
        Shape(float x);
        virtual float area() = 0;
        void print();
    protected:
        float x_tmp;
};

class Square : public Shape{
    public:
        Square(float x) : Shape(x) {};
        float area();
        void print();
};

class Equilateral: public Shape{
    public:
        Equilateral(float x) : Shape(x) {};
        float area();
        void print();
};

