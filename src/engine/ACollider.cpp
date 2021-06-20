
#include "ACollider.hpp"

namespace engine
{
  ACollider::ACollider(CollisionType type)
  {
  }
  
  ACollider::ACollider(const v3& pos, const v3& s, CollisionType type)
      : position(pos), size(s), type(type)
  {
  }

  void		ACollider::setPosition(const v3& p)
  {
    this->position = p;
  }
    
  const v3&			ACollider::getPosition() const
  {
    return this->position;
  }

  const v3&			ACollider::getSize() const
  {
    return this->size;
  }

  CollisionType	ACollider::getType() const
  {
    return this->type;
  }


}
