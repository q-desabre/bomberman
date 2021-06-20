
#ifndef _ACOLLIDABLE_HPP
# define _ACOLLIDABLE_HPP

# include "Vector.hpp"

namespace engine
{  
  enum CollisionType
    {
     BLOCK,
     OVERLAP
    };
  
  class ACollider
  {
  public:
    ACollider(CollisionType type = BLOCK);
    ACollider(const v3& pos, const v3& s, CollisionType type = BLOCK);
 
    virtual bool		collide(const ACollider &other) = 0;
    
    void			setPosition(const Vec3<float>& p);
    const v3&			getPosition() const;
    const v3&			getSize() const;
    CollisionType		getType() const;

  protected:
    Vec3<float>		position;
    Vec3<float>		size;
    CollisionType	type;
  };
}


#endif /* _ACOLLIDABLE_HPP */
