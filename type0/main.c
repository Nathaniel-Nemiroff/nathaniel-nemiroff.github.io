#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "ututil.h" // unix type utility
#include "typeclass.h"

main()
{
	//Text t0 = Text("blah");
	//Text t1 = Text("words");
	//Text t2 = Text("much");

	//Text queue[10];
	//Text Dflt = Text("default");
	//Text current = Dflt;

	string appleActions[4];
	appleActions[0]="Look";
	appleActions[1]="Eat";
	appleActions[2]="throw";
	appleActions[3]="null";
	string batActions[4];
	batActions[0] = "look";
	batActions[1] = "eat";
	batActions[2] = "throw";
	batActions[3] = "hit";
	string thingActions[4];
	thingActions[0] = "look";
	thingActions[1] = "hit";
	thingActions[2] = "null";
	thingActions[3] = "null";
	string astuffActions[4];
	astuffActions[0] = "desecrate";
	astuffActions[1] = "null";
	astuffActions[2] = "null";
	astuffActions[3] = "null";

	Item ITEMS[4];
	ITEMS[0] = Item("Apple", appleActions);
	ITEMS[1] = Item("bat", batActions);
	ITEMS[2] = Item("thing", thingActions);
	ITEMS[3] = Item("a Stuff", astuffActions);

	Room currRoom = Room("A ROOM", 4, ITEMS);
	Entity currEnt = currRoom;

	char buf = 0;
	while(true)
	{
		//printf("Current string: %s (%c)\n", current.Data().c_str(), buf);
		printf("%s\n", currEnt.Data().c_str());
		currEnt.printStuff();
		buf = getch();
		switch(buf)
		{
			case 'a':
				currEnt = currEnt.getEntity(0);
				break;
			case 's':
				currEnt = currEnt.getEntity(1);
				break;
			case 'd':
				currEnt = currEnt.getEntity(2);
				break;
			default:
				currEnt = currEnt.getEntity(3);
				break;
		}
		if(currEnt.Data() == "null")
			currEnt = currRoom;
	}
}
