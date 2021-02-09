#pragma once

#include <iostream>
#include <string>
#include<vector>
#include<ctime>




std::vector<std::vector<int>> create_arr(int size);///
std::vector<int> swap(std::vector<int> arr, int size);///
void vuvid(std::vector<std::vector<int>> arr, int size);///
std::vector<std::vector<int>> mnozhennya(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2, int size);
std::vector<int> create_raw(std::vector<std::vector<int>> arr2, int size, int j);///
int result(std::vector<int> raw1, std::vector<int> raw2, int size);