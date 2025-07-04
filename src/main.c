#include "game.h"
#include "map.h"
#include "raylib.h"
#include "Mavajid.h"
#include "menu.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char playername[25] = "";

int main(void) {

    srand(time(NULL));
    InitWindow(SAFHE_TOOL, SAFHE_ERTEFA, "MardPac");
    SetTargetFPS(fps);
    

    loadTextureandAudio();

    GameState currentState = MENU;

    while (currentState != EXIT && !WindowShouldClose()) {
        
        if (currentState == MENU) 
            RunMenu(&currentState);

        else if (currentState == MUSIC_MENU)
            RunMusicMenu(&currentState);

        else if (currentState == DIFFICULTY)
            RunDifficultyMenu(&currentState);

        else if(currentState == CHOOSE_MAP)
            RunChooseMapMenu(&currentState);     

        else if(currentState == ENTER_NAME)
            RunEnterName(&currentState,playername);     

        else if (currentState == GAME){
            SetSoundVolume(backgroundMusic,0.5); 
            GameLoop(&currentState);
        }
        else if (currentState == RECORDS) 
            RunRecords(&currentState);

        else if(currentState == GAME_OVER)
            RunGameOver(&currentState);
                
        
    } 
    CloseAudioDevice();
    CloseWindow(); 

    return 0;
}
