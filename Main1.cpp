// CMakeProject1.cpp : Defines the entry point for the application.
//


#include <iostream>
#include <string>
#include<vector>
#include<ctime>

using namespace std;


vector<vector<int>> create_arr(int size);///
vector<int> swap(vector<int> arr, int size);///
void vuvid(vector<vector<int>> arr, int size);///
vector<vector<int>> mnozhennya(vector<vector<int>> arr1, vector<vector<int>> arr2, int size);
vector<int> create_raw(vector<vector<int>> arr2, int size, int j);///
int result(vector<int> raw1, vector<int> raw2, int size);
int main()
{
	//1
	srand(time(NULL));

	int size;

	cout << "size:";
	cin >> size;

	vector<vector<int>> arr = create_arr(size);
	vuvid(arr, size);

	for (int i = 0; i < size; i++)
	{
		arr[i]= swap(arr[i], size);
	}
	cout << "RES" << endl;
	vuvid(arr, size);

	//2

	system("pause");
	system("cls");

	vector<vector<int>> arr1 = create_arr(size);
	cout << "MATR1" << endl;
	vuvid(arr1, size);


	vector<vector<int>> arr2 = create_arr(size);
	cout << "MATR2" << endl;
	vuvid(arr2, size);

	vector<vector<int>> arr3 = mnozhennya(arr1, arr2, size);
	cout << "RES" << endl;
	vuvid(arr3, size);
}



vector<vector<int>> create_arr(int size)
{

	vector<vector<int>> arr(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i].push_back(rand() % 90 + 10);
		}
	}

	return arr;
}






vector<int> swap(vector<int> arr, int size)
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
	return arr;
}



void vuvid(vector<vector<int>> arr, int size)
{
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "|" << endl;
	}
}

vector<vector<int>> mnozhennya(vector<vector<int>> arr1, vector<vector<int>> arr2, int size)
{
	vector<vector<int>> arr = create_arr(size);
	vector<int> raw;
	for (int i = 0; i < size; i++) {
		raw = create_raw(arr2, size, i);
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = result(arr1[j], raw, size);
		}
	}
	return arr;
}




vector<int> create_raw(vector<vector<int>> arr2, int size, int j)
{
	vector<int>  raw;
	for (int i = 0; i < size; i++) {
		raw.push_back(arr2[i][j]);
	}
	return raw;
}

int result(vector<int> raw1, vector<int> raw2, int size)
{
	int res = 0;;
	for (int i = 0; i < size; i++) {
		res += raw1[i] * raw2[i];
	}
	return res;
}
