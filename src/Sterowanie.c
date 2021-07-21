/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#define _CRT_NONSTDC_NO_WARNINGS
#include "Sterowanie.h"
#include <stdio.h>
#include <conio.h>

#define GORA  296
#define DOL   304
#define LEWO  299
#define PRAWO 301

/**
 * Funkcja odpowiada za ustawienie klawiszy steruj�cych.
 *
 * @param int* kierunek: warto��, kt�ra odpowiada za kierunek poruszania si� w�a.
 */
void ustawienia_sterowania(int* kierunek)
{
    int klawisz;

    if (kbhit())
    {
        klawisz = getch();

        if (klawisz == 224)
        {
            klawisz += getch();
        }

        if (klawisz == GORA && (*kierunek == LEWO || *kierunek == PRAWO))
        {
            *kierunek = GORA;
        }
        if (klawisz == DOL && (*kierunek == LEWO || *kierunek == PRAWO))
        {
            *kierunek = DOL;
        }
        if (klawisz == LEWO && (*kierunek == GORA || *kierunek == DOL))
        {
            *kierunek = LEWO;
        }
        if (klawisz == PRAWO && (*kierunek == GORA || *kierunek == DOL))
        {
            *kierunek = PRAWO;
        }
    }
}

/**
 * Funkcja realizuj�ca ruch w�a w poszczeg�lnym kierunku.
 *
 * @param int* kierunek: warto��, kt�ra odpowiada za kierunek poruszania si� w�a.
 * @param int* wspolrzedna_x_weza: warto�� adresu pami�ci gdzie jest przechwywana warto�� koordynatu X z pozycj� w�a.
 * @param int* wspolrzedna_y_weza: warto�� adresu pami�ci gdzie jest przechwywana warto�� koordynatu Y z pozycj� w�a.
 */
void sterowanie(int* kierunek, int* wspolrzedna_x_weza, int* wspolrzedna_y_weza)
{
    if (*kierunek == GORA)
    {
        (*wspolrzedna_y_weza)--;
    }
    if (*kierunek == DOL)
    {
        (*wspolrzedna_y_weza)++;
    }
    if (*kierunek == LEWO)
    {
        (*wspolrzedna_x_weza)--;
    }
    if (*kierunek == PRAWO)
    {
        (*wspolrzedna_x_weza)++;
    }
}
