#include"Matrix.h"
Matrix swap(Matrix A)
{

	for (int i = 0; i < A.getsize(); i++) {
		int max = A.getnum(i, 0);
		int it = 0;

		for (int j = 0; j < A.getsize(); j++) {
			if (max < A.getnum(i, j)) {
				max = A.getnum(i, j);
				it = j;
			}
		}

		A.setnum(A.getnum(i, 0), i, it);
		A.setnum(max, i, 0);

	}
	return A;
}




Matrix mnozhennya(Matrix B, Matrix C)
{
	Matrix res(B.getsize());

	for (int i = 0; i < B.getsize(); i++) {

		for (int j = 0; j < B.getsize(); j++)
		{
			res.setnum(result(B, C, i, j), i, j);
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
Matrix::Matrix(size_t inf)
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
		std::cout << "|";
		for (int j = 0; j < size; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	Matrix A(other.size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A.setnum(other.arr[i][j], i, j);
		}
	}
	return A;

}



