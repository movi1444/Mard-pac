#ifndef MENU_H
#define MENU_H

#include "raylib.h"

typedef enum {
    MENU,
    DIFFICULTY,
    ENTER_NAME,
    CHOOSE_MAP,
    MUSIC_MENU,
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
extern Sound SelectedSound;

void RunMenu(GameState *currentState);
void RunDifficultyMenu(GameState *currentState);
void RunEnterName(GameState *currentState, char *playerName);
void RunGameOver(GameState *currentState);
void RunChooseMapMenu(GameState *currentState);
void RunRecords(GameState *currentState);
void RunMusicMenu(GameState *currentState);

#endif 