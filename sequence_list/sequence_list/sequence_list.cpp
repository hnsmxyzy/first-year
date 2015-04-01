
#include "stdafx.h"
#include <iostream>
#include "sequence_list.h"
#include <string.h>
using namespace std;
char tem_team[10];
int tem_rank;
int tem_score;
int tem_win;
int tem_lose;
int tem_draw;
int tem_total_kills;
int tem_total_deaths;
int tem_total_assists;
float tem_kda;
int tem_get_money;
int num;
data temp;
FILE *fp = NULL;
char s[120];
bool flag = 1;
void data::set_data(char tem_team[10], int tem_rank, int tem_score, int tem_win, int tem_lose,
	int tem_draw, int tem_total_kills, int tem_total_deaths, int tem_total_assists, float tem_kda, int tem_get_money)
{
	rank = tem_rank; strcpy_s(team,10,tem_team); score = tem_score; win = tem_win;
	lose = tem_lose; draw = tem_draw; total_kills = tem_total_kills;
	total_deaths = tem_total_deaths; total_assists = tem_total_assists;
	kda = tem_kda; get_money = tem_get_money;
}

void data::get_data()
{
	cout << rank << "\t"<< team << "\t" << score << "\t" << win << "\t"
	<< lose << "\t" << draw << "\t" << total_kills << "\t" <<total_deaths <<
	"\t" << total_assists << "\t" << kda << "\t" << get_money << endl;
}
void seqlist::mainmenu()
{
	system("cls");
	system("mode con cols=112 lines=20");
	cout << "*********************" << endl;
	cout << "*1.查找 " << endl;
	cout << "*                    " << endl;
	cout << "*2.插入	 " << endl;
	cout << "*                    " << endl;
	cout << "*3.删除	 " << endl;
	cout << "*                    " << endl;
	cout << "*4.打印	 " << endl;
	cout << "*                    " << endl;
	cout << "*5.长度 " << endl;
	cout << "*                    " << endl;
	cout << "*6.退出 " << endl;
	cout << "*********************" << endl;
	cout << endl << "请进行选择(1 - 6): ";
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice > 6)
		{
			cout << "输入错误，请重选 1 - 6: ";
			cin.clear();
			cin.sync();
		}
		else
		{
			break;
		}
	}
	switch (choice)
	{
	case 1:
	{
			  cout << ">> 您选择了【1.查找】，请选择查找类型" << endl;
			  cout << ">> 输入1按位查找,输入2按值查找" << endl;
			  while (true)
			  {
				  cin >> search;
				  if (search != 1 && search != 2)
				  {
					  cout << "输入错误，请重新输入: ";
					  cin.clear();
					  cin.sync();
				  }
				  if (search == 1)
				  {
					  cout << "请输入查找位置：" << endl;
					  cin >> num;
					  get(num);
					  system("pause");
					  break;
				  }
				  if (search == 2)
				  {
					  cout << "请输入要查找的积分值" << endl;
					  int k = 0;
					  cin >> k;
					  locate(k);
					  system("pause");
					  break;
				  }
			  }
	}
		break;
	case 2:
	{
			  cout << ">> 您选择了【2.插入】." << endl;
			  cout << "请输入插入位置：" << endl;
			  cin >> num;
			  cout << "请输入插入值：" << endl;
			  cin >> tem_rank >> tem_team >> tem_score >> tem_win >> tem_lose >> tem_draw
				  >> tem_total_kills >> tem_total_deaths >> tem_total_assists >> tem_kda >> tem_get_money;
			  temp.set_data(tem_team, tem_rank, tem_score, tem_win, tem_lose, tem_draw,
				  tem_total_kills, tem_total_deaths, tem_total_assists, tem_kda, tem_get_money);
			  insert(num, temp);
	}
		break;
	case 3:
	{
			  cout << ">> 您选择了【3.删除】." << endl;
			  cout << "请输入删除位置：" << endl;
			  cin >> num;
			  Delete(num);
			  system("pause");
	}
		break;
	case 4:
	{
			  cout << ">> 您选择了【4.打印】" << endl;
			  printlist();
			  system("pause");
	}
		break;
	case 5:
	{
			  cout << ">> 您选择了【5.长度】" << endl;
			  Length();
			  system("pause");
	}
		break;
	case 6:
	{
			  cout << ">> 您选择了【6.退出】" << endl;
			  system("pause");
			  exit = 0;
	}
		break;
	}
	
}

void seqlist::get(int num)
{
	if (num < 1 || num > length)
	{
		cout << "查找位置非法." << endl;
	}
	else
	{
		arr[num - 1].get_data();
	}
}
void seqlist::locate(int score)
{
	bool flag = true;
	for (int i = 0; i < length; i++)
	{
		if (arr[i].score == score)
		{
			arr[i].get_data();
			flag = false;
		}
	}
	if (flag)
	{
		cout << "未找到所输入积分对应的战队信息。" << endl;
	}
}
void seqlist::insert(int num, data element)
{
	if (length >= maxsize)
	{
		cout << "长度超过最大值。" << endl;
	}
	if (num < 1 || num > length + 1)
	{
		cout << "插入位置错误。" << endl;
	}
	for (int j = length; j >= num; j--)
	{
		arr[j] = arr[j - 1];
	}
	arr[num - 1] = element;
	length++;
}

void seqlist::Delete(int num)
{
	if (length == 0)
	{
		cout << "长度小于最小值。" << endl;
	}
	if (num < 1 || num > length)
	{
		cout << "删除位置错误。" << endl;
	}
	arr[num - 1].get_data();
	for (int i = num; i < length; i++)
	{
		arr[i - 1] = arr[i];
	}
	length--;
}

void seqlist::printlist()
{
	fp = fopen("D:\\projects\\first-year\\sequence_list\\list_data.txt", "r+");
	if (fp == NULL)
	{
		cout << "open error!" << endl;
	}
	else
	{
		cout << "open success!" << endl;
	}
	fgets(s, 120, fp);
	cout << s;
	for (int i = 0; i < length; i++)
	{
		arr[i].get_data();
	}
}