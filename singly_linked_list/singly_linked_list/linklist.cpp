#include "link_list.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int tmp_rank;
int tmp_score;
int tmp_win;
int tmp_lose;
int tmp_draw;
int tmp_total_kills;
int tmp_total_deaths;
int tmp_total_assists;
float tmp_kda;
int tmp_get_money;
int num;
data temp;
FILE *fp;
char s[120];
void data::set_data(int tmp_rank, char *tmp_team, int tmp_score, int tmp_win, int tmp_lose, int tmp_draw,
	int tmp_total_kills, int tmp_total_deaths, int tmp_total_assists, float tmp_kda, int tmp_get_money)
{
	rank = tmp_rank; strcpy(team, tmp_team); score = tmp_score; win = tmp_win;
	lose = tmp_lose; draw = tmp_draw; total_kills = tmp_total_kills;
	total_deaths = tmp_total_deaths; total_assists = tmp_total_assists;
	kda = tmp_kda; get_money = tmp_get_money;
}

void data::get_data()
{
	cout << rank << "\t" << team << "\t" << score << "\t" << win << "\t"
		<< lose << "\t" << draw << "\t" << total_kills << "\t" << total_deaths <<
		"\t" << total_assists << "\t" << kda << "\t" << get_money << endl;
}
void node::copy(data *temp, data *info)
{
	info->rank = temp->rank;
	strcpy(info->team, temp->team);
	info->score = temp->score;
	info->win = temp->win;
	info->lose = temp->lose;
	info->draw = temp->draw;
	info->total_kills = temp->total_kills;
	info->total_deaths = temp->total_deaths;
	info->total_assists = temp->total_assists;
	info->kda = temp->kda;
	info->get_money = temp->get_money;
}
void linklist::mainmenu()
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
					  cout << "������Ҫ���ҵĻ���:" << endl;
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
			  char *tmp_team;
			  tmp_team = new char[10];
			  cin >> tmp_rank >> tmp_team >> tmp_score >> tmp_win >> tmp_lose >> tmp_draw
				  >> tmp_total_kills >> tmp_total_deaths >> tmp_total_assists >> tmp_kda >> tmp_get_money;
			  temp.set_data(tmp_rank, tmp_team, tmp_score, tmp_win, tmp_lose, tmp_draw,
				  tmp_total_kills, tmp_total_deaths, tmp_total_assists, tmp_kda, tmp_get_money);
			  x = new node;
			  x->info = temp;
			  insert(num, x);
			  delete tmp_team;
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
data::data()
{
	team = new char[10];
}
data::~data()
{
	delete[] team;
}
linklist::linklist()
{
	exit = 1; count = 0; length = 0; choice = 0; search = 0;
	first = new node;
	first->next = NULL;
}
linklist::~linklist()
{
	while (first != NULL)
	{
		node *q;
		//q = new node;
		//delete q->info.team;
		q = first;
		first = first->next;
		delete q;
	}
	cout << "���������ѵ���" << endl;
	cout << "�����Ա���ɾ��" << endl;
}
bool linklist::creat(FILE *fp)
{
	if (fp == NULL)
	{
		cout << "open error!" << endl;
		exit = false;
		return false;
	}
	else
	{
		cout << "open success!" << endl;
	}
	int num = 1;
	char s[120];
	fgets(s, 120, fp);
	while ((fgets(s, 120, fp)) != NULL)
	{
		char *tmp_team;
		tmp_team = new char[10];
		sscanf(s, "%d%s%d%d%d%d%d%d%d%f%d", &tmp_rank, tmp_team, &tmp_score,
			&tmp_win, &tmp_lose, &tmp_draw, &tmp_total_kills, &tmp_total_deaths, &tmp_total_assists, &tmp_kda, &tmp_get_money);
		temp.set_data(tmp_rank, tmp_team, tmp_score, tmp_win, tmp_lose, tmp_draw,
			tmp_total_kills, tmp_total_deaths, tmp_total_assists, tmp_kda, tmp_get_money);
		x = new node;
		x->copy(&temp, &x->info);
		p = first;
		count = 0;
		while (p != NULL && count < num - 1)
		{
			p = p->next;
			count++;
		}
		x->next = p->next;
		p->next = x;
		num++;
		delete tmp_team;
	}
	fclose(fp);
	return true;
}
void linklist::get(int num)
{
	p = first->next;
	count = 1;
	while (p != NULL && count < num)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		cout << "����λ�÷Ƿ���" << endl;
	}
	else
	{
		p->info.get_data();
	}
}
void linklist::locate(int score)
{
	bool flag = true;
	p = first->next;
	count = 1;
	for (int i = 0; i < length; i++)
	{
		if (p->info.score == score)
		{
			p->info.get_data();
			flag = false;
		}
	}
	if (flag)
	{
		cout << "δ�ҵ���������ֶ�Ӧ��ս����Ϣ��" << endl;
	}
}
void linklist::insert(int num, node *x)
{
	p = first;
	count = 0;
	while (p != NULL && count < num - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		cout << "����λ���쳣" << endl;
	}
	else
	{
		x->next = p->next;
		p->next = x;
	}
}

void linklist::Delete(int num)
{
	p = first;
	count = 0;
	while (p != NULL && count < num - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)
	{
		cout << "ɾ��λ�ô���" << endl;
	}
	else
	{
		node *q;
		//q = new node;
		q = p->next; 
		p->next = q->next;
		q->info.get_data();
		delete q;
	}
}

void linklist::printlist()
{
	fp = fopen("D:\\projects\\first-year\\singly_linked_list\\list_data.txt", "r+");
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
	p = first->next;
	while (p != NULL)
	{
		p->info.get_data();
		p = p->next;
	}
}

void linklist::Length()
{
	p = first->next;
	count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	cout << "�õ�����ĳ���Ϊ��" << count << endl;
}