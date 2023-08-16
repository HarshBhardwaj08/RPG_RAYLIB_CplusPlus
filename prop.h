#include "raylib.h"

class prop
{
private:
 Texture2D texture;
 Vector2 worldpos{};
 float scale{4.0f};
 

public:
    prop(Texture2D Tex, Vector2 pos);
    void render(Vector2 heropos);
    Rectangle collisoncheck(Vector2  heropos);
   
};



