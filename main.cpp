#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "prop.h"
#include "Enemy.h"



int main()
{    
    // size of pop screen
    int width_screen = 384;
    int height_screen = 384;
    float mapscale{4.0f};
    // call of pop screen
    InitWindow(width_screen, height_screen, "top down rpg ");
    // Load Texture Background
    Texture2D Background = LoadTexture("nature_tileset/OpenWorld.png");
    Vector2 pos_bg = {0.0, 0.0};
    //Player 
    character hero(width_screen, height_screen);
    //Props
     prop props[2] {
           prop{LoadTexture("nature_tileset/Rock.png"),Vector2{600.0f,300.0f}},
            prop{LoadTexture("nature_tileset/Log.png"),Vector2{400.0f,500.0f}}
       } ;
        Enemy goblin{
        Vector2{},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    };
    goblin.setTarget(&hero);


    // Game Loop
    SetTargetFPS(60);
    while (WindowShouldClose() == IsKeyDown(KEY_ESCAPE))
    {
        
        BeginDrawing();

        ClearBackground(WHITE);
        pos_bg = Vector2Scale(hero.getWorldpos(),-1.0f);
        // Draw BG
        DrawTextureEx(Background, pos_bg, 0.0, 4.0, WHITE);
       
       
        for (auto objects : props)
        {
            objects.render(hero.getWorldpos());
        }
        for (auto objects : props){
            if(CheckCollisionRecs(hero.collisoncheck(),objects.collisoncheck(hero.getWorldpos()))){
               hero.undo_movement();
            }
        }
      
      

          hero.tick(GetFrameTime());

       if (hero.getWorldpos().x < 0.f ||
            hero.getWorldpos().y < 0.f ||
            hero.getWorldpos().x + width_screen > Background.width * mapscale ||
            hero.getWorldpos().y + height_screen > Background.height * mapscale)
        {
            hero.undo_movement();
           
        }
        
      
          goblin.tick(GetFrameTime());
           if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionRecs(goblin.get, hero.getWeaponCollisionRec()))
            {
                goblin.setAlive(false);
            }
        }

        EndDrawing();
    }
    CloseWindow();
}