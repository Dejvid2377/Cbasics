#ifndef OPERACJELOKALNE_H
#define OPERACJELOKALNE_H
#include"ZmiennePomocnicze.h"

int konturowanie(int obraz_pgm[][MAX],int *wymx,int *wymy); 
int rozmywanie_poziome(int obraz_pgm[][MAX],int *wymx,int *wymy);
int rozmywanie_pionowe(int obraz_pgm[][MAX],int *wymx,int *wymy);
int rozciaganie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

#endif
