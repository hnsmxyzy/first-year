//作业3，不改变节点处储存地址，将单链表逆序排列。
/*思路：使用3个指针分别储存当前，前一个以及后一个节点指针。
从头结点开始，每次操作断下当前链表的头结点，将其指向前一个节点。
当当前节点为空时，循环终止，加上头结点。
*/
#include "worklist3.h"
#include <iostream>
using namespace std;

int main()
{
	linklist numlist;
	FILE *fp = NULL;
	fp = fopen("D:\\projects\\first-year\\home_work3\\worklist3.txt", "r+");
	numlist.flag = numlist.creat(fp);
	if (numlist.flag)
	{
		cout << "原链表为" << endl;
		numlist.printlist();
		cout << endl;
		cout << "逆置后的链表为" << endl;
		numlist.inversion();
		numlist.printlist();
	}
	return 0;
}