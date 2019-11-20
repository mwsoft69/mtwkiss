#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mtwkiss.h"

/*KISS PRNG 32-bit.*/
unsigned int Kiss(struct state *s)
{

	unsigned long long t, a = 698769069ULL;

	s->x = 69069*s->x+12345;
	s->y ^= (s->y<<13);
       	s->y ^= (s->y>>17);
       	s->y ^= (s->y<<5);

	t = a*s->z+s->c; 
	s->c = (t>>32);

	//return x+y+(z=t);
	return (s->x+s->y+(s->z+t));

}

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
		


