#include "home_work1.h"
#include <iostream>
using namespace std;

//void data::set_data(int tmp_info)
//{
//	info = tmp_info;
//}

bool seqlist::creat(FILE *fp)
{
	if (fp == NULL)
	{
		cout << "open error!" << endl;
		return false;
	}
	else
	{
		cout << "open success!" << endl;
	}
	int num = 0;
	char s[10];
	int element;
	while ((fgets(s, 10, fp)) != NULL)
	{
		sscanf(s, "%d", &element);
		arr1[num] = element;
		arr2[num] = arr1[num];
		num++;
		length++;
	}
	fclose(fp);
	return true;
}

int seqlist::locate(int info)
{
	int x;				//Î»ÖÃ±äÁ¿
	int low, mid, high;
	if (info > arr1[length - 1])
	{
		x = length;
	}
	else if (info < arr1[0])
	{
		x = 0;
	}
	else
	{
		low = 0;
		high = length - 1;
		mid = (low + high) / 2;
		if (info == arr1[mid])
		{
			x = mid;
		}
		else
		{
			while (low < high)
			{
				if (info > arr1[mid])
				{
					low = mid + 1;
				}
				else if (info < arr1[mid])
				{
					high = mid - 1;
				}
				else
				{
					break;
				}
				mid = (low + high) / 2;
			}
			x = mid;
		}
	}
	return x;
}
void seqlist::insert(int info, int posi)
{
	for (int i = 0; i < posi; i++)
	{
		arr2[i] = arr1[i];
	}
	arr2[posi] = info;
	for (int i = posi + 1; i < length; i++)
	{
		arr2[i] = arr1[i - 1];
	}
	length++;
}

void seqlist::printlist()
{
	int i;
	for (i = 0; i < length; i++)
	{
		cout << arr2[i] << '\t';
		if (i % 5 == 4)
		{
			cout << endl;
		}
	}
}