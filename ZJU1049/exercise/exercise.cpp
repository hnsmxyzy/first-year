// exercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

//�� pi = 3.14���ƴ���Բ���ʡ�

#define pi 3.14																								
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	//nΪ����������yearΪ��ݡ�
	int n = 0, year = 0;																					
	cin >> n;
	//��̬���䣬ָ��һ������Ϊn�����飬���ڴ���ÿ�����ݵ�ԭ��ľ��롣
	float *arr_distance = new float[n];		
	//��̬���䣬ָ��һ��n�У�2�еĶ�ά���飬���ڴ�����������ꡣ
	float **arr_coordinate = new float *[n];																
	for (int i = 0; i < n; i++)
	{
		arr_coordinate[i] = new float[2];
	}
	//��������
	for (int i = 0; i < n; i++)																				
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr_coordinate[i][j];
		}
	}
	//������벢���档
	for (int i = 0; i < n; i++)																				
	{
		arr_distance[i] = sqrt(pow(arr_coordinate[i][0], 2) + pow(arr_coordinate[i][1], 2));
	}
	//��ӡ�����
	for (int i = 0; i < n; i++)																				
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
	//�ͷſռ䲢ʹָ���Ϊ��ָ�롣
	delete []arr_distance;																					
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