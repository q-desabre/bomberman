
#include "AActor.hpp"

namespace engine
{
  AActor::AActor() : uid(generateUid())
  {
  }

  void			AActor::update()
  {  
  }

  DrawableType		AActor::getDrawableType() const
  {
    return DrawableType::ACTOR;
  }

  const v3&		AActor::getScale() const
  {
    return this->scale;
  }

  void			AActor::setScale(const v3& newScale)
  {
    this->scale = newScale;
  }

  const v3&		AActor::getPosition() const
  {
    return position;
  }

  void			AActor::setPosition(const v3& newPos)
  {
    this->position = newPos;
  }

  void			AActor::rotate(float angle)
  {
    this->angleRotation = angle;
  }

  float			AActor::getAngleRotation() const
  {
    return this->angleRotation;
  }
    
  const v3&		AActor::getRotation() const
  {
    return rotation;
  }

  void			AActor::setRotation(const v3& newR)
  {
    this->rotation = newR;
  }

  int			AActor::getUid() const
  {
    return uid;
  }

  
}
