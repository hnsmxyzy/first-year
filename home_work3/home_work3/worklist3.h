#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
using namespace std;

struct node
{
	void set_data(int num);
	void get_data();
	int data;
	node *next;
};

class linklist
{
public:
	linklist();
	~linklist();
	bool creat(FILE *fp);
	//void Length();
	//void get(int i);
	//void locate(int x);
	//void insert(int i, node *x);
	//void Delete(int i);
	void inversion();
	void printlist();
	//void mainmenu();
	bool flag;
private:
	node *now;	//工作指针1
	node *will;	//工作指针2
	node *prev;	//工作指针3
	node *x;	//新建节点
	node *first;	//头指针
	int num;
	int count;
};