#ifndef PRZYGOTOWANIEPROGRAMU_H
#define PRZYGOTOWANIEPROGRAMU_H
#include"ZmiennePomocnicze.h"

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci); 
int zapis (FILE *plik_wy,int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
void wyswietl(char *n_pliku);
void menu_glowne(void);
_Bool dobry_stan (char *);

#endif
