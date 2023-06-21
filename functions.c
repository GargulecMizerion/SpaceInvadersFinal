#include "functions.h"

void startFrame(int* start_window, ALLEGRO_MOUSE_STATE* mouse_state, ALLEGRO_FONT* font, ALLEGRO_FONT* shadowFont, ALLEGRO_FONT* menuFont, ALLEGRO_BITMAP* bg_bitmap, ALLEGRO_SAMPLE* sample) {
    al_play_sample(sample, 0.2, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
    while (*start_window) {

        al_play_sample(sample, 0.01, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
        al_get_mouse_state(mouse_state);
        al_draw_bitmap(bg_bitmap, 0, 0, NULL);
        al_draw_filled_rectangle(SCREEN_WIDTH / 2 - 150, 300, SCREEN_WIDTH / 2 + 150, 400, al_map_rgba(40, 0, 100, 0));
        al_draw_text(shadowFont, al_map_rgb(100, 0, 255), SCREEN_WIDTH / 2 + 5, 25, ALLEGRO_ALIGN_CENTER, "SPACE  INVADERS");
        al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 20, ALLEGRO_ALIGN_CENTER, "SPACE  INVADERS");
        al_draw_text(menuFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 320, ALLEGRO_ALIGN_CENTER, "START");

        if (mouse_state->buttons & 1 && mouse_state->x > SCREEN_WIDTH / 2 - 150 && mouse_state->x < SCREEN_WIDTH / 2 + 150 && mouse_state->y > 300 && mouse_state->y < 400) {
            *start_window = 0;
        }
        al_flip_display();
    }

    al_stop_sample(sample);
    al_destroy_sample(sample);

    return;
}

void endFrame(ALLEGRO_MOUSE_STATE* mouse_state, ALLEGRO_FONT* font, ALLEGRO_FONT* shadowFont, ALLEGRO_FONT* menuFont, ALLEGRO_BITMAP* bg_bitmap, int* points) {
    while (1) {
        al_get_mouse_state(mouse_state);
        al_draw_bitmap(bg_bitmap, 0, 0, NULL);
        al_draw_filled_rectangle(SCREEN_WIDTH / 2 - 150, 320, SCREEN_WIDTH / 2 + 150, 420, al_map_rgba(40, 0, 100, 0));
        al_draw_text(shadowFont, al_map_rgb(100, 0, 255), SCREEN_WIDTH / 2 + 5, 25, ALLEGRO_ALIGN_CENTER, "SPACE  INVADERS");
        al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 20, ALLEGRO_ALIGN_CENTER, "SPACE  INVADERS");
        al_draw_text(menuFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 340, ALLEGRO_ALIGN_CENTER, "KONIEC");
        al_draw_textf(menuFont, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, 200, ALLEGRO_ALIGN_CENTER, "Points: %d", *points);
        al_flip_display();

        if (mouse_state->buttons & 1 && mouse_state->x > SCREEN_WIDTH / 2 - 150 && mouse_state->x < SCREEN_WIDTH / 2 + 150 && mouse_state->y > 300 && mouse_state->y < 400) {
            return;
        }

    }

}

int checkEnemy(Enemy* opponents) {
    int check = 0;
    for (int i = 0; i < 10; i++) check = opponents[i].hp > 0 ? ++check : check;
    return check;
}

void drawBullet(Bullet* bullet, ALLEGRO_COLOR bullet_color) {
    // Rysowanie pocisku
    if (bullet->bullet_active) {

        al_draw_filled_rectangle(bullet->x - 23, bullet->y, bullet->x + bullet->bullet_size - 23, bullet->y + bullet->bullet_size, bullet_color);

        // Aktualizacja pozycji pocisku
        bullet->bullet_active = true;
        if (bullet->bullet_active) {
            bullet->y += bullet->vy;
        }
    }

    // Sprawdzenie, czy pocisk wylecia³ poza ekran
    if (bullet->y < 0) {
        bullet->bullet_active = false;
    }
}

void drawBulletEnemy(Bullet* bullet_enemy, ALLEGRO_COLOR bullet_color_enemy) {
    // Rysowanie pocisku
    if (bullet_enemy->bullet_active) {

        al_draw_filled_rectangle(bullet_enemy->x + 30, bullet_enemy->y + 20, bullet_enemy->x + bullet_enemy->bullet_size + 30, bullet_enemy->y + bullet_enemy->bullet_size + 20, bullet_color_enemy);

        // Aktualizacja pozycji pocisku przeciwnika
        bullet_enemy->bullet_active = true;
        if (bullet_enemy->bullet_active) {
            bullet_enemy->y += bullet_enemy->vy;
        }
    }

    // Sprawdzenie, czy pocisk przeciwnika wylecia³ poza ekran
    if (bullet_enemy->y > SCREEN_HEIGHT) {
        bullet_enemy->bullet_active = false;
    }
}

void checkEnemyBulletColision(Bullet* bullet_enemy, Ship* ship) {
    if (bullet_enemy->x < ship->x + 72 && bullet_enemy->x + 30> ship->x && bullet_enemy->y > ship->y + 45) {
        printf("trafiony zostalem");
        ship->hp--;
        bullet_enemy->bullet_active = 0;
    }
}

void checkCollision(Bullet* bullet, Enemy* enemy, ALLEGRO_SAMPLE* sample, int* points) {
    int iter;
    for (iter = 0; iter < 10; iter++) {
        if (bullet->x > enemy[iter].x && bullet->x < enemy[iter].x + 80 && bullet->y < enemy[iter].y + 20 && bullet->y > enemy[iter].y) {
            enemy[iter].hp -= 1;
            //lista  z przeciwnikami
            if (!enemy[iter].hp) {
                al_play_sample(sample, 0.5, 0, 1.5, ALLEGRO_PLAYMODE_ONCE, NULL);
                enemy[iter].x = -100;
                enemy[iter].y = -100;
                *points += 10 * enemy->type;
            }

            printf("%d\n", *points);
            bullet->bullet_active = false;
            bullet->x = -10;
            bullet->y = -10;
        }
    }
}

void shipMove(Ship* ship, Bullet* bullet, ALLEGRO_KEYBOARD_STATE* keyboard_state, ALLEGRO_SAMPLE* sample) {
    al_get_keyboard_state(keyboard_state);
    if (al_key_down(keyboard_state, ALLEGRO_KEY_LEFT)) {
        ship->x -= ship->vx;
        if (ship->x < 0) {
            ship->x = 0;
        }
    }

    if (al_key_down(keyboard_state, ALLEGRO_KEY_RIGHT)) {
        ship->x += ship->vx;
        if (ship->x > SCREEN_WIDTH - 150) {
            ship->x = SCREEN_WIDTH - 150;
        }
    }
    if (al_key_down(keyboard_state, ALLEGRO_KEY_SPACE) && !bullet->bullet_active) {
        al_play_sample(sample, 0.1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
        puts("klikam spacje ");
        bullet->bullet_active = true;
        bullet->x = ship->x + 70;
        bullet->y = ship->y;
    }
}