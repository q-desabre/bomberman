
#ifndef _RAY_BOX_COLLISION_
# define _RAY_BOX_COLLISION_

# include "raylib.h"
# include "ICollidable.hpp"

namespace engine
{
  class RayCollisionBox : public ACollider
  {
  public:
    RayCollisionBox(const v3& pos, const v3& s, CollisionType type = BLOCK);

    bool		collide(const ACollider &o);
  };
}


#endif /* _RAY_BOX_COLLISION_ */
