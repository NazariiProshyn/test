#include <iostream>
#include <string>
#include<vector>
#include<ctime>

using namespace std;



class Matrix
{
public:
	Matrix(int size);
	Matrix(const Matrix& other);
	~Matrix();
	void vuvid();

	bool operator !=(const Matrix& other);
	int getnum(int i, int j) { return arr[i][j]; }
	void setnum(int num, int i, int j) { arr[i][j] = num; };
	int getsize() { return size; }
private:
	int size = 0;
	int** arr = nullptr;


};




Matrix swap(Matrix A, int size);

Matrix mnozhennya(Matrix B, Matrix C, int size);

int result(Matrix B, Matrix C, int i, int j);