#include "map.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "menu.h"

int map1[15][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int map2[15][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int map3[15][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int map[15][20];

Color Selectedmapcolor1;
Color Selectedmapcolor2;


bool Is_divar(Vector2 pos) {
    int x = pos.x / GRID_ANDAZE;
    int y = pos.y / GRID_ANDAZE;
    if (x >= 0 && x < 20 && y >= 0 && y < 15) {
        return map[y][x] == 1; 
    }
    return false;
}

void DrawMap(void) {
    for (int y = 0; y < 15; y++) {
        for (int x = 0; x < 20; x++) {
            if (map[y][x] == 1) {
                DrawRectangle(x * GRID_ANDAZE, y * GRID_ANDAZE, GRID_ANDAZE, GRID_ANDAZE, Selectedmapcolor1);
            }
            else 
                DrawRectangle(x * GRID_ANDAZE, y * GRID_ANDAZE, GRID_ANDAZE, GRID_ANDAZE, Selectedmapcolor2);
        }
    }
}

bool divarkhor(Vector2 pos,Vector2 direction){
    int m = direction.x , n =direction.y;

    if(m) 
        if(Is_divar((Vector2){pos.x + GRID_ANDAZE/2*m,pos.y})) return true;
    if(n) 
        if(Is_divar((Vector2){pos.x,pos.y + GRID_ANDAZE/2*n})) return true;    
}

bool Is_Node(Vector2 pos){
    int x,y;

    if((pos.x / GRID_ANDAZE) - (int)(pos.x / GRID_ANDAZE) < 0.6
    && (pos.x / GRID_ANDAZE) - (int)(pos.x / GRID_ANDAZE) > 0.4)
        x = pos.x / GRID_ANDAZE;
    else 
       return false;    
    if((pos.y / GRID_ANDAZE) - (int)(pos.y / GRID_ANDAZE) < 0.6
    && (pos.y / GRID_ANDAZE) - (int)(pos.y / GRID_ANDAZE) > 0.4)
        y = pos.y / GRID_ANDAZE;
    else 
        return false;    

    Vector2 Jahatha[4] = {{1,0},{-1,0},{0,1},{0,-1}};

    int cnt = 0;
    for(int i=0;i<4;i++){
        int m = Jahatha[i].x , n =Jahatha[i].y;
        if(map[y][x+m] == 0 && map[y+n][x] == 0)
            cnt++;
    }
    if(cnt>2) return true;
    else return false;
}

Vector2 Jahatbad(Vector2 pos){
    srand(time(NULL));
    int x = pos.x / GRID_ANDAZE;
    int y = pos.y / GRID_ANDAZE;

    Vector2 Jahatha[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    Vector2 Jahathabad[4];

    int cnt=0;
    for(int i=0;i<4;i++){
        int m = Jahatha[i].x , n =Jahatha[i].y;
        if(map[y][x+m] == 0 && map[y+n][x] == 0){
            Jahathabad[cnt].x = Jahatha[i].x;
            Jahathabad[cnt].y = Jahatha[i].y;
            cnt++;
        }
    }
    Vector2 Jahatbadi;
    int index = rand()%cnt;
    Jahatbadi.x = Jahathabad[index].x; Jahatbadi.y = Jahathabad[index].y;

    return Jahatbadi; 
}

float fasele(Vector2 pos1,Vector2 pos2){
    float fasele = sqrt((pos1.x-pos2.x)*(pos1.x-pos2.x)+(pos1.y-pos2.y)*(pos1.y-pos2.y));
    return fasele;
}

bool Is_khord(Vector2 pos1,Vector2 pos2){
    if(fasele(pos1,pos2)<18) return true;
    else return false;
}

Vector2 randompos(int tool,int ertefa){
    Vector2 pos;
    do{ 
        pos = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % (tool - 1) + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % (ertefa - 1) + 1) * 2) + 20};
    }while(Is_divar(pos));
    
    return pos;
}