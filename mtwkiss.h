#ifndef MTWKISS_H
#define MTWKISS_H

struct state{
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int c;

};


unsigned int devRand();
unsigned int Kiss(struct state *s);

#endif
