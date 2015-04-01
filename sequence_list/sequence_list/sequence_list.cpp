
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
	cout << "*1.���� " << endl;
	cout << "*                    " << endl;
	cout << "*2.����	 " << endl;
	cout << "*                    " << endl;
	cout << "*3.ɾ��	 " << endl;
	cout << "*                    " << endl;
	cout << "*4.��ӡ	 " << endl;
	cout << "*                    " << endl;
	cout << "*5.���� " << endl;
	cout << "*                    " << endl;
	cout << "*6.�˳� " << endl;
	cout << "*********************" << endl;
	cout << endl << "�����ѡ��(1 - 6): ";
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice > 6)
		{
			cout << "�����������ѡ 1 - 6: ";
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
			  cout << ">> ��ѡ���ˡ�1.���ҡ�����ѡ���������" << endl;
			  cout << ">> ����1��λ����,����2��ֵ����" << endl;
			  while (true)
			  {
				  cin >> search;
				  if (search != 1 && search != 2)
				  {
					  cout << "�����������������: ";
					  cin.clear();
					  cin.sync();
				  }
				  if (search == 1)
				  {
					  cout << "���������λ�ã�" << endl;
					  cin >> num;
					  get(num);
					  system("pause");
					  break;
				  }
				  if (search == 2)
				  {
					  cout << "������Ҫ���ҵĻ���ֵ" << endl;
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
			  cout << ">> ��ѡ���ˡ�2.���롿." << endl;
			  cout << "���������λ�ã�" << endl;
			  cin >> num;
			  cout << "���������ֵ��" << endl;
			  cin >> tem_rank >> tem_team >> tem_score >> tem_win >> tem_lose >> tem_draw
				  >> tem_total_kills >> tem_total_deaths >> tem_total_assists >> tem_kda >> tem_get_money;
			  temp.set_data(tem_team, tem_rank, tem_score, tem_win, tem_lose, tem_draw,
				  tem_total_kills, tem_total_deaths, tem_total_assists, tem_kda, tem_get_money);
			  insert(num, temp);
	}
		break;
	case 3:
	{
			  cout << ">> ��ѡ���ˡ�3.ɾ����." << endl;
			  cout << "������ɾ��λ�ã�" << endl;
			  cin >> num;
			  Delete(num);
			  system("pause");
	}
		break;
	case 4:
	{
			  cout << ">> ��ѡ���ˡ�4.��ӡ��" << endl;
			  printlist();
			  system("pause");
	}
		break;
	case 5:
	{
			  cout << ">> ��ѡ���ˡ�5.���ȡ�" << endl;
			  Length();
			  system("pause");
	}
		break;
	case 6:
	{
			  cout << ">> ��ѡ���ˡ�6.�˳���" << endl;
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
		cout << "����λ�÷Ƿ�." << endl;
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
		cout << "δ�ҵ���������ֶ�Ӧ��ս����Ϣ��" << endl;
	}
}
void seqlist::insert(int num, data element)
{
	if (length >= maxsize)
	{
		cout << "���ȳ������ֵ��" << endl;
	}
	if (num < 1 || num > length + 1)
	{
		cout << "����λ�ô���" << endl;
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
		cout << "����С����Сֵ��" << endl;
	}
	if (num < 1 || num > length)
	{
		cout << "ɾ��λ�ô���" << endl;
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