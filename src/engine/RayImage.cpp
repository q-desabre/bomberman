
#include "RayImage.hpp"
#include "TextureManager.hpp"

namespace engine
{
  RayImage::RayImage(const v2& pos, const std::string& tm, float s)
  {
    this->texture = TextureManager<Texture2D>::getInstance().getTexture(tm);
    this->position.x = pos.x;
    this->position.y = pos.y;
    this->scale = s;
    this->color = WHITE;
  }

  void		RayImage::draw()
  {
    DrawTexture(this->texture,
		(GetScreenWidth() / 100.0f) * position.x - this->texture.width / 2,
		(GetScreenHeight() / 100.0f)  * position.y - this->texture.height / 2,
		this->color);
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
