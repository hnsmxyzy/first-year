#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
const int maxsize = 50;
class data
{
public:
	data(){
		team[0] = NULL; score = 0; rank = 0; win = 0; lose = 0; draw = 0;
	total_kills = 0; total_deaths = 0; total_assists = 0; kda = 0; get_money = 0;}
	~data(){}
	char team[10];
	int score;
	void get_data();
	void set_data(char tem_team[10], int tem_rank, int tem_score, int tem_win, int tem_lose,
		int tem_draw, int tem_total_kills, int tem_total_deaths, int tem_total_assists, float tem_kda, int tem_get_money);
private:
	int rank;
	int win;
	int lose;
	int draw;
	int total_kills;
	int total_deaths;
	int total_assists;
	float kda;
	int get_money;
};

class seqlist
{
public:
	seqlist(){ length = 0; choice = 0; search = 0; exit = 1; }
	seqlist(data arr[], int m, int n, int i);
	~seqlist(){}
	void Length(){ cout << length << endl; }
	void get(int num);
	void locate(int score);
	void insert(int num, data element);
	void Delete(int num);
	void printlist();
	void mainmenu();
	bool exit;
private:
	data arr[maxsize];
	int length;
	int choice;
	int search;
	
};
extern char tem_team[10];
extern int tem_rank;
extern int tem_score;
extern int tem_win;
extern int tem_lose;
extern int tem_draw;
extern int tem_total_kills;
extern int tem_total_deaths;
extern int tem_total_assists;
extern float tem_kda;
extern int tem_get_money;
extern int num;
extern data temp;
extern FILE *fp;
extern char s[120];