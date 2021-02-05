// CMakeProject1.cpp : Defines the entry point for the application.
//


#include"Matrix.h"
int main()
{
	//1
	

	int size;

	cout << "size:";
	cin >> size;

	Matrix A1(size);
	A1.vuvid();

	Matrix A(swap(A1,size));
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






