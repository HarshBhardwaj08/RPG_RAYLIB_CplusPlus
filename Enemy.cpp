#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) 
    
{  
     worldpos = pos;
    textures = idle_texture;
    idle = idle_texture;
    run = run_texture;

    width = textures.width / max_frames;
    height = textures.height;
    speed = 3.4f;
}

void Enemy::tick(float deltaTime)
{
     if (!getAlive()) return;
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
   Basecharacter::tick(deltaTime);
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldpos, target->getWorldpos());
}

