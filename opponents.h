#pragma once
#include <stdio.h>
#include <stdlib.h>

/**
 * @file opponents.h
 * @brief Plik naglowkowy zawierajacy definicje struktury wroga oraz funkcje odpowiedzialna za inicjacje tablicy wrogow odpowiednimi wartosciami
 */



/**
 * @struct Enemy
 * @brief Struktura wroga
 */
typedef struct Enemy {
    float x;
    float y;
    float hp;
    float dmg;
    float speed;
    short type;
} Enemy;


/**
 * @brief Funkcja do inicjacji tablicy wrogow odpowiednimi wartosciami w zaleznosci od poziomu
 * @param lvl Numer aktualnego poziomu
 * @return Zwracana wartosc to wskaznik na tablice wrogow
 */
Enemy* initializeOpponents(int lvl);