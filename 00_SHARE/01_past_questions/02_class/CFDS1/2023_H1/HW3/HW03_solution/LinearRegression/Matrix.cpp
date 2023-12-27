#include "Matrix.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

/***DataFrame***/
DataFrame::DataFrame(){
    vector<vector<double>> content; // original matrix
    vector<vector<double>> mat; // indexed matrix
}

int DataFrame::ReadData(string FileName, char sep, char comment, bool IsHeader){
    ifstream myfile (FileName);
    if(!myfile) exit (1);

    if (myfile.is_open()){
        while (getline(myfile, line)){
            if (line[0] == comment) {
                continue;
            }
            if (IsHeader == true) {
                IsHeader = false;
                continue;
            }
            row.clear();
            stringstream ss(line);
            while(getline(ss, value, sep)) {
                row.push_back(stod(value));
            }
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
    
    myfile.close();
    return 0;
}

Matrix DataFrame::GetMatrix(int index[], int nColumn){
    for (int i=0 ; i < content.size() ; i++){
        row.clear();
        for (int j = 0 ; j < nColumn ; j++){
            row.push_back(content[i][index[j]]);
        }
        mat.push_back(row);
    }
    Matrix A(mat);
    return A;
}

/***Matrix***/
// parameterized constructor
Matrix::Matrix(vector<vector<double>>mat):matrix(mat){}
// copy constructor
Matrix::Matrix(const Matrix &mat){
    matrix = mat.matrix;
}

Matrix Matrix::operator+(const Matrix &A){
    vector<vector<double>> temp(GetNumRow(), vector<double>(GetNumColumn(), 0));
    Matrix Temp(temp);

    for (int i=0 ; i<Temp.GetNumRow(); i++){
        for (int j=0 ; j<Temp.GetNumColumn(); j++){
            Temp.matrix[i][j] = GetVal(i, j) + A.GetVal(i, j);
        }
    }
    return Temp;
}
Matrix Matrix::operator-(const Matrix &A){
    vector<vector<double>> temp(GetNumRow(), vector<double>(GetNumColumn(), 0));
    Matrix Temp(temp);

    for (int i=0 ; i<Temp.GetNumRow(); i++){
        for (int j=0 ; j<Temp.GetNumColumn(); j++){
            Temp.matrix[i][j] = GetVal(i, j) - A.GetVal(i, j);
        }
    }
    return Temp;
}
Matrix Matrix::operator*(const Matrix &A){
    vector<vector<double>> temp(GetNumRow(), vector<double>(A.GetNumColumn(), 0));
    Matrix Temp(temp);

    for (int i=0 ; i<Temp.GetNumRow(); i++){
        for (int j=0 ; j<Temp.GetNumColumn(); j++){
            for (int k=0 ; k<GetNumColumn(); k++){
                Temp.matrix[i][j] += (GetVal(i, k) * A.GetVal(k, j));
            }
        }
    }
    return Temp;
}

Matrix Matrix::Transpose(){
    vector<vector<double>> temp(GetNumColumn(), vector<double>(GetNumRow(), 0));
    Matrix Temp(temp);
    
    for (int i=0 ; i<GetNumColumn(); i++){
        for (int j=0 ; j<GetNumRow(); j++){
            Temp.matrix[i][j] = GetVal(j, i);
        }
    }
    return Temp;
}

Matrix Matrix::GetSubVectorbyColumn(int column){
    vector<vector<double>> mat;
    vector<double> row;

    for (int i=0 ; i < GetNumRow() ; i++){
        row.clear();
        row.push_back(matrix[i][column]);
        mat.push_back(row);
    }

    Matrix A(mat);
    return A;
}

void Matrix::Print(){
    for(int i=0;i<GetNumRow();i++){
        for(int j=0;j<GetNumColumn();j++){
            cout<<GetVal(i, j)<<" ";
        }
        cout<<endl;
    }
}

int Matrix::GetNumRow()const {
    return matrix.size();
}

int Matrix::GetNumColumn()const {
    return matrix[0].size();
}

double Matrix::GetVal(int x, int y) const{
    return matrix[x][y];
}

/**Correlation**/
Matrix Cor(Matrix &mat, int method){
    vector<vector<double>> temp(mat.GetNumColumn(), vector<double>(mat.GetNumColumn(), 0));
    Matrix Temp(temp);

    // Pearson
    if (method == 1){
        for (int i=0 ; i<Temp.GetNumColumn(); i++){
            for (int j=0 ; j<Temp.GetNumRow(); j++){
                if (i == j)
                    Temp.matrix[i][j] = 1;
                else {
                    Matrix X = mat.GetSubVectorbyColumn(i);
                    Matrix Y = mat.GetSubVectorbyColumn(j);
                    Temp.matrix[i][j] = Pearson(X, Y);
                }
            }
        }
    }
    // Kendall's tau
    if (method == 2){
        for (int i=0 ; i<Temp.GetNumColumn(); i++){
            for (int j=0 ; j<Temp.GetNumRow(); j++){
                if (i == j)
                    Temp.matrix[i][j] = 1;
                else {
                    Matrix X = mat.GetSubVectorbyColumn(i);
                    Matrix Y = mat.GetSubVectorbyColumn(j);
                    Temp.matrix[i][j] = Kendall(X, Y);
                }
            }
        }
    }
    return Temp;
}

double Pearson(Matrix &X, Matrix &Y){
    int n = X.GetNumRow();
    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;
  
    for (int i = 0; i < n; i++){
        // sum of elements of vector X.
        sum_X = sum_X + X.GetVal(i,0);
        // sum of elements of vector Y.
        sum_Y = sum_Y + Y.GetVal(i,0);
        // sum of X[i] * Y[i].
        sum_XY = sum_XY + X.GetVal(i,0) * Y.GetVal(i,0);
        // sum of square of array elements.
        squareSum_X = squareSum_X + X.GetVal(i,0) * X.GetVal(i,0);
        squareSum_Y = squareSum_Y + Y.GetVal(i,0) * Y.GetVal(i,0);
    }
    // use formula for calculating correlation coefficient.
    double result = (double)(n * sum_XY - sum_X * sum_Y) / sqrt((n * squareSum_X - sum_X * sum_X) * (n * squareSum_Y - sum_Y * sum_Y));
    return result;
}

double Kendall(Matrix &X, Matrix &Y){
    int size = X.GetNumRow();
    int numerator = 0;
    int denominator = size * (size - 1) / 2;
    int t = 0;

    for (int i=0 ; i<size ; i++){
        for (int j=0 ; j<i ; j++){
            t = (X.GetVal(i,0) - X.GetVal(j,0)) * (Y.GetVal(i,0) - Y.GetVal(j,0)) >= 0 ? 1: -1;
            numerator += t;
        }
    }

    double result = (double) numerator / (double) denominator;
    return result;
}

/**SimpleLinearRegression**/
Matrix SimpleLinearRegression(Matrix &X, Matrix&Y){
    int n = X.GetNumRow();
    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;
    double coeff = 0;
    double constTerm = 0;
    vector<vector<double>> ans;
    vector<double> row;

    // take inputs
    for (int i = 0; i < n; i++){
        sum_X = sum_X + X.GetVal(i,0);
        sum_Y = sum_Y + Y.GetVal(i,0);
        sum_XY = sum_XY + X.GetVal(i,0) * Y.GetVal(i,0);
        squareSum_X = squareSum_X + X.GetVal(i,0) * X.GetVal(i,0);
        squareSum_Y = squareSum_Y + Y.GetVal(i,0) * Y.GetVal(i,0);
    }
    // fitting line
    coeff = (n * sum_XY - sum_X * sum_Y) / (n * squareSum_X - sum_X * sum_X);
    constTerm = (sum_Y * squareSum_X - sum_X * sum_XY) / (n * squareSum_X - sum_X * sum_X);

    row.push_back(constTerm);
    ans.push_back(row);
    row.clear();
    row.push_back(coeff);
    ans.push_back(row);

    Matrix A(ans);
    return A;
}