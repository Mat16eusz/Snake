/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Ustawienia_konsoli.h"
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

/**
 * Ustawianie rozmiaru okna konsoli.
 */
void rozmiar_konsoli(void)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT wielkosc_okna = { 0, 0, 140, 41 };
    COORD wielkosc_bufora = { 120, 30 };
    HWND uchwyt_konsoli = GetConsoleWindow();

    MoveWindow(uchwyt_konsoli, 0, 0, 5000, 5000, TRUE);
    SetConsoleWindowInfo(h, 1, &wielkosc_okna);
    SetConsoleScreenBufferSize(h, wielkosc_bufora);
}

/**
 * Funkcja odpowiadaj¹ca za pokazywanie i ukrywanie kursora w konsoli.
 *
 * @param bool jest_kursor: parametr przekazuj¹cy wartoœæ czy kursor ma byæ widoczny w konsoli
 */
void pokaz_kursor_na_ekranie(bool jest_kursor)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO wlasciwosci_kursora;

    GetConsoleCursorInfo(h, &wlasciwosci_kursora);
    wlasciwosci_kursora.bVisible = jest_kursor;
    SetConsoleCursorInfo(h, &wlasciwosci_kursora);
}
