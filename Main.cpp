// CMakeProject1.cpp : Defines the entry point for the application.
//


#include <iostream>
#include <string>
#include<ostream>
#include<ctime>

using namespace std;


int** create_arr(int size);///
void swap(int* arr, int size);///
void vuvid(int** arr, int size);///
int** mnozhennya(int** arr1, int** arr2, int size);
int* create_raw(int** arr2, int size, int j);///
int result(int* raw1, int* raw2, int size);
int main()
{
	//1
	srand(time(NULL));

	int size;

	cout << "size:";
	cin >> size;

	int** arr = create_arr(size);
	vuvid(arr, size);

	for (int i = 0; i < size; i++)
	{
		swap(arr[i], size);
	}
	cout << "RES" << endl;
	vuvid(arr, size);

	//2

	system("pause");
	system("cls");

	int** arr1 = create_arr(size);
	cout << "MATR1" << endl;
	vuvid(arr1, size);


	int** arr2 = create_arr(size);
	cout << "MATR2" << endl;
	vuvid(arr2, size);

	int** arr3 = mnozhennya(arr1, arr2, size);
	cout << "RES" << endl;
	vuvid(arr3, size);
}

int** create_arr(int size)
{

	int** arr = new int* [size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}



	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 90 + 10;
		}
	}

	return arr;
}

void swap(int* arr, int size)
{
	int max = arr[0];
	int it = 0;

	for (int i = 0; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
			it = i;
		}
	}

	arr[it] = arr[0];
	arr[0] = max;
}

void vuvid(int** arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
}

int** mnozhennya(int** arr1, int** arr2, int size)
{
	int** arr = create_arr(size);
	int* raw;
	for (int i = 0; i < size; i++) {
		raw = create_raw(arr2, size, i);
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = result(arr1[j], raw, size);
		}
	}
	return arr;
}

int* create_raw(int** arr2, int size, int j)
{
	int* raw = new int[size];
	for (int i = 0; i < size; i++) {
		raw[i] = arr2[i][j];
	}
	return raw;
}

int result(int* raw1, int* raw2, int size)
{
	int res = 0;;
	for (int i = 0; i < size; i++) {
		res += raw1[i] * raw2[i];
	}
	return res;
}
