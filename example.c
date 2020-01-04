#include <stdio.h>
#include <stdlib.h>
#include "mtwkiss.h"

int main()
{
	
	struct state *s;
	s = malloc(sizeof(struct state));
	
	/*set seeds using devRand(). You can also define your own seeds.*/
	s->x = devRand();
	s->y = devRand();
	s->z = devRand();
	s->c = devRand();
		
	unsigned int randNum = Kiss(s);

	printf("random number is %d\n",randNum);

	/*Free struct memory.*/
	free(s);
	
	return 0;
}
