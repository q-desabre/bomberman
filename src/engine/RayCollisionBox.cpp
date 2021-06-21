
#include "RayCollisionBox.hpp"

namespace engine
{
  RayCollisionBox::RayCollisionBox(const v3& pos, const v3& s, CollisionType type)
    : ACollider(pos, s, type)
  {
  }
    
  bool		RayCollisionBox::collide(const ACollider &o)
  {
    Vector3	start_pos = (Vector3){position.x - size.x / 2,
				      position.y - size.y / 2,
				      position.z - size.z / 2};      
    Vector3	end_pos = (Vector3){position.x + size.x / 2,
				    position.y + size.y / 2,
				    position.z + size.z / 2};
      
    Vector3	o_start_pos = (Vector3){o.getPosition().x - o.getSize().x / 2,
					o.getPosition().y - o.getSize().y / 2,
					o.getPosition().z - o.getSize().z / 2};      
    Vector3	o_end_pos = (Vector3){o.getPosition().x + o.getSize().x / 2,
				      o.getPosition().y + o.getSize().y / 2,
				      o.getPosition().z + o.getSize().z / 2};
      
    return (CheckCollisionBoxes((BoundingBox){start_pos, end_pos},
				(BoundingBox){o_start_pos, o_end_pos}));
  }


}
