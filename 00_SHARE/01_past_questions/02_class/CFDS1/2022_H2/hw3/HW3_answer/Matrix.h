#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <cmath>
using namespace std;

class Matrix {
    public:
        // member functions
        void input (vector<vector<double> >&);
        Matrix operator+(const Matrix&);
        Matrix operator-(const Matrix&);
        Matrix operator*(const Matrix&);
        Matrix Transpose();
        Matrix GetSubVectorbyColumn(int);
        void Print();
        
        // accessors
        int GetNumRow();
        int GetNumColumn();
        double GetVal(int x, int y);

        // friend class
        // every member function of DataFrame can access the Matrix's members
        friend class DataFrame;

        // member variables
        vector<vector<double>> arr;
        int rows;
        int cols;
};

class DataFrame {
    public:
        // member functions
        int ReadData(string, char, char, bool);
        Matrix GetMatrix(int[], int);
        // member variables
        vector<vector<string> >parsedCsv;
};

Matrix Cor(Matrix &, int method = 1);
Matrix SimpleLinearRegression(Matrix &, Matrix&);