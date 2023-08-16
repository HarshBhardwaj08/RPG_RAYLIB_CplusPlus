#include "raylib.h"
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H


class Basecharacter
{
private:
  bool alive{true};
protected:
    Texture2D textures{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenpos{};
    Vector2 worldpos{};
    Vector2 worldlastpos{};
    float speed{5.0f};
    // flip left = 1 flip Right = -1
    float move_right{1.0f};
    // Animation Variables
    float normaltime{};
    float updatetime{1.0f / 12.0f};
    int frames{};
    int max_frames{6};
    float width{};
    float height{};
    float scale{4.0f};
     Vector2 velocity{};
    
 
public:
    Basecharacter(/* args */);
    Vector2 getWorldpos() { return worldpos; }
    void undo_movement();
    Rectangle collisoncheck();
     virtual void tick(float deltaTime);
     virtual Vector2 getScreenPos() = 0;
      bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }

};

#endif
