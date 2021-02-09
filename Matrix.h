#include <iostream>
#include <string>
#include<vector>
#include<ctime>

/**
*A Matrix class
* Class for working with Matrix
*/

class Matrix
{
public:
	/**
	* A Constructor
	* Creates a matrix of dimension size 
	* and fills with values from 10 to 99
	*/
	Matrix(size_t size);
	/*
	* copy constructor
	* Makes copy of matrix
	*/
	Matrix(const Matrix& other);
	~Matrix();

	/*
	*Displays matrix elements
	*/
	void vuvid();

	/**
	* get-function for matrix elements
	*/
	int getnum(int i, int j) { return arr[i][j]; }
	/**
	* set-function for matrix elements
	*/
	void setnum(int num, int i, int j) { arr[i][j] = num; };

	/**
	* get-function for matrix size
	*/
	int getsize() { return size; }
private:

	size_t size = 0; //< matrix size
	int** arr = nullptr; //matrix

	/*
	* copy assignment
	* Makes copy of matrix
	*/
	Matrix& operator= (const Matrix& other); //

};




Matrix swap(Matrix A);

Matrix mnozhennya(Matrix B, Matrix C);

int result(Matrix B, Matrix C, int i, int j);