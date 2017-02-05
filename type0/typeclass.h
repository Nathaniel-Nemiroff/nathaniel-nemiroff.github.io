#include <string>
#include <string.h>

using namespace std;

class Text
{
	string data;
	public:
	Text()
	{
		data = "null";
	}
	Text(string DATA)
	{
		data = DATA;
	}
	string Data(){return data;}
};
class Entity
{
	Text text;
	public:
	Entity(){}
	Entity(string DATA)
	{
		text = Text(DATA);
	}
	string Data(){return text.Data();}
	void printStuff(){printf("nothing to see here\n");}
	Entity getEntity(int x){return Entity("null");}
	// is there a reason to have entity be it's own thing?
};
class Event:public Entity
{
	// func to do stuff
	//		move items
	//		move rooms
	//		change items
	//		change player status
	//		etc
};
class Item:public Entity
{
	Entity actions[4];
	public:
	Item(){}
	Item(string DATA, string ACTIONS[4]):Entity(DATA)
	{
		actions[0] = Entity(ACTIONS[0]);
		actions[1] = Entity(ACTIONS[1]);
		actions[2] = Entity(ACTIONS[2]);
		actions[3] = Entity(ACTIONS[3]);
	}
	void printStuff()
	{
		char button = 'a';
		char *act;
		for(int i = 0; i < 4; i++)
		{
			if(actions[i].Data()!="null")
			{
				printf("%c: %s\n", button, actions[i].Data().c_str());
				switch(button)
				{
					case 'a':
						button = 's';
						break;
					case 's':
						button = 'd';
						break;
					case 'd':
						button = 'f';
						break;
					default:
						break;
				}
			}
		}
	}
	//@override
	virtual Entity getEntity(int x){return actions[x];}
	// events
};
class Room:public Entity
{
	// items
	int NumItems=0;
	Item *items;
	public:
	Room(string DATA, int numitems, Item *ITEMS):Entity(DATA)
	{
		NumItems = numitems;
		items = new Item[numitems];
		for(int i = 0; i < NumItems; i++)
			items[i] = ITEMS[i];
	}
	void printStuff()
	{
		char button = 'a';
		for(int i = 0; i<NumItems;i++)
		{
				printf("%c: %s\n", button, items[i].Data().c_str());//actions[i].c_str());
				switch(button)
				{
					case 'a':
						button = 's';
						break;
					case 's':
						button = 'd';
						break;
					case 'd':
						button = 'f';
						break;
					default:
						break;
				}
			}
	}
	Entity getEntity(int x){return items[x];}
	// events (for change rooms)
	// rooms
};
class Character:public Entity
{
	// status
	// items
	// events
};
class Player:Character
{
	// no events
	// inventory
};

void doEvent(Event ev)
{
	//switch statement
	if(false)// move item
	{
		// if item exists in x place
			// if current room is x
				// move item to room x
	}
	if(false)// move room
	{
		// if currroom has x room
			// curr room = x room
	}
	if(false)// change item
	{
		// if item x exists
			// remove x and insert y
	}
	if(false)// change status
	{
		// if character is in eventroom or eventroom=null
			// char.status+/- x
	}
	if(false)// etc
	{
		// iunno, stuff
	}
}


