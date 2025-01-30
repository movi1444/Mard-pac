#include "raylib.h"
#include "map.h"
#include "Mavajid.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"

void GameLoop(GameState *currentState) {
    bazikoon.pos = (Vector2) {400, 300};
    bazikoon.direction = (Vector2) {0, 0};
    bazikoon.sorat = 2.5;

    InitializeMavajid();
    
    while (!WindowShouldClose()) {

        UpdateSoundLoop();

        if (IsKeyDown(KEY_UP)) bazikoon.direction = (Vector2){0, -1};
        if (IsKeyDown(KEY_DOWN)) bazikoon.direction = (Vector2){0, 1};
        if (IsKeyDown(KEY_LEFT)) bazikoon.direction = (Vector2){-1, 0};
        if (IsKeyDown(KEY_RIGHT)) bazikoon.direction = (Vector2){1, 0};

        bazikoon.pos.x += bazikoon.sorat * bazikoon.direction.x;
        bazikoon.pos.y += bazikoon.sorat * bazikoon.direction.y;

        if (bazikoon.pos.x < GRID_ANDAZE) bazikoon.pos.x = GRID_ANDAZE;
        if (bazikoon.pos.y < GRID_ANDAZE) bazikoon.pos.y = GRID_ANDAZE;
        if (bazikoon.pos.x > SAFHE_TOOL - GRID_ANDAZE) bazikoon.pos.x = SAFHE_TOOL - GRID_ANDAZE;
        if (bazikoon.pos.y > SAFHE_ERTEFA - GRID_ANDAZE) bazikoon.pos.y = SAFHE_ERTEFA - GRID_ANDAZE;

        if (Is_divar((Vector2){bazikoon.pos.x-12.5, bazikoon.pos.y})) bazikoon.pos.x += bazikoon.sorat;
        if (Is_divar((Vector2){bazikoon.pos.x+12.5, bazikoon.pos.y})) bazikoon.pos.x -= bazikoon.sorat;
        if (Is_divar((Vector2){bazikoon.pos.x, bazikoon.pos.y+12.5})) bazikoon.pos.y -= bazikoon.sorat;
        if (Is_divar((Vector2){bazikoon.pos.x, bazikoon.pos.y-12.5})) bazikoon.pos.y += bazikoon.sorat;

        UpdateMavajid(bazikoon.pos,currentState);
         if (*currentState == GAME_OVER) break;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawMap();
        DrawMavajid(bazikoon.pos);

        char emtiaz[30];
        sprintf(emtiaz, "emtiaz : %.0lf", sekecnt*10*zarib);
        DrawText(emtiaz, 360, 10, 20, GREEN);

        if(goloostimer>0){
            char goloostime[30];
            sprintf(goloostime, "goloostime : %.2lf", goloostimer);
            DrawText(goloostime, SAFHE_TOOL - 200, SAFHE_ERTEFA - 30, 20, RED);
        }

        if(falafeltimer>0){
            char falafeltime[30];
            sprintf(falafeltime, "falafeltime : %.2lf", falafeltimer);
            DrawText(falafeltime, 40, SAFHE_ERTEFA - 30, 20, DARKGREEN);
        }
        
        EndDrawing();
    }
}