#include "Basecharacter.h"
#include "raymath.h"

Basecharacter::Basecharacter(/* args */)
{
    
}

void Basecharacter::undo_movement(){
    worldpos = worldlastpos;
}
Rectangle Basecharacter::collisoncheck()
{
    return Rectangle{
       getScreenPos().x,
        getScreenPos().y,

       width*4.0f,
       height*4.0f
    };

}
void Basecharacter::tick(float deltatime)
{   
      
      worldlastpos = worldpos;
 // update frames
    normaltime += deltatime;
    if (normaltime >= updatetime)
    {
        frames++;
        normaltime = 0;
        if (frames > max_frames)
        {
            frames = 0;
        }
    }
     if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos + velocity

        worldpos = Vector2Add(worldpos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? move_right = -1.f : move_right = 1.f;
        textures = run;
    }
    else
    {
        textures = idle;
    }
    velocity = {};

    // Draw Hero
    // source location of frames from sprite sheet

    Rectangle source{frames * width, 0.0f, move_right * width, height };
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(textures, source, dest, Vector2{}, 0.0f, WHITE);
}