//��ҵ1��˳�������������⡣
/*˼·����������Ҫ��Ҫ���������ؼ�������
1.����Ҫ���������������ж�Ӧ��λ�á�
2.�����ݲ����Ӧλ�ú�ʣ�����ݶ�Ӧ�ƶ���
���ڲ���1����ʹ���˶��ֲ��ҵ��㷨������λ�ã�ʱ�临�Ӷ�ΪO(log2 n);
���ڲ���2������ѭ����ԭ��������ݿ�������һ�����飬�ڶ�Ӧλ�ò��������ݡ�ʱ�临�Ӷ�ΪO(n);
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
		cout << "ԭ����Ϊ��" << endl;
		numlist.printlist();
		cout << "������������֣�" << endl;
		cin >> info;
		posi = numlist.locate(info);
		numlist.insert(info, posi);
		cout << "����������Ϊ��" << endl;
		numlist.printlist();
	}
	return 0;
}