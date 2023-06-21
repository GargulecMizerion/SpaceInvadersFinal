#pragma once
#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include "opponents.h"
#include <time.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#define SCREEN_WIDTH 1280   
#define SCREEN_HEIGHT 720
#define MAX_LEVEL 3



/**
 * @file functions.h
 * @brief Plik naglowkowy wszystkich funkcji
 */



/**
 * @struct Ship
 * @brief Struktura statku kosmicznego gracza
 */
typedef struct Ship {
    float x;
    float y;
    float vx;
    float vy;
    float hp;
    float dmg;
} Ship;



/**
 * @struct Bullet
 * @brief Struktura pocisku
 */
typedef struct Bullet {
    float x;
    float vx;
    float y;
    float vy;
    int bullet_size;
    bool bullet_active;
} Bullet;


/**
 * @brief Funkcja odpowiedzialna za rysowanie pocisku gracza
 * @param bullet Wystrzelony pocisk
 * @param bullet_color Kolor pocisku
 */
void drawBullet(Bullet* bullet, ALLEGRO_COLOR bullet_color);

/**
 * @brief Funkcja odpowiedzialna za rysowanie pocisku przeciwnika 
 * @param bullet_enemy Wystrzelony pocisk
 * @param bullet_color_enemy Kolor pocisku
 */
void drawBulletEnemy(Bullet* bullet_enemy, ALLEGRO_COLOR bullet_color_enemy);
 
/**
 * @brief Funkcja odpowiedzialna za sprawdzanie kolizji 
 * @param bullet Wystrzelony pocisk
 * @param enemy Wrog dla ktorego sprawdzana jest kolizja z pociskiem
 * @param sample Dzwiek odtwarzany w razie zestrzelenia statku
 * @param points Wskaznik na ilosc punktow, ktorego wartosc jest zwiekszana w razie zestrzelenia statku
 */
void checkCollision(Bullet* bullet, Enemy* enemy, ALLEGRO_SAMPLE* sample, int* points);
/// Deklaracja funkcji odpowiadajacej za porzuszanie sie statkiem
/**
 * @brief Funkcja odpowiedzialna za porzuszanie sie statkiem
 * @param ship Statek gracza
 * @param keyboard_state Stan klawiatury
 * @param sample Dzwiek odtwarzany podczas strzalu
 */
void shipMove(Ship* ship, Bullet* bullet, ALLEGRO_KEYBOARD_STATE* keyboard_state, ALLEGRO_SAMPLE* sample);
/// Deklaracja funkcji odpowiadajacej za sprawdzenie ile jest wrogow w tablicy
/**
 * @brief Funkcja sprawdzajaca ilosc pozostalych wrogow w tablicy
 * @param opponents Tablica z wrogami
 * @return Wartosc calkowitoliczbowa reprezentujaca ilosc wrogow
 */
int checkEnemy(Enemy* opponents);
/// Deklaracja funkcji odpowiadajacej za wyswietlenie okna koncowego gry
/**
 * @brief Funkcja odpowiedzialna za wyswietlenie okna koncowego gry
 * @param mouse_state Stan myszki
 * @param font Glowna czcionka
 * @param shadowFont Czcionka - cien
 * @param menuFont Czcionka na przycisk
 * @param bg_bitmap Obraz tla
 * @param points Ilosc zdobytych punktow
 */
void endFrame(ALLEGRO_MOUSE_STATE* mouse_state, ALLEGRO_FONT* font, ALLEGRO_FONT* shadowFont, ALLEGRO_FONT* menuFont, ALLEGRO_BITMAP* bg_bitmap, int* points);
/// Deklaracja funkcji odpowiadajacej za sprawdzenie kolizcji pociskow z graczem
/**
 * @brief Funkcja odpowiedzialna na sprawdzenie kolizcji pociskow z graczem
 * @param bullet_enemy Sprawdzany pocisk
 * @param ship Statek kosmiczny gracza
 */
void checkEnemyBulletColision(Bullet* bullet_enemy, Ship* ship);
/// Deklaracja funkcji odpowiadajacej za wyswietlenie okna startowego gry
/**
 * @brief Funkcja odpowiedzialna za wyswietlenie okna startowego gry
 * @param start_window Flaga odpowiedzialna za wylaczenie ekranu startowego i przejscie do rozgrywki
 * @param mouse_state Stan myszki
 * @param font Glowna czcionka
 * @param shadowFont Czcionka - cien
 * @param menuFont Czcionka na przycisk
 * @param bg_bitmap Obraz tla
 * @param sample Muzyka 
 */
void startFrame(int* start_window, ALLEGRO_MOUSE_STATE* mouse_state, ALLEGRO_FONT* font, ALLEGRO_FONT* shadowFont, ALLEGRO_FONT* menuFont, ALLEGRO_BITMAP* bg_bitmap, ALLEGRO_SAMPLE* sample);
