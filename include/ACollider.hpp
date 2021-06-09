
#ifndef _ACOLLIDABLE_HPP
# define _ACOLLIDABLE_HPP

# include "Vector.hpp"

namespace bomber
{  
  enum CollisionType
    {
     BLOCK,
     OVERLAP
    };
  
  class ACollider
  {
  public:
    ACollider(CollisionType type = BLOCK) {}
    ACollider(Vec3<float> pos, Vec3<float> s, CollisionType type = BLOCK)
      : position(pos), size(s), type(type) {}
    ~ACollider() {}

    virtual bool	collide(const ACollider &other) = 0;
    
    void		setPosition(const Vec3<float>& p)
    {
      this->position = p;
    }
    
    Vec3<float>		getPosition() const
    {
      return this->position;
    }

    Vec3<float>		getSize() const
    {
      return this->size;
    }

    virtual CollisionType	getType() const
    {
      return this->type;
    }

  protected:
    Vec3<float>		position;
    Vec3<float>		size;
    CollisionType	type;
  };
}


#endif /* _ACOLLIDABLE_HPP */
