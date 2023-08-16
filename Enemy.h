#include "raylib.h"
#include "BaseCharacter.h"
#include "character.h"
class Enemy : public Basecharacter
{
public:
    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);
    
   virtual void tick(float deltaTime) override;
   void setTarget(character* character) { target = character; }
     virtual Vector2 getScreenPos() override;
   
   
private:
  character* target;
};


