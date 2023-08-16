#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "Basecharacter.h"
class character : public Basecharacter
{
private:
int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};


    
public:
    character(int winWidths, int winHeights);
    virtual void tick(float deltaTime) override;
     virtual Vector2 getScreenPos() override;
      Rectangle getWeaponCollisionRec() { return weaponCollisionRec; }
   
};

#endif