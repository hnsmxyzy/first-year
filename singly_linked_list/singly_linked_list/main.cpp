#include "link_list.h"
#include <iostream>
using namespace std;

int main()
{
	linklist lollist;
	FILE *fp = NULL;
	fp = fopen("D:\\projects\\first-year\\singly_linked_list\\list_data.txt", "r+");
	lollist.creat(fp);
	while (lollist.exit)
	{
		lollist.mainmenu();
	}
	return 0;
}