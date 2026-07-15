Hellop
# 🕹️ Mard-pac

A custom Pac-Man clone built from the ground up. Navigate the maze, eat the dots, and experience an unexpectedly dramatic aesthetic while dodging whatever is chasing you.

## 🛠️ Tech Stack
*   **Language:** C
*   **Graphics & Audio Framework:** `raylib`

## 🎵 The Vibe
This isn't your standard arcade game. The background music features a completely unexpected, emotionally devastating soundtrack, ensuring maximum tension while you secure that high score.

## 📂 Project Structure

```text
Mard-pac/
│
├── src/                         # Source code files (main.c, map.c, game.c, etc.)
├── .vscode/                     # VS Code workspace settings
│   ├── settings.json           
│   └── tasks.json               # Build tasks
├── assets/                      # Game sprites and audio
│   ├── 3.png, 4.png, 7.png...   # Custom game assets
│   ├── 3up.png, 3down.png...    # Directional sprites for movement
│   └── Audio/                  
│       └── [SECRET_TRACK].mp3   # You'll know it when you hear it
├── Record/                     
│   └── RECORDS.txt              # High scores and game records
├── Mardpac.exe                  # Compiled Windows executable
└── README.txt                   # Legacy readme
```
## ⚙️ Compile project with:
gcc src/main.c src/map.c src/Mavajid.c src/game.c src/menu.c -Iraylib -Lraylib -lraylib -lwinmm -lgdi32 -luser32 -lkernel32 -lm -o Mardpac -mwindows

## 🚀 How to Play
Compile the game using the command above, or just use the pre-built Mardpac.exe.

Turn your volume all the way up for the full experience.

Run the executable to start the game.

