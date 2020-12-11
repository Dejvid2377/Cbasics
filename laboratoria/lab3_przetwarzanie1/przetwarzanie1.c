/**********************************************************************************************************
* PROJEKT:  PRZETWARZANIE OBRAZOW CZESC PIERWSZA                                                          *
* AUTOR:    DAWID KREKORA                                                                                 *
* DATA:     10.12.2020                                                                                    *
* OPIS:     Program zawarty w tym pliku sluzy do operowania na obrazach monochromatycznych w formacie PGM.*
*           Zaimplementowane w nim funkcje pozwalaja na przeprowadzenie podstawowych operacji na pikselach* 
*           zapisujac calosc modyfikacji w nowym pliku o wybranej przez uzytkownika nazwie.               *
**********************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024       /* Dlugosc buforow pomocniczych */

/* Prototypy funkcji operujacych na obrazach uzytych w programie */ 
int czytaj(FILE *plik_we,int obraz_pgm[][MAX],int *wymx,int *wymy, int *szarosci); 
int zapis (FILE *plik_wy,int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int negatyw (int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int progowanie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int polprogowanie_czerni(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int polprogowanie_bieli(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int korekcja_gamma(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int zmiana_poziomow(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
int konturowanie(int obraz_pgm[][MAX],int *wymx,int *wymy); 
int rozmywanie_poziome(int obraz_pgm[][MAX],int *wymx,int *wymy);
int rozmywanie_pionowe(int obraz_pgm[][MAX],int *wymx,int *wymy);
int rozciaganie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);
void wyswietl(char *n_pliku);
void menu_glowne(void);
_Bool dobry_stan (char *);

int main() {
 // Zmienne pomocnicze:
 int wymx,wymy,odcieni;        /*do przechwywania parametrow obrazu */
 int obraz[MAX][MAX];          /*do przechowywania wymiarow obrazu */         
 char nazwa[100],nazwa2[100];  /*do przechowywania nazw plikow */
 char menu[2] = " ";           /*do funkcji switch */
 FILE *plik, *plik2;           /*do sprawdzenia uchwytu pliku */
 int odczytano = 0;            /*do okreslania poprawnosci >>*/  
 int zapisano = 0;             /*>> dzialania funkcji czytaj i zapis */ 
 int koniec = 0;               /*do sprawdzenia poprawnosci danych*/

 do {
  printf("Program operujacy na obrazach PGM.\n"); 
   /*sekwencja pobrania danych obrazu wejsciowego */
  printf("Podaj nazwe pliku:\n");
  scanf("%s",nazwa);
  plik=fopen(nazwa,"r");
  odczytano = czytaj(plik,obraz,&wymx,&wymy,&odcieni);
  fclose(plik);
   /* jezeli funkcja odczytano zadzialala prawidlowo wyswietl menu: */
  if (odczytano!=0){
   menu_glowne();
   scanf("%1s", menu);
  /* menu oparte na funkcji switch, przypisanie zmiennej koniec wartosci !=0 
    (jako wartosci zwracanej przy poprawnym wykonaniu funkcji) jest kluczowe 
    dla dalszego dzialania programu */
   switch(menu[0]){
    case 'w': wyswietl(nazwa);
              koniec = 1;
              break;
    case '0': koniec = negatyw(obraz,&wymx,&wymy,&odcieni);
              break;
    case '1': koniec = progowanie(obraz,&wymx,&wymy,&odcieni);
              break;
    case '2': koniec = polprogowanie_czerni(obraz,&wymx,&wymy,&odcieni);
              break;
    case '3': koniec = polprogowanie_bieli(obraz,&wymx,&wymy,&odcieni);
              break;
    case '4': koniec = korekcja_gamma(obraz,&wymx,&wymy,&odcieni);
              break;
    case '5': koniec = zmiana_poziomow(obraz,&wymx,&wymy,&odcieni);
              break;
    case '6': koniec = konturowanie(obraz,&wymx,&wymy);
              break;
    case '7': koniec = rozmywanie_poziome(obraz,&wymx,&wymy);
              break; 
    case '8': koniec = rozmywanie_pionowe(obraz,&wymx,&wymy);
              break; 
    case '9': koniec = rozciaganie(obraz,&wymx,&wymy,&odcieni);
              break; 
    case 'k': printf("Koniec dzialania programu.\n");
              break;
    default:  printf("Nierozpoznane, sprobuj ponownie.\n");  
   }
   /* jezeli wpisano prawidlowe wartosci w etapie menu..sekwencja zapisu do nowego pliku */
   if (dobry_stan(menu) && koniec){
    printf("Podaj nazwe pliku do zapisu: ");
    scanf("%s", nazwa2);
     
    plik2=fopen(nazwa2,"w");
    if (plik2 != NULL){
     zapisano = zapis(plik,obraz,&wymx,&wymy,&odcieni);
     fclose(plik2);  }
   }
  }
 } while (menu[0]!='k' && koniec);
 return zapisano;
}

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
 if ((menu[0]>='0' && menu[0]<='9') || menu[0]=='w');
 else sukces = 0;
 return sukces;
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu negatywu	       	    *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej	                        *
 ************************************************************************************/
int negatyw (int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){
 int i,j;                    /*iteratory tablic                                    */

 for (i=0;i<*wymy;i++) {  /* zmiana wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   obraz_pgm[i][j] = *szarosci-(obraz_pgm[i][j]); 
  }
 }
 return 1;
}

/****************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu progowania      	        *
 * (im wyzszy poziom progu tym wiecej pikseli klasyfikujemy jako punkty koloru czarnego)*
 *                                                                                      *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                        *
 * \param[in] wymx szerokosc obrazka						                                        *
 * \param[in] wymy wysokosc obrazka						                                          *   
 * \param[in] szarosci liczba odcieni szarosci                                          *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                           *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                              *
 ****************************************************************************************/
int progowanie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){                
 int i,j;           /*iteratory tablic                                    */
 float prog;        /*zmienna pomocnicza przy przypisaniu wartosci progu  */     

 printf("Podaj wartosc progu (w %%): ");
 if (scanf("%f", &prog) != 1){  
  fprintf(stderr,"To nie jest liczba. Nie dokonano zadnych zmian.\n");
  return 0; }
 if (prog>100 || prog<0){
  fprintf(stderr,"Bledna wartosc progu. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= (prog/100 * *szarosci))  
    obraz_pgm[i][j] = 0;
   else
    obraz_pgm[i][j] = *szarosci;
  } 
 } 
 return 1; 
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu polprogowania czerni *
 * (wszystkim pikselom ponizej wartosci progu przypisuje wartosc 0)                 *
 *                                                                                  *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int polprogowanie_czerni(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){               
 int i,j;           /*iteratory tablic                                    */
 float prog;        /*zmienna pomocnicza przy przypisaniu wartosci progu  */  

 printf("Podaj wartosc progu (w %%): ");
 if (scanf("%f", &prog) != 1){
  fprintf(stderr,"Błąd. To nie jest liczba. Nie dokonano zadnych zmian.\n");
  return 0; }
 if (prog>100 || prog<0){
  fprintf(stderr,"Bledna wartosc progu. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {    /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= (prog/100 * *szarosci))
    obraz_pgm[i][j] = 0;
   else
    obraz_pgm[i][j] = obraz_pgm[i][j];
  } 
 } 
 return 1; 
}

/*************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu polprogowania bieli   *
 * (wszystkim pikselom powyzej wartosci progu przypisuje maksymalna wartosc szarosci)*
 *                                                                                   *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                     *
 * \param[in] wymx szerokosc obrazka						                                     *
 * \param[in] wymy wysokosc obrazka						                                       *   
 * \param[in] szarosci liczba odcieni szarosci                                       *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                        *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                           *
 *************************************************************************************/
int polprogowanie_bieli(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){               
 int i,j;           /*iteratory tablic                                    */
 float prog;        /*zmienna pomocnicza przy przypisaniu wartosci progu  */  

 printf("Podaj wartosc progu (w %%): ");
 if (scanf("%f", &prog) != 1){
  fprintf(stderr,"Blad. To nie jest liczba. Nie dokonano zadnych zmian.\n");
  return 0; }
 if (prog>100 || prog<0){
  fprintf(stderr,"Blad. Bledna wartosc progu. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= (prog/100 * *szarosci))
    obraz_pgm[i][j] = obraz_pgm[i][j];
   else
    obraz_pgm[i][j] = *szarosci;
  } 
 } 
  return 1; 
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu korekcji gamma       *
 * ()									                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int korekcja_gamma(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci) {              
 int i,j;                  /*iteratory tablic                                    */
 float gamma;              /*zmienna pomocnicza przy przypisaniu wartosci progu  */ 

 printf("Podaj wartosc parametru gamma (wieksze od 0): ");
 if (scanf("%f",&gamma) != 1){
  fprintf(stderr,"Błąd. To nie jest liczba.\n");
  return 0; }
 if (gamma <= 0){
  fprintf(stderr,"Bledna wartosc parametru. Nie dokonano zadnych zmian.\n");
  return 0; }

 for (i=0;i<*wymy;i++) {   /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   obraz_pgm[i][j]= pow(obraz_pgm[i][j],1/gamma) / pow(*szarosci,(1-gamma)/gamma);
  } 
 } 
 return 1;
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania zmiany poziomow             *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci                                      *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int zmiana_poziomow(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci){              
 int i,j;                  /*iteratory tablic                                    */
 float biel,czern;         /*zmienna pomocnicza przy ustalaniu wartosci progow   */
 float prog_czerni, prog_bieli; /* zmienna pomocnicza przy ustalaniu wartosci z ich */
 
 printf("Podaj nowe wartosci dla parametrow czerni i bieli (w %%).\n");
 printf("(Uwaga, pierwszy parametr nie moze miec wiekszej wartosci od drugiego): ");
 
 if (scanf("%f%f",&czern,&biel) != 2){
  fprintf(stderr,"Blad. Bledna wartosc parametrow\n");
  return 0; }
 if (biel-czern<=0){
  fprintf(stderr,"Blad. Parametr czerni nie moze byc wiekszy od bieli\n");
  return 0; }
 if (czern<0 || biel<0 || czern>100 || biel>100){
  fprintf(stderr,"Blad. Wartosci parametrow musza miescic sie w zakresie od 0%% do 100%%\n");
  return 0; }

 prog_bieli = biel/100 * *szarosci;     /* wyznaczanie wartosci progow */
 prog_czerni = czern/100 * *szarosci;

 for (i=0;i<*wymy;i++) {                /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (obraz_pgm[i][j] <= prog_czerni)
    obraz_pgm[i][j] = 0;
   else if (obraz_pgm[i][j]>prog_czerni && obraz_pgm[i][j]<prog_bieli)
    obraz_pgm[i][j] = (obraz_pgm[i][j]-prog_czerni) * *szarosci/(prog_bieli-prog_czerni);
   else if (obraz_pgm[i][j]>=prog_bieli)
    obraz_pgm[i][j] = *szarosci;
  } 
 }
 return 1;
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu konturowania         *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int konturowanie(int obraz_pgm[][MAX],int *wymx,int *wymy){
 int i,j;                  /*iteratory tablic                                    */

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli */
  for (j=0;j<*wymx;j++) {
   if (j==*wymx-1)
    obraz_pgm[i][j]=fabs(obraz_pgm[i+1][j]-obraz_pgm[i][j])+fabs(obraz_pgm[i][j]-obraz_pgm[i][j]);
   else if (i==*wymy-1 && j<*wymx-1)
    obraz_pgm[i][j]=fabs(obraz_pgm[i][j]-obraz_pgm[i][j])+fabs(obraz_pgm[i][j+1]-obraz_pgm[i][j]);
   else
    obraz_pgm[i][j]=fabs(obraz_pgm[i+1][j]-obraz_pgm[i][j])+fabs(obraz_pgm[i][j+1]-obraz_pgm[i][j]);
  }
 }
 return 1;
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu rozmycia poziomego   *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int rozmywanie_poziome(int obraz_pgm[][MAX],int *wymx,int *wymy){
 int i,j;                  /*iteratory tablic                                       */

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli          */
  for (j=0;j<*wymx;j++) {
   if (j==0) /*pierwsza kolumna */
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j]+obraz_pgm[i][j]+obraz_pgm[i+1][j]);
   else if (j==*wymx-1) /*ostatnia kolumna */
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i-1][j]+obraz_pgm[i][j]+obraz_pgm[i][j]);
   else
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i-1][j]+obraz_pgm[i][j]+obraz_pgm[i+1][j]);
  }
 }
 return 1;
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu rozmycia pionowego   *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int rozmywanie_pionowe(int obraz_pgm[][MAX],int *wymx,int *wymy){
 int i,j;                     /*iteratory tablic                                    */

 for (i=0;i<*wymy;i++) {      /*poczatek sekwencji zmiany wartosci pikseli          */
  for (j=0;j<*wymx;j++) {
   if (i==0)
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j]+obraz_pgm[i][j]+obraz_pgm[i][j+1]);
   else if (i==*wymy-1)
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j-1]+obraz_pgm[i][j]+obraz_pgm[i][j]);
   else
    obraz_pgm[i][j]=(1.0/3.0)*(obraz_pgm[i][j-1]+obraz_pgm[i][j]+obraz_pgm[i][j+1]);
  }
 }
 return 1;
}

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu rozmycia pionowego   *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[in] szarosci liczba odcieni szarosci
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int rozciaganie(int obraz_pgm[][MAX],int *wymx, int *wymy, int *szarosci){
 int i,j;                 /*poczatek sekwencji zmiany wartosci pikseli */                  
 int max=0;               /*inicjalizacja wartosci maksymalnej         */
 int min=*szarosci;       /*inicjalizacja wartosci minimalnej          */

 for(i=0;i<*wymy;i++) {     /*sekwencja przeszukiwania tablicy w celu znalezienia */
  for(j=0;j<*wymx;j++) {    /*minimalnej i maksymalnej wartosci pikseli w pliku   */
	 if(obraz_pgm[i][j]>max)  
    max = obraz_pgm[i][j];
	 if(obraz_pgm[i][j]<min)  
    min = obraz_pgm[i][j];
	}
 }
 for(i=0;i<*wymy;i++) {     /*poczatek sekwencji zmiany wartosci pikseli w pliku */
  for(j=0;j<*wymx;j++) {
	 obraz_pgm[i][j]=(obraz_pgm[i][j]-min)*(*szarosci/(max-min));
  }
 }
  return 1;
} 