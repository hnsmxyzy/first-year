#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
using namespace std;
struct data
{
	data();
	~data();
	void data::set_data(int tmp_rank, char *tmp_team, int tmp_score, int tmp_win, int tmp_lose, int tmp_draw,
		int tmp_total_kills, int tmp_total_deaths, int tmp_total_assists, float tmp_kda, int tmp_get_money);
	void get_data();
	char *team;
	int rank;
	int score;
	int win;
	int lose;
	int draw;
	int total_kills;
	int total_deaths;
	int total_assists;
	float kda;
	int get_money;
};

struct node
{
	void copy(data *temp, data *info);
	data info;
	node *next;
};

class linklist
{
public:
	linklist();
	~linklist();
	bool creat(FILE *fp);
	void Length();
	void get(int i);
	void locate(int x);
	void insert(int i, node *x);
	void Delete(int i);
	void printlist();
	void mainmenu();
	bool exit;
private:
	node *p;
	node *x;
	node *first;
	//node *end;
	int count;
	int length;
	int choice;
	int search;
};