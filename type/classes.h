//#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

bool LEFT;
int c2i(char c)
{
	if (LEFT)switch (c)
	{
	case 'a':return 0;
	case 's':return 1;
	case 'd':return 2;
	case 'f':return 3;
	}
	else    switch (c)
	{
	case 'j':return 0;
	case 'k':return 1;
	case 'l':return 2;
	case ';':return 3;
	}
	if (c == ' ')
		return -1;
	return -2;
}
char i2c(int i)
{
	if (LEFT)switch (i)
	{
	case 0:return 'a';
	case 1:return 's';
	case 2:return 'd';
	case 3:return 'f';
	}
	else    switch (i)
	{
	case 0:return 'j';
	case 1:return 'k';
	case 2:return 'l';
	case 3:return ';';
	}
	if (i == -1)
		return ' ';
	return -2;
}

void Action(int flag)
{
	// to do: stuff
	//food:eat->delete item and fill stat
	//take item->delete item from parent, put it in inventory
	//drop item->delete item from inventory, put it in current room
	//use item on item->delete that item and put another item in
		//->delete this item, put another item in it's parent
	//events->go either immediately or after a bit to another entity
		//->allow for change part way through


}

class Entity
{
	string Name;
	string Flavor;
	vector<Entity> Entities;
	Entity *DefaultEnt;
	//int NumEnt;
	//Entity *Entities;
	bool end;

public:
	Entity() {}
	Entity(string name, string flavor)
	{
		Name = name;
		Flavor = flavor;
		end = true;
	}
	Entity(string name, string flavor, vector<Entity>entities)
	{
		Name = name;
		Flavor = flavor;
		Entities = entities;
		//Entities = entities;
		end = true;
		if (entities.size() > 0)
			end = false;
	}
	Entity getEntity(int x)
	{
		if (x < Entities.size())
			return Entities[x];
		// Entity retval = Entity("null", "null");
		//retval.end = false;
		return *this;// retval;
	}
	bool isEnd() { return end; }
	string getName() { return Name; }
	string getFlavor()
	{
		int j;
		string retval = "";
		if (Flavor != "null")
		{
			retval += Flavor;
			retval += "\n";
		}
		for (int i = 0; i < Entities.size(); i++)
		{
			retval += i2c(i);
			retval += ": " + Entities[i].getName() + "\n";
		}
		return retval;
	}
};
Entity Initialize()
{
	vector<Entity> group;

	Entity aplk = Entity("look", "it's an apple!");
	Entity apet = Entity("eat", "you eat the apple!");
	group.push_back(aplk);
	group.push_back(apet);
	Entity a = Entity("apple", "null", group);
	group.clear();

	Entity rklk = Entity("stare", "It's a rock!");
	Entity rket = Entity("bite", "You can't eat a rock!");
	group.push_back(rklk);
	group.push_back(rket);
	Entity b = Entity("rock", "null", group);
	group.clear();

	group.push_back(a);
	group.push_back(b);

	Entity r = Entity("Room", "inna room innit?", group);
	return r;
}