//作业1：顺序表有序插入问题。
/*思路：该问题主要需要进行两个关键操作：
1.查找要插入数据在数组中对应的位置。
2.将数据插入对应位置后，剩余数据对应移动。
对于操作1，我使用了二分查找的算法来查找位置，时间复杂度为O(log2 n);
对于操作2，我用循环将原数组的数据拷贝至另一个数组，在对应位置插入新数据。时间复杂度为O(n);
*/
#include "home_work1.h"
#include <iostream>
using namespace std;

int main()
{
	seqlist numlist;
	FILE *fp = NULL;
	int info, posi;
	fp = fopen("D:\\projects\\first-year\\home_work1\\worklist1.txt", "r+");
	numlist.flag = numlist.creat(fp);
	if (numlist.flag)
	{
		cout << "原数组为：" << endl;
		numlist.printlist();
		cout << "请输入插入数字：" << endl;
		cin >> info;
		posi = numlist.locate(info);
		numlist.insert(info, posi);
		cout << "插入后的数组为：" << endl;
		numlist.printlist();
	}
	return 0;
}