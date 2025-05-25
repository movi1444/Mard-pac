#include "Mavajid.h"
#include "map.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "menu.h"
#include <string.h>

Texture pacbaste,pacbaz1,pacbaz2,pacbaz3,pacbaz4;
Texture gilas,felfel,sib,gharch,ghost,galb;
Sound dard,sekeg,mive,bakht,rooh;
Sound backgroundMusic;
Sound Dariush;
Sound menu1,menu2;

int animcounter = 0;
int sekecnt = 0;
int maxjoon;
int NUM_ARVAHSASAN;
double zarib;

bazikon bazikoon;

Texture selectedTexture;
Rooh *ARVAH;

Gilas goloos[NUM_GILAS];
Sib Sibs[NUM_SIB];
Felfel Falafel[NUM_FELFEL];
Gharch Ghrooch[NUM_GHARCH];
seke Sekes[NUM_SEKES];

double goloostimer = 0;
double falafeltimer = 0;
double cooldowntimer = 0;
double cooldown = 0;

void InitializeMavajid(void) {

    ARVAH =(Rooh *)malloc(9*sizeof(Rooh));
    sekecnt = 0;

    switch(selectedmap){
        case 1:
            memcpy(map, map1, sizeof(map1));
            Selectedmapcolor1 = DARKGRAY;
            Selectedmapcolor2 = BLACK;
            break;
        case 2:
            memcpy(map, map2, sizeof(map2));
            Selectedmapcolor1 = BROWN;
            Selectedmapcolor2 = BEIGE;
            break;
        case 3:
            memcpy(map, map3, sizeof(map3));
            Selectedmapcolor1 = BLACK;
            Selectedmapcolor2 = MAGENTA;
            break;

    }    

    double roohsorat;

    switch(sath){
        case (1):
            bazikoon.joon = maxjoon = 3;            
            NUM_ARVAHSASAN = 5;
            roohsorat = 2.5;
            cooldown = 3;
            zarib = 1;
            break;
        case (2):
            bazikoon.joon = maxjoon = 2;
            NUM_ARVAHSASAN = 7;
            roohsorat = 2.75;
            cooldown = 2;
            zarib = 1.5;
            break;
        case (3):
            bazikoon.joon = maxjoon = 1;
            NUM_ARVAHSASAN = 9;
            roohsorat = 3;
            cooldown = 1.5;
            zarib = 2;
            break;        
    }
    
    srand(time(NULL));
    int i = 0;
    while (i < NUM_ARVAHSASAN) {
        ARVAH[i].position = (Vector2){325 + i*15,540};
        ARVAH[i].sorat = roohsorat;
        ARVAH[i].direction = (Vector2){1, 0};
        ARVAH[i].color = (Color){rand() % 256, rand() % 256, rand() % 256, 255};
        ARVAH[i].is_zende = true;  
        if (!Is_divar(ARVAH[i].position)) i++;
    }

    for(int i=0;i<NUM_GILAS;i++){
        do{goloos[i].position = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20
        };
        }while(Is_divar(goloos[i].position));
        goloos[i].hast_khorde = false;
    }
    for(int i=0;i<NUM_SIB;i++){
        do{Sibs[i].position = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20
        };
        }while(Is_divar(Sibs[i].position));
        Sibs[i].hast_khorde = false;
    }
    for(int i=0;i<NUM_FELFEL;i++){
        do{Falafel[i].position = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20
        };
        }while(Is_divar(Falafel[i].position));
        Falafel[i].hast_khorde = false;
    }

    for(int i=0;i<NUM_GHARCH;i++){
        do{Ghrooch[i].position = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20
        };
        }while(Is_divar(Ghrooch[i].position));
        Ghrooch[i].hast_khorde = false;
    }

    for(int i=0;i<NUM_SEKES;i++){
        int par;
        do{
            par = 1;
            Sekes[i].position = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};

            for(int j = 0; j < NUM_GHARCH; j++) {
                if(Sekes[i].position.x == Ghrooch[j].position.x && Sekes[i].position.y == Ghrooch[j].position.y) {
                    par = 0;
                    break;
                }
            }
        
        }while(Is_divar(Sekes[i].position)|| !par);
        Sekes[i].hast_gerefteh = false;
    }
}

void UpdateMavajid(Vector2 posbazikoon,GameState *currentstate) {
    srand(time(NULL));
    for (int i = 0; i < NUM_ARVAHSASAN; i++) {
        Rooh *rooh = &ARVAH[i];
        rooh->position.x += rooh->direction.x * rooh->sorat;
        rooh->position.y += rooh->direction.y * rooh->sorat;

        if (divarkhor(rooh->position,rooh->direction)||Is_Node(rooh->position)){
            rooh->direction = Jahatbad(rooh->position);
        }
            
        if (Is_divar((Vector2){rooh->position.x - 20, rooh->position.y})) rooh->position.x += rooh->sorat;
        if (Is_divar((Vector2){rooh->position.x + 20, rooh->position.y})) rooh->position.x -= rooh->sorat;
        if (Is_divar((Vector2){rooh->position.x, rooh->position.y + 20})) rooh->position.y -= rooh->sorat;
        if (Is_divar((Vector2){rooh->position.x, rooh->position.y - 20})) rooh->position.y += rooh->sorat;
    }

    for(int i=0;i<NUM_GILAS;i++){
        if(Is_khord(posbazikoon,goloos[i].position)){
            goloos[i].hast_khorde = true;
            goloos[i].position =(Vector2){-1,-1};
            PlaySound(mive);
            goloostimer = 10.0;
        }    
    }

    for(int i=0;i<NUM_FELFEL;i++){
        if(Is_khord(posbazikoon,Falafel[i].position)){
            Falafel[i].hast_khorde = true;
            Falafel[i].position = (Vector2){-1,-1};
            PlaySound(mive);
            bazikoon.sorat = bazikoon.sorat + 1.5;
            falafeltimer = 10.0;
        }    
    }

    for(int i=0;i<NUM_SIB;i++){
        if(Is_khord(posbazikoon,Sibs[i].position)){
            Sibs[i].hast_khorde = true;
            Sibs[i].position = (Vector2){-1,-1};
            if(bazikoon.joon + 1 <= maxjoon){
                bazikoon.joon++;
                PlaySound(mive);
            }    
        }    
    }

    for(int i=0;i<NUM_GHARCH;i++){
        if(Is_khord(posbazikoon,Ghrooch[i].position)){
            Ghrooch[i].hast_khorde = true;
            Ghrooch[i].position = (Vector2){-1,-1};
            bazikoon.joon--;
            PlaySound(dard);
            cooldowntimer = cooldown;
            if(bazikoon.joon == 0){
                    StopSound(SelectedSound);
                    PlaySound(bakht);
                    cooldowntimer = 0;
                    falafeltimer = 0;
                    goloostimer = 0;
                    free(ARVAH);
                    *currentstate = GAME_OVER;
                    return;
            }
        }    
    }

    if(goloostimer > 0)
        goloostimer -= GetFrameTime();

    if(goloostimer<=0){
        for(int i=0;i<NUM_ARVAHSASAN;i++){
            if(!ARVAH[i].is_zende){
                do{
                    ARVAH[i].position =(Vector2){
                    (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
                    (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};
                }while(Is_divar(ARVAH[i].position));
                ARVAH[i].color = (Color){rand() % 256, rand() % 256, rand() % 256, 255};
                ARVAH[i].is_zende = true;
                ARVAH[i].direction = (Vector2){1,0};
            }
        }
    }

    if(falafeltimer > 0)
        falafeltimer -= GetFrameTime();
    else
        if(bazikoon.sorat > 3) bazikoon.sorat = 2.5;            

    for(int i=0;i<NUM_SEKES;i++){
        if(Is_khord(posbazikoon,Sekes[i].position)){
            Sekes[i].hast_gerefteh = true;
            Sekes[i].position = (Vector2){-1,-1};
            PlaySound(sekeg);
            sekecnt++;
        }    
    }

    for(int i=0; i<NUM_ARVAHSASAN; i++){
        if(Is_khord(posbazikoon,ARVAH[i].position) && ARVAH[i].is_zende){
            if(goloostimer > 0){
                PlaySound(rooh);
                ARVAH[i].is_zende = false;    
            }        
            else{ 
                if(cooldowntimer <= 0){
                    cooldowntimer = cooldown;
                    bazikoon.joon--;
                    PlaySound(dard);
                } 
                if(bazikoon.joon == 0){
                    StopSound(SelectedSound);
                    PlaySound(bakht);
                    cooldowntimer = 0;
                    falafeltimer = 0;
                    goloostimer = 0;
                    free(ARVAH);
                    *currentstate = GAME_OVER;
                    return;
                }                    
            }
        }        
    }

    if(cooldowntimer > 0)
        cooldowntimer -= GetFrameTime();

    int flag = 1;
    for(int i=0;i<NUM_SEKES;i++){
        if(!Sekes[i].hast_gerefteh)
            flag = 0;
    }
    if(flag){
        for(int i=0;i<NUM_SEKES;i++){
        int par;
        do{
            par = 1;
            Sekes[i].position = (Vector2){
            (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
            (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};

            for(int j = 0; j < NUM_GHARCH; j++) {
                if(Sekes[i].position.x == Ghrooch[j].position.x && Sekes[i].position.y == Ghrooch[j].position.y) {
                    par = 0;
                    break;
                }
            }
        
        }while(Is_divar(Sekes[i].position)|| !par);
        Sekes[i].hast_gerefteh = false;
    }

        for(int i=0;i<NUM_GILAS;i++){
            if(goloos[i].hast_khorde){
                goloos[i].hast_khorde = false;
                do{goloos[i].position = (Vector2){
                    (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
                    (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};
                }while(Is_divar(goloos[i].position));
            }
        }

        for(int i=0;i<NUM_SIB;i++){
            if(Sibs[i].hast_khorde){
                Sibs[i].hast_khorde = false;
                do{Sibs[i].position = (Vector2){
                    (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
                    (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};
                }while(Is_divar(Sibs[i].position));
            }
        }
        
        for(int i=0;i<NUM_FELFEL;i++){
            if(Falafel[i].hast_khorde){
                Falafel[i].hast_khorde = false;
                do{Falafel[i].position = (Vector2){
                    (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
                    (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};
                }while(Is_divar(Falafel[i].position));
            }
        }

        for(int i=0;i<NUM_GHARCH;i++){
            if(Ghrooch[i].hast_khorde){
                Ghrooch[i].hast_khorde = false;
                int par;
                do{
                    par = 1;
                    Ghrooch[i].position = (Vector2){
                    (GRID_ANDAZE / 2) * ((rand() % 19 + 1) * 2) + 20,
                    (GRID_ANDAZE / 2) * ((rand() % 14 + 1) * 2) + 20};

                    for(int j = 0; j < NUM_SEKES; j++) {
                        if(Sekes[j].position.x == Ghrooch[i].position.x && Sekes[j].position.y == Ghrooch[i].position.y) {
                            par = 0;
                            break;
                        }
                    }
        
                }while(Is_divar(Ghrooch[i].position)|| !par);
            }
        }        
    }
}

void loadTextureandAudio(){
    Image image = LoadImage("assets/4.png");
    ImageResize(&image,28,28);
    pacbaste = LoadTextureFromImage(image);

    image = LoadImage("assets/3.png");
    ImageResize(&image,28,28);
    pacbaz1 = LoadTextureFromImage(image);

    image = LoadImage("assets/3up.png");
    ImageResize(&image,28,28);
    pacbaz2 = LoadTextureFromImage(image);

    image = LoadImage("assets/3left.png");
    ImageResize(&image,28,28);
    pacbaz3 = LoadTextureFromImage(image);

    image = LoadImage("assets/3down.png");
    ImageResize(&image,28,28);
    pacbaz4 = LoadTextureFromImage(image);

    image = LoadImage("assets/7.png");
    ImageResize(&image,20,20);
    gilas = LoadTextureFromImage(image);

    image = LoadImage("assets/9.png");
    ImageResize(&image,20,20);
    sib = LoadTextureFromImage(image);

    image = LoadImage("assets/10.png");
    ImageResize(&image,20,20);
    felfel = LoadTextureFromImage(image);

    image = LoadImage("assets/gharch.png");
    ImageResize(&image,40,40);
    gharch = LoadTextureFromImage(image);

    image = LoadImage("assets/blueghost.png");
    ImageResize(&image,40,40);
    ghost = LoadTextureFromImage(image);

    image = LoadImage("assets/galb.png");
    ImageResize(&image,60,40);
    galb = LoadTextureFromImage(image);

    UnloadImage(image);

    InitAudioDevice();
    backgroundMusic = LoadSound("assets/Audio/music.mp3");
    SetSoundVolume(backgroundMusic,0.3);

    Dariush = LoadSound("assets/Audio/Dariush - Shekanjegar.mp3");
    SetSoundVolume(Dariush,1);

    SelectedSound = backgroundMusic;
    
    dard = LoadSound("assets/Audio/oof.mp3");
    SetSoundVolume(dard,0.5);

    mive = LoadSound("assets/Audio/mivah.wav");
    SetSoundVolume(mive,0.5);

    sekeg = LoadSound("assets/Audio/sekeg.wav");
    SetSoundVolume(sekeg,0.4);

    bakht = LoadSound("assets/Audio/loose.mp3");
    SetSoundVolume(bakht,0.5);

    rooh = LoadSound("assets/Audio/ghost.wav");
    SetSoundVolume(rooh,0.5);

    menu1 = LoadSound("assets/Audio/menu1.mp3");
    SetSoundVolume(menu1,1);

    menu2 = LoadSound("assets/Audio/menu2.mp3");
    SetSoundVolume(menu2,1);
}

void UpdateSoundLoop(void) {
    if (!IsSoundPlaying(SelectedSound)){
        if(SelectedSound.stream.buffer == backgroundMusic.stream.buffer)
            SetSoundVolume(SelectedSound,0.2);

        PlaySound(SelectedSound);
    }        
}

void SelectedTexture(int n){
    if(n<15)
        selectedTexture = pacbaste;
    else{
        if(IsKeyDown(KEY_RIGHT)) selectedTexture = pacbaz1;
        else if(IsKeyDown(KEY_UP)) selectedTexture = pacbaz2;
        else if(IsKeyDown(KEY_LEFT)) selectedTexture = pacbaz3;
        else if(IsKeyDown(KEY_DOWN)) selectedTexture = pacbaz4;
    }

}

void DrawMavajid(Vector2 posbazikoon) {
    
    SelectedTexture(animcounter);

    if(cooldowntimer>0.2){ 
        if(animcounter < 15) DrawTexture(selectedTexture,posbazikoon.x-14,posbazikoon.y-14,ORANGE);
        else DrawTexture(selectedTexture,posbazikoon.x-14,posbazikoon.y-14,YELLOW);
    }
    else if(goloostimer > 0.2)
        DrawTexture(selectedTexture,posbazikoon.x-14,posbazikoon.y-14,RED);

    else if(falafeltimer > 0.2)
        DrawTexture(selectedTexture,posbazikoon.x-14,posbazikoon.y-14,GREEN);    

    else 
        DrawTexture(selectedTexture,posbazikoon.x-14,posbazikoon.y-14,YELLOW);
        
    for (int i = 0; i < NUM_ARVAHSASAN; i++) {
        if(ARVAH[i].is_zende)
            DrawTexture(ghost,ARVAH[i].position.x-20,ARVAH[i].position.y-20,ARVAH[i].color);
    }

    for (int i = 0; i < NUM_GILAS; i++) {
        if (!goloos[i].hast_khorde)
            DrawTexture(gilas,goloos[i].position.x-10,goloos[i].position.y-10,WHITE);
    }

    for (int i = 0; i < NUM_SIB; i++) {
        if (!Sibs[i].hast_khorde)
            DrawTexture(sib,Sibs[i].position.x-10,Sibs[i].position.y-10,WHITE);
    }

    for (int i = 0; i < NUM_FELFEL; i++) {
        if (!Falafel[i].hast_khorde)
            DrawTexture(felfel,Falafel[i].position.x-10,Falafel[i].position.y-10,WHITE);
    }

    for (int i = 0; i < NUM_GHARCH; i++) {
        if (!Ghrooch[i].hast_khorde)
            DrawTexture(gharch,Ghrooch[i].position.x-20,Ghrooch[i].position.y-20,WHITE);
    }

    for (int i = 0; i < NUM_SEKES; i++) {
        if (!Sekes[i].hast_gerefteh)
            DrawCircleV(Sekes[i].position,5,GOLD);
    }
    for(int i = 0;i<bazikoon.joon;i++)
        DrawTexture(galb,SAFHE_TOOL-60-(i*40),7,WHITE);

    if(animcounter<30) animcounter++;
    else animcounter = 0;
}