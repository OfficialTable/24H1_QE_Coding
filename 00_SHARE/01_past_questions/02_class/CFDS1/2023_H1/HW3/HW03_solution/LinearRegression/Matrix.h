#pragma once
#include <vector>
#include <string>
using namespace std;

class Matrix {
    public:
        // parameterized constructor
        Matrix(vector<vector<double>>mat);
        // copy constructor
        Matrix(const Matrix &mat);
        // member functions
        Matrix operator+(const Matrix &A);
        Matrix operator-(const Matrix &A);
        Matrix operator*(const Matrix &A);
        Matrix Transpose();
        Matrix GetSubVectorbyColumn(int column);
        void Print();
        
        // accessors
        int GetNumRow() const;
        int GetNumColumn() const;
        double GetVal(int x, int y) const;

        // member variables
        vector<vector<double>> matrix;
};

class DataFrame {
    public:
        // constructor
        DataFrame();
        // member functions
        int ReadData(string FileName, char sep, char comment, bool IsHeader);
        Matrix GetMatrix(int index[], int nColumn);
        
    protected:
        // member variables
        vector<vector<double>> content;
        vector<vector<double>> mat;
        vector<double> row;
        string value;
        string line;
};

Matrix Cor(Matrix &mat, int method = 1);
double Pearson(Matrix &X, Matrix &Y);
double Kendall(Matrix &X, Matrix &Y);
Matrix SimpleLinearRegression(Matrix &X, Matrix&Y);