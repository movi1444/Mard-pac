#include "game.h"
#include "map.h"
#include "raylib.h"
#include "Mavajid.h"
#include "menu.h"

char playername[25] = "";

int main(void) {

    InitWindow(SAFHE_TOOL, SAFHE_ERTEFA, "MardPac");
    SetTargetFPS(fps);
    

    loadTextureandAudio();

    GameState currentState = MENU;

    while (currentState != EXIT && !WindowShouldClose()) {
        
        SetSoundVolume(backgroundMusic,0.3);
        
        if (currentState == MENU) 
            RunMenu(&currentState);

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
