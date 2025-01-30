#ifndef MENU_H
#define MENU_H

#include "raylib.h"

typedef enum {
    MENU,
    DIFFICULTY,
    ENTER_NAME,
    CHOOSE_MAP,
    GAME,
    RECORDS,
    GAME_OVER,
    EXIT
} GameState;

typedef struct {
    char name[30];
    int score;
    char date[20];
} Record;

extern int sath;
extern int selectedmap;
extern char playername[25];

void RunMenu(GameState *currentState);
void RunDifficultyMenu(GameState *currentState);
void RunEnterName(GameState *currentState, char *playerName);
void RunGameOver(GameState *currentState);
void RunChooseMapMenu(GameState *currentState);
void RunRecords(GameState *currentState);

#endif 