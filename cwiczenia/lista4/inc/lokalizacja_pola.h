#ifndef LOKAZLIZACJA_POLA_H
#define LOKAZLIZACJA_POLA_H
#include "zmienne_pomocnicze.h"

/************************************************************************************
* Funkcja wylicza wspolrzedne pola na podstawie indeksu tablicy                     *
* \param[in] indeks numer indeksu tablicy z liczbami                                * 
* \return wspolrzedne pola na ktorym znajduje sie liczba	 	                    *
*************************************************************************************/
wspolrzedne z1d_n2d (int indeks);

/************************************************************************************
* Funkcja wylicza numer indeksu tablicy na podstawie wspolrzednych pola             *
* \param[in] pole wspolrzedne pola na ktorym znajduje sie wybrana liczba            * 
* \return numer indeksu w ktorym znajduje sie szukana liczba	                    *
*************************************************************************************/
int z2d_n1d (wspolrzedne pole);

/************************************************************************************
* Funkcja wylicza numer indeksu w ktorym znajduje sie puste pole                    *
* \param[in] *tablica wskaznik na dynamiczna tablice                                * 
* \return numer indeksu w ktorym znajduje sie szukana liczba	                    *
*************************************************************************************/
int znajdz_puste(int *tablica);

/************************************************************************************
* Funkcja zamienia wartosci dwoch pol w tablicy                                     *
* \param[in] *tablica wskaznik na dynamiczna tablice                                *
* \param[in] indeks_przed indeks liczby przed zamiana                               *
* \param[in] indeks_po indeks liczby po zamianie                                    * 
*************************************************************************************/
void zamien(int *tablica,int indeks_przed,int indeks_po);


/************************************************************************************
* Funkcja ustala poprawnosc wskazanego ruchu i nowe polozenie wolnego pola          *
* \param[in] puste wspolrzedne pustego pola                                         *
* \param[in] kierunek tablica przechowujaca informacje o wyborze ruchu              *
* \return nowe polozenie pustego pola                                               * 
*************************************************************************************/
wspolrzedne ruch (wspolrzedne puste, char kierunek[]);

/************************************************************************************
* Funkcja w losowy sposob wykonuje ruch mieszajac ustawienie poczatkowe             *
*									   	                                            *
* \param[in] indeks - indeks pustego pola w tablicy                                 * 
* \param[in] puste - wspolrzedne pustego pola               		                *
* \param[in] *tablica  wskaznik na tablice liczba                                   *
* \return wartosc logiczna do oblugi funkcji main  		 	                        *	
*************************************************************************************/
void pomieszaj (int indeks,wspolrzedne puste,int *tablica);

#endif