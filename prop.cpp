#include "prop.h"
#include "raymath.h"

prop::prop(Texture2D Tex, Vector2 pos):worldpos(pos),texture(Tex)
{

}

void prop::render(Vector2 heropos)
{
 Vector2 prop_pos = Vector2Subtract(worldpos,heropos);
 DrawTextureEx(texture,prop_pos,0.0,scale,WHITE);
}

 Rectangle prop::collisoncheck(Vector2 heropos)
 {
 Vector2 prop_pos = Vector2Subtract(worldpos,heropos);
 return Rectangle{
    prop_pos.x,
    prop_pos.y,
    texture.width*scale,
    texture.height*scale
 };
 }  