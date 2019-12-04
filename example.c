#include <stdio.h>
#include <stdlib.h>
#include "mtwkiss.h"

int main()
{
	
	struct state *s;
	s = malloc(sizeof(struct state));

	unsigned int randNum = s;

	printf("random number is %d\n",randNum);

	/*Free struct memory.*/
	free(s);
	
	return 0;
}
