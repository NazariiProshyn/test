// CMakeProject1.cpp : Defines the entry point for the application.
//


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
	int getsize() { return size; }
private:
	int size = 0;
	int** arr = nullptr;
	friend Matrix swap(Matrix A, int size);
	friend Matrix mnozhennya(Matrix B, Matrix C, int size);

};




Matrix swap(Matrix A, int size);

Matrix mnozhennya(Matrix B, Matrix C, int size);

int result(Matrix B, Matrix C, int i, int j);
int main()
{
	//1


	int size;

	cout << "size:";
	cin >> size;

	Matrix A1(size);
	A1.vuvid();

	Matrix A(A1);
	cout << "RES" << endl;
	A.vuvid();

	//2



	Matrix B(size);
	cout << "MATR1" << endl;
	B.vuvid();


	Matrix C(size);
	cout << "MATR2" << endl;
	C.vuvid();
	Matrix D(mnozhennya(B, C, size));

	cout << "RES" << endl;
	D.vuvid();
}





Matrix swap(Matrix A, int size)
{
	for (int i = 0; i < size; i++) {
		int max = A.arr[i][0];
		int it = 0;

		for (int j = 0; j < size; j++) {
			if (max < A.arr[i][j]) {
				max = A.arr[i][j];
				it = j;
			}
		}

		A.arr[i][it] = A.arr[i][0];
		A.arr[i][0] = max;
	}
	return A;
}




Matrix mnozhennya(Matrix B, Matrix C, int size)
{
	Matrix res(size);

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++)
		{
			res.arr[i][j] = result(B, C, i, j);
		}
	}
	return res;
}




int result(Matrix B, Matrix C, int i, int j)
{
	int res = 0;
	int size = B.getsize();
	for (int z = 0; z < size; z++) {
		res += B.getnum(i, z) * C.getnum(z, j);
	}
	return res;
}
Matrix::Matrix(int inf)
{
	size = inf;
	arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 90 + 10;
		}
	}
	//cout << "NEW" << arr<<endl;
}

Matrix::Matrix(const Matrix& other)
{
	if (other.arr != this->arr) {
		this->size = other.size;
		this->arr = new int* [this->size];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = new int[this->size];
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
		//	cout << "COPY" << this->arr << endl;
	}


}

Matrix::~Matrix()
{
	//cout << "DELETE" << arr << " ";
	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = 0;
	//	cout << arr << endl;
}

void Matrix::vuvid()
{
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
}



bool Matrix::operator!=(const Matrix& other)
{
	if (this->arr == other.arr) { return true; }
	return false;
}
