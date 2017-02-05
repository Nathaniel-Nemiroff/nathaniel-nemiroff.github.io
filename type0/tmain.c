#include <stdio.h>
#include <stdlib.h>

#include "tclass.c"
#include "ututil.h"

main()
{
	LEFT = true;
	Entity curr = Initialize();
	Entity Room = curr;
	char c;
	int i = 0;
	while(c!=27)
	{
		if(i>-1)
			printf(curr.getFlavor().c_str());
		printf("\n");

		if(curr.isEnd())
		{
			curr = Room;
			//printf(curr.getName().c_str());
			i=-1;
			continue;
		}
		c = getch();
		i = c2i(c);
		curr = curr.getEnt(i);
		printf("\ndebug\n\"%s\"\ndebug\n", curr.getName().c_str());
		if(curr.getName() == "null")
		{
			i = 0;
			curr = Room;
		}
	}
	return 0;
}
