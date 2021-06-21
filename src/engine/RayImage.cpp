
#include "RayImage.hpp"
#include "TextureManager.hpp"

namespace engine
{
  RayImage::RayImage(const v2& pos, const std::string& tm, float s)
  {
    this->position.x = pos.x;
    this->position.y = pos.y;
    this->texture = TextureManager<Texture2D>::getInstance().getTexture(tm);
    this->scale = s;
    this->color = WHITE;
  }

  void		RayImage::draw()
  {
    DrawTexture(this->texture, this->position.x, this->position.y, this->color);
  }

  void		RayImage::setScale(float s)
  {
    this->scale = s;
  }
    
  float		RayImage::getScale() const
  {
    return this->scale;
  }
    
  void		RayImage::setTint(Color c)
  {
    this->color = c;
  }
    
}
