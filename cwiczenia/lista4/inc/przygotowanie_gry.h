#ifndef PRZYGOTOWANIE_POLA_H
#define PRZYGOTOWANIE_POLA_H
#include "zmienne_pomocnicze.h"

/************************************************************************************
* Funkcja wyswietla pole gry (tablice wypelniona liczbami w aktualnym ustawieniu)   *									
* \param[in] *tablica wskaznik na dynamiczna tablice z liczbami                     * 
* \param[out] *tablica nowe ustawienie pola gry  			 	                    *
*************************************************************************************/
void wyswietl(int *tablica);

/************************************************************************************
* Funkcja wypelnia pole gry 							                            *
*									   	                                            *
* \param[in] *tablica wskaznik na dynamiczna tablice          		                * 
* \param[out] *tablica uzupelniona o losowe ustawienie liczb  		 	            *	
*************************************************************************************/
void wypelnij(int *tablica);

/************************************************************************************
* Funkcja sprawdzajaca warunki wygranej						                        *
*									   	                                            *
* \param[in] *tablica wskaznik na dynamiczna tablice          		                * 
* \return wartosc logiczna do oblugi petli w funkcji main  		 	                *	
*************************************************************************************/
int wygrana (int *tablica,char menu[]);

/************************************************************************************
* Funkcja wyswietlajaca menu dostepnych opcji					                    *	
*************************************************************************************/
void menu_glowne();

/************************************************************************************
* Funkcja sprawdzajaca poprawnosc wybranej opcji				                    *
*									   	                                            *
* \param[in] menu[] tablica przechowujaca wybor uzytkownika    		                * 
* \return wartosc logiczna do oblugi funkcji main  		 	                        *	
*************************************************************************************/
_Bool dobry_stan(char menu[]);

#endif
