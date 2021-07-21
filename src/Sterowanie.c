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
 * Funkcja odpowiada za ustawienie klawiszy steruj¹cych.
 *
 * @param int* kierunek: wartoœæ, która odpowiada za kierunek poruszania siê wê¿a.
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
 * Funkcja realizuj¹ca ruch wê¿a w poszczególnym kierunku.
 *
 * @param int* kierunek: wartoœæ, która odpowiada za kierunek poruszania siê wê¿a.
 * @param int* wspolrzedna_x_weza: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu X z pozycj¹ wê¿a.
 * @param int* wspolrzedna_y_weza: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu Y z pozycj¹ wê¿a.
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
