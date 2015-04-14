#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <string.h>
#define maxsize  10000
using namespace std;

struct data
{
	//void set_data(int tmp_info);
	int info;
};

class seqlist
{
public:
	seqlist(){ length = 0; }
	seqlist(int arr[],int n);
	~seqlist(){}
	bool creat(FILE *fp);
	int locate(int info);
	void insert(int info, int posi);
	void printlist();
	bool flag;
private:
	int arr1[maxsize], arr2[maxsize];  //1为原数组，2为新数组
	int length;
	//int choice;
	//int search;
};