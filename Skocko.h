/*************************************************************************
**                            ~ Autori ~                                **
**                         Kristina Batinic                             **
**                         Danijel Jovanovic                            **
*************************************************************************/


#ifndef SKOCKO_H_INCLUDED
#define SKOCKO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

static char moguce[6] = {'T', 'K', 'H', 'P', 'Z', 'S'};
static char generisano[4] = {'N', 'N', 'N', 'N'}; // nije generisano

void meni();
char *generisiKombinaciju();
void pogadjanjeKombinacije(char *);

#endif // SKOCKO_H_INCLUDED
