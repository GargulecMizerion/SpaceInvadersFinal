#include <stdio.h>
#include <stdlib.h>
#include "opponents.h"

Enemy* initializeOpponents(int lvl) {

    Enemy* opponents = NULL;

    if (lvl == 1) {
        opponents = (Enemy*)calloc(10, sizeof(Enemy));
        opponents[0].x = 50;
        opponents[0].y = 100;
        opponents[0].dmg = 1;
        opponents[0].hp = 1;
        opponents[0].speed = 0.04;
        opponents[0].type = 1;

        opponents[1].x = 327;
        opponents[1].y = 100;
        opponents[1].dmg = 1;
        opponents[1].hp = 1;
        opponents[1].speed = 0.04;
        opponents[1].type = 1;

        opponents[2].x = 604;
        opponents[2].y = 100;
        opponents[2].dmg = 1;
        opponents[2].hp = 1;
        opponents[2].speed = 0.04;
        opponents[2].type = 1;

        opponents[3].x = 881;
        opponents[3].y = 100;
        opponents[3].dmg = 1;
        opponents[3].hp = 1;
        opponents[3].speed = 0.04;
        opponents[3].type = 1;

        opponents[4].x = 1158;
        opponents[4].y = 100;
        opponents[4].dmg = 1;
        opponents[4].hp = 1;
        opponents[4].speed = 0.04;
        opponents[4].type = 1;

        opponents[5].x = 50;
        opponents[5].y = 300;
        opponents[5].dmg = 1;
        opponents[5].hp = 1;
        opponents[5].speed = 0.04;
        opponents[5].type = 1;

        opponents[6].x = 327;
        opponents[6].y = 300;
        opponents[6].dmg = 1;
        opponents[6].hp = 1;
        opponents[6].speed = 0.04;
        opponents[6].type = 1;

        opponents[7].x = 604;
        opponents[7].y = 300;
        opponents[7].dmg = 1;
        opponents[7].hp = 1;
        opponents[7].speed = 0.04;
        opponents[7].type = 1;

        opponents[8].x = 881;
        opponents[8].y = 300;
        opponents[8].dmg = 1;
        opponents[8].hp = 1;
        opponents[8].speed = 0.04;
        opponents[8].type = 1;

        opponents[9].x = 1158;
        opponents[9].y = 300;
        opponents[9].dmg = 1;
        opponents[9].hp = 1;
        opponents[9].speed = 0.04;
        opponents[9].type = 1;
    }

    if (lvl == 2) {
        opponents = (Enemy*)calloc(10, sizeof(Enemy));
        opponents[0].x = 50;
        opponents[0].y = 100;
        opponents[0].dmg = 1;
        opponents[0].hp = 2;
        opponents[0].speed = 0.04;
        opponents[0].type = 2;

        opponents[1].x = 327;
        opponents[1].y = 100;
        opponents[1].dmg = 1;
        opponents[1].hp = 1;
        opponents[1].speed = 0.04;
        opponents[1].type = 1;

        opponents[2].x = 604;
        opponents[2].y = 100;
        opponents[2].dmg = 1;
        opponents[2].hp = 1;
        opponents[2].speed = 0.04;
        opponents[2].type = 1;

        opponents[3].x = 881;
        opponents[3].y = 100;
        opponents[3].dmg = 1;
        opponents[3].hp = 1;
        opponents[3].speed = 0.04;
        opponents[3].type = 1;

        opponents[4].x = 1158;
        opponents[4].y = 100;
        opponents[4].dmg = 1;
        opponents[4].hp = 2;
        opponents[4].speed = 0.04;
        opponents[4].type = 2;

        opponents[5].x = 50;
        opponents[5].y = 300;
        opponents[5].dmg = 1;
        opponents[5].hp = 1;
        opponents[5].speed = 0.04;
        opponents[5].type = 1;

        opponents[6].x = 327;
        opponents[6].y = 300;
        opponents[6].dmg = 1;
        opponents[6].hp = 2;
        opponents[6].speed = 0.04;
        opponents[6].type = 2;

        opponents[7].x = 604;
        opponents[7].y = 300;
        opponents[7].dmg = 1;
        opponents[7].hp = 2;
        opponents[7].speed = 0.04;
        opponents[7].type = 2;

        opponents[8].x = 881;
        opponents[8].y = 300;
        opponents[8].dmg = 1;
        opponents[8].hp = 2;
        opponents[8].speed = 0.04;
        opponents[8].type = 2;

        opponents[9].x = 1158;
        opponents[9].y = 300;
        opponents[9].dmg = 1;
        opponents[9].hp = 1;
        opponents[9].speed = 0.04;
        opponents[9].type = 1;
    }

    if (lvl == 3) {
        opponents = (Enemy*)calloc(10, sizeof(Enemy));
        opponents[0].x = 50;
        opponents[0].y = 100;
        opponents[0].dmg = 1;
        opponents[0].hp = 2;
        opponents[0].speed = 0.04;
        opponents[0].type = 2;

        opponents[1].x = 327;
        opponents[1].y = 100;
        opponents[1].dmg = 1;
        opponents[1].hp = 1;
        opponents[1].speed = 0.04;
        opponents[1].type = 1;

        opponents[2].x = 604;
        opponents[2].y = 100;
        opponents[2].dmg = 1;
        opponents[2].hp = 2;
        opponents[2].speed = 0.04;
        opponents[2].type = 2;

        opponents[3].x = 881;
        opponents[3].y = 100;
        opponents[3].dmg = 1;
        opponents[3].hp = 1;
        opponents[3].speed = 0.04;
        opponents[3].type = 1;

        opponents[4].x = 1158;
        opponents[4].y = 100;
        opponents[4].dmg = 1;
        opponents[4].hp = 2;
        opponents[4].speed = 0.04;
        opponents[4].type = 2;

        opponents[5].x = 50;
        opponents[5].y = 300;
        opponents[5].dmg = 1;
        opponents[5].hp = 1;
        opponents[5].speed = 0.04;
        opponents[5].type = 1;

        opponents[6].x = 327;
        opponents[6].y = 300;
        opponents[6].dmg = 1;
        opponents[6].hp = 3;
        opponents[6].speed = 0.04;
        opponents[6].type = 3;

        opponents[7].x = 604;
        opponents[7].y = 300;
        opponents[7].dmg = 1;
        opponents[7].hp = 1;
        opponents[7].speed = 0.04;
        opponents[7].type = 1;

        opponents[8].x = 881;
        opponents[8].y = 300;
        opponents[8].dmg = 1;
        opponents[8].hp = 3;
        opponents[8].speed = 0.04;
        opponents[8].type = 3;

        opponents[9].x = 1158;
        opponents[9].y = 300;
        opponents[9].dmg = 1;
        opponents[9].hp = 1;
        opponents[9].speed = 0.04;
        opponents[9].type = 1;
    }

    if (lvl == 4) {
        opponents = (Enemy*)calloc(10, sizeof(Enemy));
        opponents[0].x = 50;
        opponents[0].y = 100;
        opponents[0].dmg = 1;
        opponents[0].hp = 2;
        opponents[0].speed = 0.04;
        opponents[0].type = 2;

        opponents[1].x = 327;
        opponents[1].y = 100;
        opponents[1].dmg = 1;
        opponents[1].hp = 1;
        opponents[1].speed = 0.04;
        opponents[1].type = 2;

        opponents[2].x = 604;
        opponents[2].y = 100;
        opponents[2].dmg = 1;
        opponents[2].hp = 2;
        opponents[2].speed = 0.04;
        opponents[2].type = 2;

        opponents[3].x = 881;
        opponents[3].y = 100;
        opponents[3].dmg = 1;
        opponents[3].hp = 1;
        opponents[3].speed = 0.04;
        opponents[3].type = 2;

        opponents[4].x = 1158;
        opponents[4].y = 100;
        opponents[4].dmg = 1;
        opponents[4].hp = 2;
        opponents[4].speed = 0.04;
        opponents[4].type = 2;

        opponents[5].x = 50;
        opponents[5].y = 300;
        opponents[5].dmg = 1;
        opponents[5].hp = 1;
        opponents[5].speed = 0.04;
        opponents[5].type = 2;

        opponents[6].x = 327;
        opponents[6].y = 300;
        opponents[6].dmg = 1;
        opponents[6].hp = 3;
        opponents[6].speed = 0.04;
        opponents[6].type = 3;

        opponents[7].x = 604;
        opponents[7].y = 300;
        opponents[7].dmg = 1;
        opponents[7].hp = 1;
        opponents[7].speed = 0.04;
        opponents[7].type = 2;

        opponents[8].x = 881;
        opponents[8].y = 300;
        opponents[8].dmg = 1;
        opponents[8].hp = 3;
        opponents[8].speed = 0.04;
        opponents[8].type = 3;

        opponents[9].x = 1158;
        opponents[9].y = 300;
        opponents[9].dmg = 1;
        opponents[9].hp = 1;
        opponents[9].speed = 0.04;
        opponents[9].type = 2;
    }

    if (lvl == 4) {
        opponents = (Enemy*)calloc(10, sizeof(Enemy));
        opponents[0].x = 50;
        opponents[0].y = 100;
        opponents[0].dmg = 1;
        opponents[0].hp = 2;
        opponents[0].speed = 0.04;
        opponents[0].type = 3;

        opponents[1].x = 327;
        opponents[1].y = 100;
        opponents[1].dmg = 1;
        opponents[1].hp = 1;
        opponents[1].speed = 0.04;
        opponents[1].type = 3;

        opponents[2].x = 604;
        opponents[2].y = 100;
        opponents[2].dmg = 1;
        opponents[2].hp = 2;
        opponents[2].speed = 0.04;
        opponents[2].type = 3;

        opponents[3].x = 881;
        opponents[3].y = 100;
        opponents[3].dmg = 1;
        opponents[3].hp = 1;
        opponents[3].speed = 0.04;
        opponents[3].type = 3;

        opponents[4].x = 1158;
        opponents[4].y = 100;
        opponents[4].dmg = 1;
        opponents[4].hp = 2;
        opponents[4].speed = 0.04;
        opponents[4].type = 3;

        opponents[5].x = 50;
        opponents[5].y = 300;
        opponents[5].dmg = 1;
        opponents[5].hp = 1;
        opponents[5].speed = 0.04;
        opponents[5].type = 3;

        opponents[6].x = 327;
        opponents[6].y = 300;
        opponents[6].dmg = 1;
        opponents[6].hp = 3;
        opponents[6].speed = 0.04;
        opponents[6].type = 3;

        opponents[7].x = 604;
        opponents[7].y = 300;
        opponents[7].dmg = 1;
        opponents[7].hp = 1;
        opponents[7].speed = 0.04;
        opponents[7].type = 3;

        opponents[8].x = 881;
        opponents[8].y = 300;
        opponents[8].dmg = 1;
        opponents[8].hp = 3;
        opponents[8].speed = 0.04;
        opponents[8].type = 3;

        opponents[9].x = 1158;
        opponents[9].y = 300;
        opponents[9].dmg = 1;
        opponents[9].hp = 1;
        opponents[9].speed = 0.04;
        opponents[9].type = 3;
    }

    return opponents;
}
