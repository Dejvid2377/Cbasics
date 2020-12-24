#ifndef ZMIENNEPOMOCNICZE_H
#define ZMIENNEPOMOCNICZE_H
#define MAX 1024            /* Maksymalny rozmiar wczytywanego obrazu */
#define DL_LINII 1024       /* Dlugosc buforow pomocniczych */

// Zmienne pomocnicze:
 int wymx,wymy,odcieni;        /*do przechwywania parametrow obrazu */
 int obraz[MAX][MAX];          /*do przechowywania wymiarow obrazu */         
 char nazwa[100],nazwa2[100];  /*do przechowywania nazw plikow */
 char menu[2] = " ";           /*do funkcji switch */
 FILE *plik, *plik2;           /*do sprawdzenia uchwytu pliku */
 int odczytano = 0;            /*do okreslania poprawnosci >>*/  
 int zapisano = 0;             /*>> dzialania funkcji czytaj i zapis */ 
 int koniec = 0;               /*do sprawdzenia poprawnosci danych*/
#endif
 


