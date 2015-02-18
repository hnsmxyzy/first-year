// exercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#define pi 3.14																								//用 pi = 3.14近似代表圆周率。
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0, year = 0;																					//n为数据数量，year为年份。
	cin >> n;
	float *arr_distance = new float[n];																		//动态分配，指定一个长度为n的数组，用于储存每组数据到原点的距离。
	float **arr_coordinate = new float *[n];																//动态分配，指定一个n行，2列的二维数组，用于储存输入的坐标。
	for (int i = 0; i < n; i++)
	{
		arr_coordinate[i] = new float[2];
	}
	for (int i = 0; i < n; i++)																				//坐标输入
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr_coordinate[i][j];
		}
	}
	for (int i = 0; i < n; i++)																				//计算距离并储存。
	{
		arr_distance[i] = sqrt(pow(arr_coordinate[i][0], 2) + pow(arr_coordinate[i][1], 2));
	}
	for (int i = 0; i < n; i++)																				//打印结果。
	{
		for (;; year++)
		{
			double r = 0;
			r = sqrt(100 * year / pi);
			if (r > arr_distance[i])
			{
				break;
			}
		}
		cout << "Property " << i + 1 << ":"
			<< "This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	delete []arr_distance;																					//释放空间并使指针成为空指针。
	arr_distance = NULL;
	for (int i = 0; i < n; i++)
	{
		delete []arr_coordinate[i];
		arr_coordinate[i] = NULL;
	}
	delete []arr_coordinate;
	arr_coordinate = NULL;
	return 0;
}