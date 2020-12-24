#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* strukura zawierajaca dane na temat parametrow obrazu */
typedef struct {
 int wymx,wymy,szarosci;
 int **obraz_pgm;
 int **red, **green, **blue **szarosc;
 char znak;
} s_obraz;

/* strukura operujaca na pliku i jego funkcjach */
typedef struct {
 FILE *plik_we, *plik_wy, *plik_tmp;
 char *nazwa_pliku_we, *nazwa_pliku_wy, *nazwa_pliku_tmp;
 int 
 float s_prog,s_wspolczynnik,s_czern,s_biel;
}s_opcje;

/* prototypy fukncji */
int czytaj(FILE *plik_we, s_obraz *obraz); 
int zapis(FILE *plik_we, s_obraz *obraz); 
void wyswietl(char *n_pliku);
void menu_glowne(void);
_Bool dobry_stan (char *);
int negatyw (s_obraz *obraz);
int progowanie(s_obraz *obraz,float prog);
int polprogowanie_czerni(s_obraz *obraz,float prog);
int polprogowanie_bieli(s_obraz *obraz,float prog);
int korekcja_gamma(s_obraz *obraz,float wspolczynnik);
int zmiana_poziomow(s_obraz *obraz,float czern, float biel);
int konturowanie(s_obraz *obraz); 
int rozmywanie_poziome(s_obraz *obraz);
int rozmywanie_pionowe(s_obraz *obraz);
int rozciaganie(s_obraz *obraz);
int przetwarzaj_opcje(s_obraz *obraz); 



