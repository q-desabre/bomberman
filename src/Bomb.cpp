
#include "Bomb.hpp"
#include "Cube.hpp"
#include "Player.hpp"

namespace bomber
{
  void		Bomb::lineFlame(Map &map, const v3& direction)
  {
    {
      std::shared_ptr<Flame> flame;
      
      for (int i = 1; i != power; i++) {
	flame = std::make_shared<Flame>(v3(position.x + direction.x * i,
					   position.y,
					   position.z + direction.z * i));
	for (int i = 0; i != map.getCollidableActors().size(); i++) {
	  if (map.getCollidableActors()[i]->collide(flame->getCollider())) {
	    Cube *c =  dynamic_cast<Cube *>(map.getCollidableActors()[i].get());
	    if (c)
	      if (c->getType() == BREAKABLE) {
	      	std::cout << "Collsion with BreakableCube " << c->getUid() << " !" << std::endl;
		c->spawnPowerUp();
		map.removeActor(map.getActorByUid(c->getUid()));
		map.removeCollidableActor(map.getCollidableActors()[i]);
	      }
	      else
	      	std::cout << "Collsion with UnBreakableCube!" << std::endl;
	    return ;
	  }
	}
	map.addActor(flame);
	flames.push_back(flame);
      }
    }

  }

}
