//��ҵ3�����ı�ڵ㴦�����ַ�����������������С�
/*˼·��ʹ��3��ָ��ֱ𴢴浱ǰ��ǰһ���Լ���һ���ڵ�ָ�롣
��ͷ��㿪ʼ��ÿ�β������µ�ǰ�����ͷ��㣬����ָ��ǰһ���ڵ㡣
����ǰ�ڵ�Ϊ��ʱ��ѭ����ֹ������ͷ��㡣
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
		cout << "ԭ����Ϊ" << endl;
		numlist.printlist();
		cout << endl;
		cout << "���ú������Ϊ" << endl;
		numlist.inversion();
		numlist.printlist();
	}
	return 0;
}