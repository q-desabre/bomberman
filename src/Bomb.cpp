
#include "Bomb.hpp"
#include "Cube.hpp"
#include "Player.hpp"

namespace bomber
{

  void		Bomb::collideWithCube(Map & map, int i)
  {
    Cube *c =  dynamic_cast<Cube *>(map.getCollidableActors()[i].get());
    if (c)
      if (c->getType() == BREAKABLE) {
	std::cout << "Collsion with BreakableCube " << c->getUid() << " !" << std::endl;
	c->spawnPowerUp();
	map.removeActor(map.getActorByUid(c->getUid()));
	map.removeCollidableActor(map.getCollidableActors()[i]);
      }
  }

  void		Bomb::collideWithPlayer(Map & map, int i)
  {
    Player *p =  dynamic_cast<Player *>(map.getCollidableActors()[i].get());
    if (p) {
      p->die();
      std::cout << "Collide with Player" << std::endl;
    }
  }
  
  void		Bomb::collideWithBomb(Map & map, int i)
  {
    Bomb *b =  dynamic_cast<Bomb *>(map.getCollidableActors()[i].get());
    if (b) {
      std::cout << "Collide with Bomb" << std::endl;
    }
  }
  
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
	    std::cout << "COLLIDE ! " << std::endl;
	    collideWithCube(map, i);
	    collideWithPlayer(map, i);
	    collideWithBomb(map, i);
	    return ;
	  }
	}
	map.addActor(flame);
	flames.push_back(flame);
      }
    }

  }

}
