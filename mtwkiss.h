#ifndef MTWKISS_H
#define MTWKISS_H

unsigned int devRand();
unsigned int Kiss(unsigned int xSeed,unsigned int ySeed, unsigned int zSeed, unsigned cSeed);
void initRandSeed (unsigned int *x,unsigned int *y,unsigned int *z,unsigned int *c);

#endif
