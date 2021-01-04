#ifndef OPERACJELOKALNE_H
#define OPERACJELOKALNE_H
#include "ZmiennePomocnicze.h"

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu konturowania         *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int konturowanie(int obraz_pgm[][MAX],int *wymx,int *wymy); 

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu rozmycia poziomego   *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int rozmywanie_poziome(int obraz_pgm[][MAX],int *wymx,int *wymy);

/************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu rozmycia pionowego   *
 *										                                                              *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                    *
 * \param[in] wymx szerokosc obrazka						                                    *
 * \param[in] wymy wysokosc obrazka						                                      *   
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                       *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                          *
 ************************************************************************************/
int rozmywanie_pionowe(int obraz_pgm[][MAX],int *wymx,int *wymy);

/*************************************************************************************
 * Funkcja modyfikuje wartosci pikseli w celu uzyskania efektu rozciągania histogramu*
 *										                                                               *
 * \param[in] obraz_pgm tablica przechowujaca wartosci pikseli	                     *
 * \param[in] wymx szerokosc obrazka						                                     *
 * \param[in] wymy wysokosc obrazka						                                       *   
 * \param[in] szarosci liczba odcieni szarosci                                       *
 * \param[out] obraz_pgm tablica z nowymi wartosciami pikseli                        *
 * \return wartosc 'logiczna' dla wejscia petli sterujacej                           *
 ************************************************************************************/
int rozciaganie(int obraz_pgm[][MAX],int *wymx,int *wymy,int *szarosci);

#endif
