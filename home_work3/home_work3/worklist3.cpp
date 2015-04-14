#include "worklist3.h"
#include <iostream>
#include <stdlib.h>

//FILE *fp;
void node::set_data(int element)
{
	data = element;
}

void node::get_data()
{
	cout << data << " -> ";
}

linklist::linklist()
{
	//exit = 1; count = 0; length = 0; choice = 0; search = 0;
	num = 0; count = 0;
	first = new node;
	first->next = NULL;
}
linklist::~linklist()
{
	while (first != NULL && first->next != NULL)
	{
		//node *q;
		will = new node;
		//delete q->info.team;
		will = first;
		first = first->next;
		delete will;
	}
	cout << "析构函数已调用" << endl;
	cout << "该线性表已删除" << endl;
}
bool linklist::creat(FILE *fp)
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
	int num = 1;
	char s[10];
	int element;
	while ((fgets(s, 10, fp)) != NULL)
	{
		sscanf(s, "%d", &element);
		x = new node;
		x->set_data(element);
		now = first;
		count = 0;
		while (now != NULL && count < num - 1)
		{
			now = now->next;
			count++;
		}
		x->next = now->next;
		now->next = x;
		num++;
	}
	fclose(fp);
	return true;
}

void linklist::inversion()
{
	prev = NULL;
	now = first->next;
	will = now->next;
	while (now != NULL)
	{
		will = now->next;
		now->next = prev;
		prev = now;
		now = will;
	}
	first->next = prev;
}

void linklist::printlist()
{

	now = first->next;
	while (now != NULL)
	{
		now->get_data();
		now = now->next;
	}
}