//#include <conio.h>
//#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "classes.h"

using namespace std;

//void clrscr(){cout << "\033[2J\033[1;1H"}

int main()
{
	LEFT = true;
	Entity curr = Initialize();
	Entity Room = curr;
	bool pause = 0;
	char c = 0;
	int i = 0;

	while (c != 27)
	{
		if (i > -1){
			printf("%s\n", curr.getFlavor().c_str());
			printf("\n");
		}
		if (curr.isEnd())
		{
			//curr = Room;
			i = -2;
			c = getch();// _getch();
			if (c == ' ') {
				curr = Room;
				system("cls");
				//clrscr();
				i = 0;
			}
			continue;
		}
		c = getch();//_getch();
		i = c2i(c);
		curr = curr.getEntity(i);// FIND A WAY TO STOP ROOM FROM REPRINTING
		if (i==-1)//curr.getName() == "null")
		{
			curr = Room;
			//clrscr();
			system("cls");
			i = 0;
		}
		//system("CLS");
	}
	return 0;
}


// START ON SAVE/LOAD
// START ON ADDING/DELETING ENTITES FROM ENTITIES
// ( ROOM FROM ROOM )
// INVENTORY
// USE ITEM ON ITEM
// ADD/REMOVE OR ALTER ITEMS
