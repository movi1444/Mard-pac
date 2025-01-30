#ifndef MAVAJID_H
#define MAVAJID_H

#include "raylib.h"
#include "menu.h"

extern int sekecnt;

typedef struct {
    Vector2 position;
    Vector2 direction;
    bool is_zende;
    float sorat;
    Color color;
} Rooh;

typedef struct {
    Vector2 position;
    bool hast_khorde;
} Gilas;

typedef struct {
    Vector2 position;
    bool hast_khorde;
} Sib;

typedef struct {
    Vector2 position;
    bool hast_khorde;
} Gharch;

typedef struct {
    Vector2 position;
    bool hast_khorde;
} Felfel;

typedef struct {
    Vector2 position;
    bool hast_gerefteh;
}seke;

typedef struct {
    Vector2 pos;
    Vector2 direction;
    float sorat;
    int joon;
}bazikon;

extern bazikon bazikoon;
extern Rooh *ARVAH;

extern double goloostimer;
extern double falafeltimer;
extern double zarib;

extern Sound backgroundMusic;
extern Sound menu1;
extern Sound menu2;


void loadTextureandAudio();
void InitializeMavajid(void);
void UpdateMavajid(Vector2 pos,GameState *currentstate);
void DrawMavajid(Vector2 posbazikoon);
void UpdateSoundLoop(void);

#endif