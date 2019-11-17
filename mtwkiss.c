#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#include "mtwkiss.h"

/*KISS PRNG.*/
unsigned int Kiss(unsigned int xSeed,unsigned int ySeed,unsigned int zSeed,unsigned int cSeed)
{
	unsigned int x = xSeed ,y = ySeed ,z = zSeed , c = cSeed;
	unsigned long long t, a = 698769069ULL;

	x = 69069*x+12345;
	y ^= (y<<13); y ^= (y>>17); y ^= (y<<5);
	t = a*z+c; c = (t>>32);

	return x+y+(z=t);

}

/*Opens and reads 4 bytes from /dev/urandom.*/
unsigned int devRand()
{

	int fn;
	unsigned int r;

	fn = open("/dev/urandom",O_RDONLY);
	if(fn == -1)
	{
		exit(-1);
	}

	if (read(fn,&r,4) != 4)
	{
		exit(-1);
	}

	close(fn);

	return r;
}
			
		
/*Inits the seeds with devRand().*/
void initRandSeed(unsigned int *x,unsigned int *y,unsigned int *z,unsigned int *c)
{
	*x = devRand();
	while(!((*y) = devRand()));
	*z = devRand();
	*c = devRand() % 698769068 +1;
}
