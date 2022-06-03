#pragma once

#define MATHLIBY_API  __declspec( dllexport )


#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <cmath>
#include <initializer_list>
using namespace std;

class Exception1 : public std::exception {
	string text1;
public:
	MATHLIBY_API Exception1(string t) : text1(t) {}
	const char* what() const { return text1.c_str(); }
};



class Matrix
{
protected:
	vector<vector<double>> M;
public:
	MATHLIBY_API Matrix() {}
	MATHLIBY_API Matrix(int n, int m);
	MATHLIBY_API Matrix(int n);
	MATHLIBY_API Matrix(initializer_list<double> list);
	MATHLIBY_API friend ostream& operator << (ostream& out, const  Matrix& M);
	MATHLIBY_API friend ifstream& operator>>(ifstream& input, Matrix& M);
	MATHLIBY_API friend ofstream& operator << (ofstream& out, Matrix& M);
	MATHLIBY_API void SetMij(int i, int j, const double value);
	MATHLIBY_API Matrix operator + (Matrix N)const;
	MATHLIBY_API Matrix operator-(Matrix N)const;
	MATHLIBY_API Matrix operator*(double x)const;
	MATHLIBY_API Matrix operator*(Matrix N)const;
	MATHLIBY_API void ReadBin(const char* fname);
	MATHLIBY_API void WriteBin(const char* fname);
	MATHLIBY_API Matrix Hadamard(Matrix N2);
	MATHLIBY_API double Det();
	MATHLIBY_API double Scalar(Matrix M2);
	MATHLIBY_API double Norm();
	MATHLIBY_API double Tr();
	MATHLIBY_API double Max();
	MATHLIBY_API double NormM();
	MATHLIBY_API double Angle(Matrix M2);
	MATHLIBY_API double Rank();
	MATHLIBY_API Matrix Minor(int n, int m);
	MATHLIBY_API Matrix Transpose();
	MATHLIBY_API Matrix Inverse();
	MATHLIBY_API Matrix AddColumn(Matrix V);
	MATHLIBY_API vector<int> Size();
	MATHLIBY_API double getElem(int n, int m);
};

class PCA {
protected:
	Matrix P;
	Matrix T;
	Matrix E;
	vector<double> H;
	vector<double> V;
	vector<double> TRV;
	vector<double> ERV;
public:
	MATHLIBY_API PCA() {}
	MATHLIBY_API PCA(Matrix M, int ar);
	MATHLIBY_API void  Dispersion();
	MATHLIBY_API void  HV();
	MATHLIBY_API Matrix GetP();
	MATHLIBY_API Matrix GetT();
	MATHLIBY_API Matrix GetE();
	MATHLIBY_API vector<double> GetH();
	MATHLIBY_API vector<double> GetV();
	MATHLIBY_API vector<double> GetTRV();
	MATHLIBY_API vector<double> GetERV();
	MATHLIBY_API Matrix Centering(Matrix M1);
	MATHLIBY_API Matrix Scaling(Matrix M1);
};

class EMatrix : public Matrix {
public:
	MATHLIBY_API EMatrix() {}
	MATHLIBY_API EMatrix(int n);
};

class DMatrix : public Matrix {
public:
	MATHLIBY_API DMatrix(int n);
};

class UTMatrix : public Matrix {
public:
	MATHLIBY_API UTMatrix(int n);
};

class LTMatrix : public Matrix {
public:
	MATHLIBY_API LTMatrix(int n);
};

class SMatrix : public Matrix {
public:
	MATHLIBY_API SMatrix(int n);
};