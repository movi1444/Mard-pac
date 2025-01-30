#ifndef MAP_H
#define MAP_H

#include "raylib.h"

#define GRID_ANDAZE 40
#define NUM_GILAS 1
#define NUM_SIB 1
#define NUM_FELFEL 1
#define NUM_GHARCH 1
#define NUM_SEKES 10
#define GILAS_TIME 600
#define MAX_NODES 100
#define SAFHE_TOOL 800
#define SAFHE_ERTEFA 600
#define fps 60

extern int map1[15][20];
extern int map2[15][20];
extern int map3[15][20];
extern int map[15][20];

extern Color Selectedmapcolor1;
extern Color Selectedmapcolor2;

bool Is_divar(Vector2 pos);
void DrawMap(void);
bool divarkhor(Vector2 pos,Vector2 direction);
Vector2 Jahatbad(Vector2 pos);
bool Is_Node(Vector2 pos);
bool Is_khord(Vector2 pos1,Vector2 pos2);
Vector2 randompos(int tool,int ertefa);

#endif