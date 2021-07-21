/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Rysowanie_planszy_i_ustawianie_wartosci.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "Logika_gry.h"

#define ROZMIAR_PLANSZY_SZEROKOSC 140
#define ROZMIAR_PLANSZY_WYSOKOSC 40
#define SZEROKOSC_PLANSZY 69
#define WYSOKOSC_PLANSZY 39

/**
 * Funkcja odpowiadaj¹ca za wylosowanie pocz¹tkowych koordynatów wê¿a i jedzenia na planszy.
 *
 * @param int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC]: logiczna plansza po której porusza siê w¹¿.
 *                                                                          Wartoœæ 0 odpowiada pustemu polu, 1 odpowiada polu z wê¿em,
 *                                                                          2 odpowiada polu z jedzeniem.
 * @param int* wspolrzedna_x_weza: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu X z pozycj¹ wê¿a.
 * @param int* wspolrzedna_y_weza: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu Y z pozycj¹ wê¿a.
 * @param int* wspolrzedna_x_jedzenia: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu X jedzenia.
 * @param int* wspolrzedna_y_jedzenia: wartoœæ adresu pamiêci gdzie jest przechwywana wartoœæ koordynatu Y jedzenia.
 */
void poczatkowe_ustawianie_pol(int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC], int* wspolrzedna_x_weza,
    int* wspolrzedna_y_weza, int* wspolrzedna_x_jedzenia, int* wspolrzedna_y_jedzenia)
{
    srand((unsigned)time(NULL));

    *wspolrzedna_x_weza = rand() % SZEROKOSC_PLANSZY;
    *wspolrzedna_y_weza = rand() % WYSOKOSC_PLANSZY;

    plansza[*wspolrzedna_x_weza][*wspolrzedna_y_weza] = 1;

    do
    {
        *wspolrzedna_x_jedzenia = rand() % SZEROKOSC_PLANSZY;
        *wspolrzedna_y_jedzenia = rand() % WYSOKOSC_PLANSZY;
    } while (plansza[*wspolrzedna_x_jedzenia][*wspolrzedna_y_jedzenia] != 0);

    plansza[*wspolrzedna_x_jedzenia][*wspolrzedna_y_jedzenia] = 2;
}

/**
 * Funkcja losuje kolor dla jedzenia wê¿a.
 */
void kolor_jedzenia(void)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand((unsigned)time(NULL));
    int kolor_jedzenia;

    kolor_jedzenia = rand() % 14;

    if (kolor_jedzenia == 0)
    {
        SetConsoleTextAttribute(h, 0x11);
    }
    else if (kolor_jedzenia == 1)
    {
        SetConsoleTextAttribute(h, 0x22);
    }
    else if (kolor_jedzenia == 2)
    {
        SetConsoleTextAttribute(h, 0x33);
    }
    else if (kolor_jedzenia == 3)
    {
        SetConsoleTextAttribute(h, 0x44);
    }
    else if (kolor_jedzenia == 4)
    {
        SetConsoleTextAttribute(h, 0x55);
    }
    else if (kolor_jedzenia == 5)
    {
        SetConsoleTextAttribute(h, 0x66);
    }
    else if (kolor_jedzenia == 6)
    {
        SetConsoleTextAttribute(h, 0x77);
    }
    else if (kolor_jedzenia == 7)
    {
        SetConsoleTextAttribute(h, 0x88);
    }
    else if (kolor_jedzenia == 8)
    {
        SetConsoleTextAttribute(h, 0x99);
    }
    else if (kolor_jedzenia == 9)
    {
        SetConsoleTextAttribute(h, 0xAA);
    }
    else if (kolor_jedzenia == 10)
    {
        SetConsoleTextAttribute(h, 0xBB);
    }
    else if (kolor_jedzenia == 11)
    {
        SetConsoleTextAttribute(h, 0xCC);
    }
    else if (kolor_jedzenia == 12)
    {
        SetConsoleTextAttribute(h, 0xDD);
    }
    else if (kolor_jedzenia == 13)
    {
        SetConsoleTextAttribute(h, 0xEE);
    }

    printf("  ");
    SetConsoleTextAttribute(h, 0x07);
}

/**
 * Funkcja odpowiadaj¹ca za rysowanie planszy jak i pocz¹tkowych wartoœci wê¿a i jedzenia na ekranie.
 *
 * @param int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC]: logiczna plansza po której porusza siê w¹¿.
 *                                                                          Wartoœæ 0 odpowiada pustemu polu, 1 odpowiada polu z wê¿em,
 *                                                                          2 odpowiada polu z jedzeniem.
 */
void rysowanie_planszy(int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC]) // TO DO ogarn¹æ
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    const char linia_pozioma = 205;
    const char linia_pionowa = 186;
    const char rog_prawy_dolny = 188;
    const char rog_prawy_gorny = 187;
    const char rog_lewy_dolny = 200;
    const char rog_lewy_gorny = 201;

    SetConsoleOutputCP(852);
    system("cls");
    idz_do_x_y(0, 1);

    printf("%c", rog_lewy_gorny);
    for (int i = 0; i < SZEROKOSC_PLANSZY; i++)
    {
        printf("%c%c", linia_pozioma, linia_pozioma);
    }
    printf("%c", rog_prawy_gorny);
    for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
    {
        printf("\n%c", linia_pionowa);
        for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
        {
            if (plansza[j][i] == 0)
            {
                printf("  ");
            }
            if (plansza[j][i] == 1)
            {
                SetConsoleTextAttribute(h, 0xFF);
                printf("  ");
                SetConsoleTextAttribute(h, 0x07);
            }
            if (plansza[j][i] == 2)
            {
                kolor_jedzenia();
            }
        }
        printf("%c", linia_pionowa);
    }
    printf("\n%c", rog_lewy_dolny);
    for (int i = 0; i < SZEROKOSC_PLANSZY; i++)
    {
        printf("%c%c", linia_pozioma, linia_pozioma);
    }
    printf("%c", rog_prawy_dolny);
}
