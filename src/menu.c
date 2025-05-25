#include "menu.h"
#include <string.h>
#include "Mavajid.h"
#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include <time.h>

Sound SelectedSound;

void DrawMenu(GameState *currentState, int selectedOption) {
    char *options[] = {"Play", "Records", "Music", "Exit"};  
    int numOptions = sizeof(options) / sizeof(options[0]);

    DrawText("MardPac", GetScreenWidth() / 2 - MeasureText("MardPac", 50) / 2, GetScreenHeight() / 2 - 150 , 50, YELLOW);

    for (int i = 0; i < numOptions; i++) {
        Color color = (i == selectedOption) ? YELLOW : WHITE;
        DrawText(options[i], GetScreenWidth() / 2 - MeasureText(options[i], 30) / 2, GetScreenHeight() / 2 - 30 + i * 30, 30, color);
    }

    UpdateSoundLoop();

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(menu2);
        switch (selectedOption) {
            case 0:
                *currentState = DIFFICULTY;
                break;
            case 1:
                *currentState = RECORDS;
                break;
            case 2:  
                *currentState = MUSIC_MENU;
                break;
            case 3:
                *currentState = EXIT;
                break;
        }
    }
}

void RunMenu(GameState *currentState) {
    int selectedOption = 0;
    const int numOptions = 4;  

    while (!WindowShouldClose() && *currentState == MENU) {
        if (IsKeyPressed(KEY_UP)) {
            PlaySound(menu1);
            selectedOption--;
            if (selectedOption < 0) selectedOption = numOptions - 1;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            PlaySound(menu1);
            selectedOption++;
            if (selectedOption >= numOptions) selectedOption = 0;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawMenu(currentState, selectedOption);

        EndDrawing();
    }
}

void RunMusicMenu(GameState *currentState) {
    int selectedOption = 0;
    char *musicOptions[] = {"Background Music", "Dariush", "Back"};
    int numOptions = sizeof(musicOptions) / sizeof(musicOptions[0]);

    while (!WindowShouldClose() && *currentState == MUSIC_MENU) {
        if (IsKeyPressed(KEY_UP)) {
            PlaySound(menu1);
            selectedOption--;
            if (selectedOption < 0) selectedOption = numOptions - 1;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            PlaySound(menu1);
            selectedOption++;
            if (selectedOption >= numOptions) selectedOption = 0;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            PlaySound(menu2);
            switch (selectedOption) {
                case 0:  
                    StopSound(Dariush);
                    StopSound(backgroundMusic);
                    SelectedSound = backgroundMusic;
                    PlaySound(backgroundMusic);
                    SetSoundVolume(SelectedSound,0.3);
                    break;
                case 1: 
                    StopSound(backgroundMusic);
                    StopSound(Dariush);
                    SelectedSound = Dariush;
                    PlaySound(Dariush);
                    SetSoundVolume(SelectedSound,1);
                    break;
                case 2: 
                    *currentState = MENU;
                    break;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Select Music", GetScreenWidth() / 2 - MeasureText("Select Music", 40) / 2, 
                 GetScreenHeight() / 2 - 150, 40, SKYBLUE);

        for (int i = 0; i < numOptions; i++) {
            Color color = (i == selectedOption) ? SKYBLUE : WHITE;
            DrawText(musicOptions[i], GetScreenWidth() / 2 - MeasureText(musicOptions[i], 30) / 2, 
                     GetScreenHeight() / 2 - 30 + i * 30, 30, color);
        }

        EndDrawing();
    }
}

void RunRecords(GameState *currentState){
    while (!WindowShouldClose() && *currentState == RECORDS) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("RECORDS", GetScreenWidth() / 2 - MeasureText("RECORDS", 40) / 2, 80, 40, RED);

        FILE *file = fopen("Record/RECORDS.txt", "r");
        for (int i = 0; i < 10; i++) {
                char addadposht[5];
                sprintf(addadposht, "%d->", (i + 1));
                char name[30];
                int emtiaz;
                char date[20];
                char emtiazlul[20];
                if (fscanf(file, "%29s %d %s", name, &emtiaz, date) == 3) {
                    sprintf(emtiazlul, "emtiaz :  %d", emtiaz);
                    DrawText(addadposht, 50, 160 + i * 40, 25, DARKBLUE);
                    DrawText(name, 100, 160 + i * 40, 25, RED);
                    DrawText(emtiazlul, 600, 160 + i * 40, 25, DARKBLUE);
                } else 
                    break; 
            }
            fclose(file);

            DrawText("Press Enter to MENU",GetScreenWidth() / 2 - MeasureText("Press Enter to MENU", 20) / 2 , GetScreenHeight() / 2 + 250,20,MAROON);

            UpdateSoundLoop();

        if (IsKeyPressed(KEY_ENTER)) {
            PlaySound(menu2);
            *currentState = MENU;
        }
        EndDrawing();
    }
}                

int sath;

void DrawDifficultyMenu(GameState *currentState, int selectedOption) {
    char *options[] = {"Easy", "Medium", "Hard"};
    int numOptions = sizeof(options) / sizeof(options[0]);

    DrawText("Select Difficulty", GetScreenWidth() / 2 - MeasureText("Select Difficulty", 40) / 2, GetScreenHeight() / 2 - 150, 40, GREEN);

    for (int i = 0; i < numOptions; i++) {
        Color color = (i == selectedOption) ? GREEN : WHITE;
        DrawText(options[i], GetScreenWidth() / 2 - MeasureText(options[i],30) / 2, GetScreenHeight() / 2 - 30 + i * 30, 30, color);
    }

    UpdateSoundLoop();

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(menu2);
        sath = selectedOption + 1;
        *currentState = CHOOSE_MAP;
    }
}

void RunDifficultyMenu(GameState *currentState) {
    int selectedOption = 0;
    int numOptions = 3;

    while (!WindowShouldClose() && *currentState == DIFFICULTY) {
        if (IsKeyPressed(KEY_UP)) {
            PlaySound(menu1);
            selectedOption--;
            if (selectedOption < 0) selectedOption = numOptions - 1;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            PlaySound(menu1);
            selectedOption++;
            if (selectedOption >= numOptions) selectedOption = 0;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawDifficultyMenu(currentState, selectedOption);

        EndDrawing();
    }
}

int selectedmap;

void DrawChooseMapMenu(GameState *currentState, int selectedOption) {
    char *options[] = {"Map 1", "Map 2", "Map 3"};
    int numOptions = sizeof(options) / sizeof(options[0]);

    DrawText("Choose Map", GetScreenWidth() / 2 - MeasureText("Choose Map", 40) / 2, GetScreenHeight() / 2 - 150, 40, VIOLET);

    for (int i = 0; i < numOptions; i++) {
        Color color = (i == selectedOption) ? VIOLET : WHITE;
        DrawText(options[i], GetScreenWidth() / 2 - MeasureText(options[i],30) / 2 - 200 + i * 200, GetScreenHeight() / 2 - 30, 30, color);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(menu2);
        selectedmap = selectedOption + 1;
        *currentState = ENTER_NAME;
    }
}

void RunChooseMapMenu(GameState *currentState) {
    int selectedOption = 0;
    int numOptions = 3;

    while (!WindowShouldClose() && *currentState == CHOOSE_MAP) {
        if (IsKeyPressed(KEY_LEFT)) {
            PlaySound(menu1);
            selectedOption--;
            if (selectedOption < 0) selectedOption = numOptions - 1;
        }
        if (IsKeyPressed(KEY_RIGHT)) {
            PlaySound(menu1);
            selectedOption++;
            if (selectedOption >= numOptions) selectedOption = 0;
        }

        UpdateSoundLoop();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawChooseMapMenu(currentState, selectedOption);

        EndDrawing();
    }
}

void RunEnterName(GameState *currentState, char *playerName) {
    int letterCount = strlen(playerName);

    while (!WindowShouldClose() && *currentState == ENTER_NAME) {
        int key = GetKeyPressed();
        if (key >= 32 && key <= 125 && letterCount < 20) {
            PlaySound(menu1);
            playerName[letterCount] = (char)key;
            playerName[letterCount + 1] = '\0';
            letterCount++;
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (letterCount > 0) {
                letterCount--;
                playerName[letterCount] = '\0';
            }
        }

        if (letterCount > 0) {
            if (IsKeyPressed(KEY_ENTER)) {
                PlaySound(menu2);
                *currentState = GAME;
            }   
        }

        UpdateSoundLoop();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Enter Your Name:", GetScreenWidth() / 2 - MeasureText("Enter Your Name:", 40) / 2, GetScreenHeight() / 2 - 150, 40, PURPLE);
        DrawText(playerName, GetScreenWidth() / 2 - MeasureText(playerName, 30) / 2, GetScreenHeight() / 2, 30, BLUE);

        EndDrawing();
    }
}

void RunGameOver(GameState *currentState){
    while (!WindowShouldClose() && *currentState == GAME_OVER) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 50) / 2, GetScreenHeight() / 2 - 120, 50, RED);
        DrawText(playername, GetScreenWidth() / 2 - MeasureText(playername, 30) / 2 - 120, GetScreenHeight() / 2 , 30, WHITE);
        char emtiaz[20];
        sprintf(emtiaz,"emtiaz : %.0lf",sekecnt*10*zarib);
        DrawText(emtiaz, GetScreenWidth() / 2 - MeasureText(emtiaz, 30) / 2 + 120, GetScreenHeight() / 2 , 30, WHITE);

        DrawText("Press Enter to MENU",GetScreenWidth() / 2 - MeasureText("Press Enter to MENU", 20) / 2 , GetScreenHeight() / 2 + 200,20,VIOLET);

        if (IsKeyPressed(KEY_ENTER)) {
            time_t now = time(NULL);
            struct tm *t = localtime(&now);
            char date[20];
            sprintf(date, "%04d-%02d-%02d", 
                    t->tm_year + 1900, 
                    t->tm_mon + 1, 
                    t->tm_mday);

            FILE *file = fopen("Record/RECORDS.txt", "a+");
            if (file) {
                fprintf(file, "%s %.0lf %s\n", playername, sekecnt * 10 * zarib, date);
                fclose(file);
            }

            Record records[500];
            int count = 0;

            file = fopen("Record/RECORDS.txt", "r");
            if (file) {
                while (fscanf(file, "%s %d %s", records[count].name, &records[count].score, records[count].date) == 3 && count < 500) {
                    count++;
                }
                fclose(file);
            }
            
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (records[j].score > records[i].score) {
                        Record temp = records[i];
                        records[i] = records[j];
                        records[j] = temp;
                    }
                }
            }

            file = fopen("Record/RECORDS.txt", "w");
            if (file) {
                for (int i = 0; i < count; i++) 
                    fprintf(file, "%s %d %s\n", records[i].name, records[i].score, records[i].date);
                
                fclose(file);
            }

            PlaySound(menu2);
            *currentState = MENU;
        }
    EndDrawing();    
    }
}