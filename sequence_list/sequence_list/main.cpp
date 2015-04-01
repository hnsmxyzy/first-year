// sequence_list.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include "sequence_list.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	seqlist lollist;
	data temp;
	FILE *fp = NULL;
	fp = fopen("D:\\projects\\first-year\\sequence_list\\list_data.txt", "r+");
	if (fp == NULL)
	{
		cout << "open error!" << endl;
		return -1;
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
		sscanf(s, "%d%s%d%d%d%d%d%d%d%f%d", &tem_rank, &tem_team, &tem_score,
			&tem_win, &tem_lose, &tem_draw, &tem_total_kills, &tem_total_deaths, &tem_total_assists, &tem_kda, &tem_get_money);
		temp.set_data(tem_team, tem_rank, tem_score, tem_win, tem_lose, tem_draw,
			tem_total_kills, tem_total_deaths, tem_total_assists, tem_kda, tem_get_money);
		lollist.insert(num, temp);
		num++;
	}
	fclose(fp);
	while (lollist.exit)
	{
		lollist.mainmenu();
	}
	return 0;
}