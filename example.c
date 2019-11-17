#include "mtwkiss.h"
#include <stdio.h>

int main()
{
	
	/*These values could be any unsigned int  or set with initRandSeed() */
	unsigned int x=0,y=0,z=0,c=0;



	for(int i = 0;i<10;i++)
	{	
		/*This example uses initRandSeed()*/
		initRandSeed(&c,&y,&z,&c);
		unsigned int randNum = Kiss(x,y,z,c);
		printf("random number is %d\n",randNum);

	}

	return 0;
}
