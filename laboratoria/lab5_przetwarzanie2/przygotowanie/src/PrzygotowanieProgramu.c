#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"PrzygotowanieProgramu.h"

/************************************************************************************
 * Funkcja wczytuje obraz PGM z pliku do tablicy       	       	       	       	    *
 *										                                                              *
 * \param[in] plik_we uchwyt do pliku z obrazem w formacie PGM			                *
 * \param[out] obraz_pgm tablica, do ktorej zostanie zapisany obraz		              *
 * \param[out] wymx szerokosc obrazka						                                    *
 * \param[out] wymy wysokosc obrazka						                                    *   
 * \param[out] szarosci liczba odcieni szarosci					                            *
 * \return liczba wczytanych pikseli						                                    *
 ************************************************************************************/

int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci) {
  char buf[DL_LINII];     /*bufor pomocniczy do czytania naglowka i komentarzy */ 
  int znak;               /*zmienna pomocnicza do czytania komentarzy          */
  int koniec=0;           /*zmienna oznaczajaca koniec danych w pliku          */                
  int i,j;                /*iteratory tablic                                   */

  /*Sprawdzenie czy podano prawidłowy uchwyt pliku */
  if (plik_we==NULL) {
    fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
    return(0);  }

  /* Sprawdzenie "numeru magicznego" - powinien być P2 */
  if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Wczytanie pierwszej linii pliku do bufora */
    koniec=1;                              /* Nie udalo sie? Koniec danych!             */

  if ( (buf[0]!='P') || (buf[1]!='2') || koniec) {  /* Czy jest magiczne "P2"? */
    fprintf(stderr,"Blad: To nie jest plik PGM\n");
    return(0);  }

  /* Pominiecie komentarzy */
  do {
   if ((znak=fgetc(plik_we))=='#') {          /* Czy linia rozpoczyna sie od znaku '#'? */
    if (fgets(buf,DL_LINII,plik_we)==NULL)   /* Przeczytaj ja do bufora                */
	   koniec=1;  }                             /* Zapamietaj ewentualny koniec danych    */
    else {                                   /* Gdy przeczytany znak z poczatku linii  */
     ungetc(znak,plik_we);  }                 /* nie jest '#' zwroc go                  */
  } while (znak=='#' && !koniec);            /* Powtarzaj dopoki sa linie komentarza   */
                                              /* i nie nastapil koniec danych           */

  /* Pobranie wymiarow obrazu i liczby odcieni szarosci */
  if (fscanf(plik_we,"%d %d %d",wymx,wymy,szarosci)!=3) {
   fprintf(stderr,"Blad: Brak wymiarow obrazu lub liczby stopni szarosci\n");
   return(0);  }

  /* Pobranie obrazu i zapisanie go w tablicy obraz_pgm*/
  for (i=0;i<*wymy;i++) {
   for (j=0;j<*wymx;j++) {
     if (fscanf(plik_we,"%d",&(obraz_pgm[i][j]))!=1) {
	    fprintf(stderr,"Blad: Niewlasciwe wymiary obrazu\n");
	    return(0);  }
    }
  }
  return *wymx**wymy;  /* Czytanie zakonczone sukcesem, zwroc liczbe wczytanych pikseli */
}
/************************************************************************************
 * Funkcja zapisuje obraz PGM do nowego pliku         	       	       	       	    *
 *										                                                              *
 * \param[in] plik_wy uchwyt do wybranego pliku                  		                *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] plik_wy obraz pgm               					                            *
 * \return liczba wczytanych pikseli						                                    *
 ************************************************************************************/
int zapis (FILE *plik_wy,int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){
 int i,j;

/*Sprawdzenie czy podano prawidłowy uchwyt pliku */
 if (plik_wy==NULL) {
  fprintf(stderr,"Blad: Nie podano uchwytu do pliku\n");
  return 0; }
/* sekwencja wpisania parametrow obrazu do pliku */
 fprintf(plik_wy,"P2\n%d %d\n %d\n",*wymx,*wymy,*szarosci);
/* sekwencja kopiowania obrazu piksel po pikselu */
 for (i=0;i<*wymy;i++) {
  for (j=0;j<*wymx;j++) {
   fprintf(plik_wy,"%d ",(obraz_pgm[i][j]));
  }
  fprintf(plik_wy,"\n");
 }
 return *wymx**wymy;
}

/************************************************************************************
 * Funkcja wyswietla rządany obraz poprzez ingerencje w polecenia systemowe    	    *
 *										                                                              *
 * \param[in] n_pliku nazwa pliku ktory chcemy wyswietlic                           * 
 * \param[out] wyswietlony obraz               					                            *
 ************************************************************************************/
void wyswietl(char *n_pliku) {
  char polecenie[DL_LINII];      /* bufor pomocniczy do zestawienia polecenia */

  strcpy(polecenie,"display ");  /* konstrukcja polecenia postaci */
  strcat(polecenie,n_pliku);     /* display "nazwa_pliku" &       */
  strcat(polecenie," &");
  printf("%s\n",polecenie);      /* wydruk kontrolny polecenia */
  system(polecenie);             /* wykonanie polecenia        */
}

/************************************************************************************
 * Funkcja wyswietla dostepne opcje w programie                                     *
 ************************************************************************************/
void menu_glowne(void){
  printf("Menu uzytkownika. Dostepne opcje: \n");
  printf("w - wyswietl\n");
  printf("0 - negatyw\n");
  printf("1 - progowanie\n");
  printf("2 - polprogowanie czerni\n");
  printf("3 - polprogowanie bieli\n");
  printf("4 - korekcja gamma\n");
  printf("5 - zmiana poziomow bieli i czerni\n");
  printf("6 - konturowanie\n");
  printf("7 - rozmywanie poziome\n");
  printf("8 - rozmywanie pionowe\n");
  printf("9 - rozciaganie histogramu\n");
  printf("k - zakoncz program\n");
}

/************************************************************************************
 * Funkcja kontrolujaca poprawnosc wpisanych danych                                 *
 *                                                                                  *
 * \param[in] menu[] wartosc zmiennej char zapisanej w tablicy menu                 *
 * \param[out] wartosc logiczna potrzebna do uruchomienia petli sterujacej          *
 ************************************************************************************/
_Bool dobry_stan (char menu[]){
 _Bool sukces = 1; /*wartosc logiczna informujaca o powodzeniu wykonania funkcji */
 if (menu[0]>='0' && menu[0]<='9');
 else sukces = 0;
 return sukces;
}

