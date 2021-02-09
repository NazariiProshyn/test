// CMakeProject1.cpp : Defines the entry point for the application.
//


#include"Matrix.h"
int main()
{
	//1


	size_t size;

	std::cout << "size:";
	std::cin >> size;

	Matrix A1(size);
	A1.vuvid();

	Matrix A(swap(A1));
	std::cout << "RES" << std::endl;
	A.vuvid();

	//2



	Matrix B(size);
	std::cout << "MATR1" << std::endl;
	B.vuvid();


	Matrix C(size);
	std::cout << "MATR2" << std::endl;
	C.vuvid();
	Matrix D(mnozhennya(B, C));

	std::cout << "RES" << std::endl;
	D.vuvid();
}






