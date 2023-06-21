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
#include "functions.h"

/// @brief Glowny plik uruchomieniowy z funkcja main
///
///

int main() {
    /// Inicjacja biblioteki Allegro
    al_init();
    /// Inicjacja modulu rysowania obiektow
    al_init_primitives_addon();
    /// Instalacja modulu klawiatury
    al_install_keyboard();
    /// Instalacja modulu myszki
    al_install_mouse();
	/// Inicjacja modulu obrazu
    al_init_image_addon();
    /// Inicjacja modulu odpowiedzialnego za czcionki
    al_init_ttf_addon();
    /// Instalacja modulu dzwieku
    al_install_audio();
    /// Inicjacja kodeku
    al_init_acodec_addon();

    /// Rezerwacja pamieci dla plikow audio
    al_reserve_samples(3);

    /// Deklaracja i inicjaca statku kosmicznego kontrolowanego przez gracza
    Ship ship;
    /// Inicjacja wartosci x statku kosmicznego kontrolowanego przez gracza
    ship.x = SCREEN_WIDTH / 2.0;
	/// Inicjacja wartosci y statku kosmicznego kontrolowanego przez gracza
    ship.y = SCREEN_HEIGHT - 100;
	/// Inicjacja wartosci vx (predkosc w poziomie) statku kosmicznego kontrolowanego przez gracza
    ship.vx = 0.5;
	/// Inicjacja wartosci dmg statku kosmicznego kontrolowanego przez gracza
    ship.dmg = 1;
	/// Inicjacja wartosci hp statku kosmicznego kontrolowanego przez gracza
    ship.hp = 3;


    /// Deklaracja pocisku wystrzelonego przez gracza
    Bullet bullet;
    /// Inicjacja pola X pocisku
    bullet.x = -10;
    /// Inicjacja pola Y pocisku
    bullet.y = -10;
    /// Inicjacja pola VX pocisku (predkosc w poziomie)
    bullet.vx = 0;
    /// Inicjacja pola VY pocisku (predkosc w pionie)
    bullet.vy = -1;
    /// Inicjacja pola bullet_size pocisku
    bullet.bullet_size = 10;
    /// Inicjacja pola bullet_active pocisku
    bullet.bullet_active = false;

    /// Deklaracja wrogiego pocisku
    Bullet bullet_enemy;
    /// Inicjacja pola X pocisku
    bullet_enemy.x = 100;
    /// Inicjacja pola Y pocisku
    bullet_enemy.y = -10;
    /// Inicjacja pola VX pocisku (predkosc w poziomie)
    bullet_enemy.vx = 0;
    /// Inicjacja pola VY pocisku (predkosc w pionie)
    bullet_enemy.vy = 0.5;
    /// Inicjacja pola bullet_size pocisku
    bullet_enemy.bullet_size = 10;
    /// Inicjacja pola bullet_active pocisku
    bullet_enemy.bullet_active = false;

    /// Deklaracja i inicjacja zmiennej ktora przechowuje numer aktualnego poziomu
    int level = 1;
    /// Deklaracja i inicjacja zmiennej ktora przechowuje aktualna ilosc punktow
    int points = 0;


    /// Alokacja pamieci na tablice wrogow i inicjacja jej wartosciami odpowiednimi dla danego poziomu
    Enemy* opponents = initializeOpponents(level);

    /// Deklaracja i inicjacja okna gry 
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	/// Nadanie tytulu okna 
    al_set_window_title(display, "Space Invaders");

    /// Deklaracja i inicjalizacja zmiennej bg_color
    ALLEGRO_COLOR bg_color = al_map_rgb(0, 0, 0);
	/// Deklaracja i inicjalizacja zmiennej bullet_color
    ALLEGRO_COLOR bullet_color = al_map_rgb(0, 255, 0);
	/// Deklaracja i inicjalizacja zmiennej bullet_color_enemy
    ALLEGRO_COLOR bullet_color_enemy = al_map_rgb(255, 0, 0);

    /// Deklaracja zmiennej keyboard_state przechowujacej stan klawiatury 
    ALLEGRO_KEYBOARD_STATE keyboard_state;
	/// Deklaracja zmiennej mouse_state przechowujacej stan myszy 
    ALLEGRO_MOUSE_STATE mouse_state;
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej
    ALLEGRO_FONT* font = al_create_builtin_font();
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej vv
    ALLEGRO_FONT* vv = al_load_ttf_font("C:/Users/Komputer/Desktop/FONTS/vermin_vibes_1989/Vermin Vibes 1989.ttf", 140, NULL);
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej vvShadow ladujacej czcionke z podanej sciezki  
    ALLEGRO_FONT* vvShadow = al_load_ttf_font("C:/Users/Komputer/Desktop/FONTS/vermin_vibes_1989/Vermin Vibes 1989.ttf", 140, NULL);
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej vvMenu ladujacej czcionke z podanej sciezki  
    ALLEGRO_FONT* vvMenu = al_load_ttf_font("C:/Users/Komputer/Desktop/FONTS/vermin_vibes_1989/Vermin Vibes 1989.ttf", 80, NULL);
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej vvPoints ladujacej czcionke z podanej sciezki  
    ALLEGRO_FONT* vvPoints = al_load_ttf_font("C:/Users/Komputer/Desktop/FONTS/vermin_vibes_1989/Vermin Vibes 1989.ttf", 30, NULL);
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej vvLevel ladujacej czcionke z podanej sciezki  
    ALLEGRO_FONT* vvLevel = al_load_ttf_font("C:/Users/Komputer/Desktop/FONTS/vermin_vibes_1989/Vermin Vibes 1989.ttf", 40, NULL);
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej menu_sample ladujacej dzwiek z podanej sciezki  
    ALLEGRO_SAMPLE* menu_sample = al_load_sample("C:/Users/Komputer/Desktop/FONTS/start_sound.ogg");;
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej shoot_sample ladujacej dzwiek z podanej sciezki  
    ALLEGRO_SAMPLE* shoot_sample = al_load_sample("C:/Users/Komputer/Desktop/FONTS/shoot.ogg");
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej dead_sample ladujacej dzwiek z podanej sciezki  
    ALLEGRO_SAMPLE* dead_sample = al_load_sample("C:/Users/Komputer/Desktop/FONTS/blast.ogg");

	/// Deklaracja i inicjalizacja zmiennej wskaznikowej bitmap ladujacej grafike z podanej sciezki  
    ALLEGRO_BITMAP* bitmap = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/player.png");
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej enemy_bitmap_1 ladujacej grafike z podanej sciezki  
    ALLEGRO_BITMAP* enemy_bitmap_1 = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/my_ufo.png");
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej enemy_bitmap_2 ladujacej grafike z podanej sciezki  
    ALLEGRO_BITMAP* enemy_bitmap_2 = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/ufo_2.png"); 
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej enemy_bitmap_3 ladujacej grafike z podanej sciezki  
    ALLEGRO_BITMAP* enemy_bitmap_3 = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/ufo.png");
	/// Deklaracja i inicjalizacja zmiennej wskaznikowej heart_bitmap ladujacej grafike z podanej sciezki  
    ALLEGRO_BITMAP* heart_bitmap = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/heart.png"); 

	/// Deklaracja i inicjalizacja zmiennej wskaznikowej heart_bitmap ladujacej grafike z podanej sciezki  
    ALLEGRO_BITMAP* background_bitmap = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/space-background.png");
    ALLEGRO_BITMAP* game_background_bitmap = al_load_bitmap("C:/Users/Komputer/Desktop/PNGsy/game-background.png");

	/// Deklaracja zmiennej wskaznikowej timer
    ALLEGRO_TIMER* timer = NULL;
    /// Zwiekszanie timera o jeden co podana wartosc
    timer = al_create_timer(0.001); 

    /// Sprawdzenie poprawnosci alokacji pamieci
    if (!timer) {
        printf("Nie udalo zainicjowac timera\n");
        return -1;
    }

    if (!vv || !vvLevel || !vvMenu || !vvPoints || !vvShadow) {
        printf("Nie udalo sie zaladowac czcionki!\n");
        return -1;
    }

    /// Sprawdzenie poprawnosci alokacji pamieci
    if (!bitmap || !enemy_bitmap_1 || !enemy_bitmap_2 || !enemy_bitmap_3 || !heart_bitmap || !background_bitmap || !game_background_bitmap) {
        printf("Nie udalo sie bitmapy!\n");
        return -1;
    }

    /// Sprawdzenie poprawnosci alokacji pamieci
    if (!menu_sample || !shoot_sample || !dead_sample) {
        printf("Nie udalo sie zaladowac dzwieku!\n");
        return -1;
    }

    srand(time(NULL));


    /// Deklaracja zmiennej iterujacej po tablicy wrogow
    int enemy_iter;                 // Iterator tablicy wrogów

    /// Deklaracja i inicjacja zmiennej pomocniczej wykorzystywanej podczas ruchu przeciwnikow
    float enemy_move = 0;           // Zmienna pomocnicza wykorzystywana do ruchu przeciwników



    /// Deklaracja i inicjacja zmiennej 
    int start_window = 1;
    int gameLoop = 1;

    startFrame(&start_window, &mouse_state, vv, vv, vvMenu, background_bitmap, menu_sample);


    /// Wystartowanie timera
    al_start_timer(timer);

    int shoot = 0;


    do {
        // SPRAWDZENIE
        if (al_get_timer_count(timer) > 0) {
            al_set_timer_count(timer, 0);
            al_draw_bitmap(background_bitmap, 0, 0, NULL);

            shipMove(&ship, &bullet, &keyboard_state, shoot_sample);

            drawBullet(&bullet, bullet_color);

            shoot = rand() % 10;
            if (!bullet_enemy.bullet_active) {
                bullet_enemy.x = opponents[shoot].x;
                bullet_enemy.y = opponents[shoot].y;
                bullet_enemy.bullet_active = true;
            }

            drawBulletEnemy(&bullet_enemy, bullet_color_enemy);
            checkEnemyBulletColision(&bullet_enemy, &ship);

            for (int hearts = 0; hearts < ship.hp; hearts++)
            {
                al_draw_bitmap(heart_bitmap, 20 + 65 * hearts, 20, 0);
            }
            
            al_draw_textf(vvPoints, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 20, ALLEGRO_ALIGN_CENTER, "Points: %d", points);
            al_draw_textf(vvLevel, al_map_rgb(255, 255, 255), SCREEN_WIDTH - 10, 20, ALLEGRO_ALIGN_RIGHT, "LEVEL %d", level);


            if (checkEnemy(opponents)) {
                checkCollision(&bullet, opponents, dead_sample, &points);
            }


            if (enemy_move > 200 || enemy_move < -200) {
                for (enemy_iter = 0; enemy_iter < 10; enemy_iter++) {
                    opponents[enemy_iter].speed *= -1;
                }
            }

            for (enemy_iter = 0; enemy_iter < 10; enemy_iter++) {
                opponents[enemy_iter].x += opponents[enemy_iter].speed;
                if (opponents[enemy_iter].hp > 0) {
                    switch (opponents[enemy_iter].type) {
                    case 1:
                        al_draw_bitmap(enemy_bitmap_1, opponents[enemy_iter].x, opponents[enemy_iter].y, 0);
                        break;
                    case 2:
                        al_draw_bitmap(enemy_bitmap_2, opponents[enemy_iter].x, opponents[enemy_iter].y, 0);
                        break;
                    case 3:
                        al_draw_bitmap(enemy_bitmap_3, opponents[enemy_iter].x, opponents[enemy_iter].y, 0);
                        break;
                    }
                   
                }
            }

            enemy_move += opponents[0].speed * 10;

            if (checkEnemy(opponents) == 0 && level == MAX_LEVEL) {
                opponents = initializeOpponents(1);
                gameLoop = 0;
                break;
            }
            else if (checkEnemy(opponents) == 0) {
                level++;
                opponents = initializeOpponents(level);
            }

            if (ship.hp > 0) {
                al_draw_bitmap(bitmap, ship.x, ship.y, 0);
            }
            else {
                gameLoop = 0;
                break;
            }
            
            al_flip_display();
        }
    } while (gameLoop);

    endFrame(&mouse_state, vv, vv, vvMenu, background_bitmap, &points);

    al_destroy_bitmap(bitmap);
    al_destroy_display(display);
    free(opponents);
    


    al_destroy_font(font);
    al_destroy_font(vv);
    al_destroy_font(vvLevel);
    al_destroy_font(vvMenu);
    al_destroy_font(vvPoints);
    al_destroy_font(vvShadow);
    al_destroy_sample(menu_sample);
    al_destroy_sample(shoot_sample);
    al_destroy_sample(dead_sample);
    al_destroy_bitmap(bitmap);
    al_destroy_bitmap(enemy_bitmap_1);
    al_destroy_bitmap(enemy_bitmap_2);
    al_destroy_bitmap(enemy_bitmap_3);
    al_destroy_bitmap(heart_bitmap);
    al_destroy_bitmap(background_bitmap);
    al_destroy_bitmap(game_background_bitmap);
    al_destroy_display(display);

    return 0;
}



