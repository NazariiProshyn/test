
#include <iostream>
#include <string>
#include<ostream>
#include<ctime>
using namespace std;
/*1) Создать двумерный массив 5х5, з
аполнить его случайными числами от 
10 до 99 и вывести на экран. Поменять местами максимальный элемент 
каждой строки с первым элементом в соответствующей строке. 
Задачу решить с помощью указателей.*/

/*2) Задача на умножение матриц. Пользователь произвольно задает размерность двух матриц и 
заполняет значениями вручную. Не забывайте, что необходимо выделить соответствующие участки памяти для матриц,
которые будет заполнять пользователь и для третьей итоговой матрицы.
Далее отобразите на экране обе заполненные матрицы и итоговую матрицу (их воспроизведение).*/


int** create_arr(int size);
void swap(int** arr, int size);
void vuvid(int*** arr,int size);
int** mnozhennya(int*** arr1, int*** arr2, int size);
int* create_raw(int**** arr2,int size,int j);
int result(int** raw1, int** raw2,int size);
int main()
{
	//1
	srand(time(NULL));

	int size;

	cout << "size:";
	cin >> size;

	int** arr = create_arr(size);
	vuvid(&(arr), size);
	
	for (int i = 0; i < size; i++)
	{
		swap(&(arr[i]), size);
	}
	cout << "RES" << endl;
	vuvid(&(arr),size);
	
	//2
	
	system("pause");
	system("cls");

	int** arr1 = create_arr(size);
	cout << "MATR1" << endl;
	vuvid(&(arr1), size);


	int** arr2 = create_arr(size);
	cout << "MATR2" << endl;
	vuvid(&(arr2), size);

	int** arr3 = mnozhennya(&(arr1), &(arr2), size);
	cout << "RES"<<endl;
	vuvid(&(arr3), size);
}

int** create_arr(int size)
{
	
	int** arr = new int*[size];
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

void swap(int** arr, int size)
{
	int max = arr[0][0];
	int it = 0;

	for (int i = 0; i < size; i++) {
		if (max < arr[0][i]) { 
			max = arr[0][i]; 
			it = i;
		}
	}

	arr[0][it] = arr[0][0];
	arr[0][0] = max;
}

void vuvid(int*** arr,int size)
{
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			cout << arr[0][i][j] << " ";
		}
		cout << "|" << endl;
	}
}

int** mnozhennya(int*** arr1, int*** arr2, int size)
{
	int** arr = create_arr(size);
	int* raw;
	for (int i = 0; i < size; i++) {
		raw = create_raw(&(arr2), size,i);
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = result(&(arr1[0][j]), &(raw), size);
		}
	}
	return arr;
}

int* create_raw(int**** arr2, int size,int j)
{
	int* raw = new int[size];
	for (int i = 0; i < size; i++) {
		raw[i] = arr2[0][0][i][j];
	}
	return raw;
}

int result(int** raw1, int** raw2, int size)
{
	int res = 0;;
	for (int i = 0; i < size; i++) {
		res += raw1[0][i] * raw2[0][i];
	}
	return res;
}
