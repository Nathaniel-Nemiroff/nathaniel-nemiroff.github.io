#include <string>
#include <string.h>
#include <vector>

using namespace std;

bool LEFT;
int c2i(char c)
{
	if(LEFT)switch(c)
			{
				case 'a':return 0;
				case 's':return 1;
				case 'd':return 2;
				case 'f':return 3;
			}
	else    switch(c)
			{
				case 'j':return 0;
				case 'k':return 1;
				case 'l':return 2;
				case ';':return 3;
			}
	return -1;
}
char i2c(int i)
{
	if(LEFT)switch(i)
			{
				case 0:return 'a';
				case 1:return 's';
				case 2:return 'd';
				case 3:return 'f';
			}
	else 	switch(i)
			{
				case 0:return 'j';
				case 1:return 'k';
				case 2:return 'l';
				case 3:return ';';
			}
	return -1;
}

class Entity
{
	string flavor;
	string name;
	//Entity *entities;
	vector<Entity> entities;
	bool end;
	// Actions?
	public:
	Entity(string Name, string Flavor)
	{
		name = Name;
		flavor = Flavor;
		end = true;
	}
	Entity(string Name, string Flavor, vector<Entity> Entities)
	{
		name = Name;
		flavor = Flavor;
		entities = Entities;
		end = false;
	}
	Entity getEnt(int x)
	{
		if(x < entities.size() && x > -1)
			return entities[x];
		return Entity("null", "null");
	}
	bool isEnd(){return end;}
	string getName(){return name;};
	string getFlavor()
	{
		string retval = "";
		if(strcmp(flavor.c_str(), "null"))//flavor.compare(nullstr)!=0)
		{
			retval += flavor;
			retval += "\n";
		}
		for(int i = 0; i < entities.size();i++)
		{
			retval += i2c(i);
			retval += ": " + entities[i].getName() + "\n";
		}
		return retval;
	}
};

Entity Initialize()
{
	vector<Entity> group;

	Entity aplk = Entity("look", "It's an apple!");
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
	// push_back
	Entity r = Entity("Room", "inna room innit?", group);
	return r;
}
