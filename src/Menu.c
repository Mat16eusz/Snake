/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Rysowanie_planszy_i_ustawianie_wartosci.h"
#include "Ustawienia_konsoli.h"
#include "Logika_gry.h"

#define ROZMIAR_PLANSZY_SZEROKOSC 140
#define ROZMIAR_PLANSZY_WYSOKOSC 40

 /**
  * Pod menu. Funkcja odpowiedzialna za powr�t do g��wnego menu lub wyj�cia z aplikacji.
  * -Wr�� do g��wnego menu
  * -Wyj�cie
  */
void pod_menu(void)
{
    char wybor = '0';

    printf("1. Wr��\n");
    printf("2. Wyj�cie\n");
    printf("Wybierz opcj�: ");

    while (wybor != '1' && wybor != '2')
    {
        scanf("%c", &wybor);
        while (getchar() != '\n');

        if (wybor != '1' && wybor != '2')
        {
            printf("Nieprawid�owy wyb�r!\n");
            printf("Wybierz ponownie opcj�: ");
        }
    }

    switch (wybor)
    {
    case '1':
        system("cls");
        menu();
        break;

    case '2':
        exit(0);
        break;

    default:
        break;
    }
}

/**
 * Menu gry. Wy�wietla menu i umo�liwia wy�wietlanie poszczeg�lnych opcji takich jak:
 * -Rozpocznij gr�
 * -Sterowanie
 * -O autorze
 * -Wyj�cie
 */
void menu(void)
{
    char wybor = '0';
    int szybkosc = 15;
    int plansza[ROZMIAR_PLANSZY_SZEROKOSC][ROZMIAR_PLANSZY_WYSOKOSC] = { 0 };
    int wspolrzedna_x_weza = 0;
    int wspolrzedna_y_weza = 0;
    int wspolrzedna_x_jedzenia = 0;
    int wspolrzedna_y_jedzenia = 0;
    FILE* zapis_najlepszego_wyniku;
    int dlugosc_weza_z_pliku = 0;

    zapis_najlepszego_wyniku = fopen("save.bin", "rb");

    if (zapis_najlepszego_wyniku == NULL)
    {
        printf("Rekord d�ugo�ci w�a wynosi 0\n");
    }
    else
    {
        if (zapis_najlepszego_wyniku == NULL)
        {
            printf("Nie mo�na otworzy� pliku aby odczyta� zapis\n");
            return 1;
        }

        fscanf(zapis_najlepszego_wyniku, "%d", &dlugosc_weza_z_pliku);
        printf("Rekord d�ugo�ci w�a wynosi %d\n", dlugosc_weza_z_pliku);

        fclose(zapis_najlepszego_wyniku);
    }

    printf("MENU\n\n");
    printf("Wybierz opcj�\n");
    printf("1. Rozpocznij gr�\n");
    printf("2. Sterowanie\n");
    printf("3. O autorze\n");
    printf("4. Wyj�cie\n");
    printf("Wybierz opcj�: ");

    while (wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4')
    {
        scanf("%c", &wybor);
        while (getchar() != '\n');

        if (wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4')
        {
            printf("Nieprawid�owy wyb�r!\n");
            printf("Wybierz ponownie opcj�: ");
        }
    }

    switch (wybor)
    {
    case '1': /*Rozpocznij gre*/
        poczatkowe_ustawianie_pol(plansza, &wspolrzedna_x_weza, &wspolrzedna_y_weza, &wspolrzedna_x_jedzenia, &wspolrzedna_y_jedzenia);
        pokaz_kursor_na_ekranie(false);
        rysowanie_planszy(plansza);
        logika_gry(szybkosc, plansza, &wspolrzedna_x_weza, &wspolrzedna_y_weza, &wspolrzedna_x_jedzenia, &wspolrzedna_y_jedzenia, &zapis_najlepszego_wyniku, dlugosc_weza_z_pliku);

        break;

    case '2': /*Sterowanie*/
        wybor = '0';
        
        system("cls");
        printf("STEROWANIE\n\n");
        printf("G�ra:  Strza�ka w g�r�\n");
        printf("D�:   Strza�ka w d�\n");
        printf("Lewo:  Strza�ka w lewo\n");
        printf("Prawo: Strza�ka w prawo\n\n");

        pod_menu();

        break;

    case '3': /*O autorze*/
        wybor = '0';

        system("cls");
        printf("Nazywam si� Mateusz Jasiak.\n\n");
        printf("Dane kontaktowe: mateusz.jasiak.dev@gmail.com\n");
        printf("Rekord autora wynosi 151.\n\n");
        printf("Podzi�kowania dla beta tester�w:\n");
        printf("Pawe� Pi�tek\n");
        printf("Adrian Ciocho�\n");
        printf("Grzegorz Kosman\n");
        printf("Daniel �azarek\n\n");

        pod_menu();

        break;

    case '4': /*Wyj�cie z aplikacji*/
        exit(0);
        break;

    default:
        break;
    }
}
