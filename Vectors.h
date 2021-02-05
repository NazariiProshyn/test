#pragma once

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