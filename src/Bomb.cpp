
#include "Bomb.hpp"
#include "Cube.hpp"
#include "Player.hpp"

namespace bomber
{

  bool		Bomb::collideWithCube(Map & map, int i)
  {
    Cube *c =  dynamic_cast<Cube *>(map.getCollidableActors()[i].get());
      if (c && c->getType() == BREAKABLE) {
	c->spawnPowerUp();
	map.removeActor(map.getActorByUid(c->getUid()));
	map.removeCollidableActor(map.getCollidableActors()[i]);
	return true;
      } else if (c)
	return true;
    return false;
  }

  bool		Bomb::collideWithPlayer(Map & map, int i)
  {
    Player *p =  dynamic_cast<Player *>(map.getCollidableActors()[i].get());
    if (p) {
      p->die();
      return true;
    }
    return false;
  }
  
  bool		Bomb::collideWithBomb(Map & map, int i)
  {
    Bomb *b =  dynamic_cast<Bomb *>(map.getCollidableActors()[i].get());
    if (b) {
      b->explode(map);
      return true;
    }
    return false;
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
	    if (collideWithCube(map, i))
	      return;
	    if (collideWithPlayer(map, i))
	      continue;
	    if (collideWithBomb(map, i))
	      return ;
	  }
	}
	map.addActor(flame);
	flames.push_back(flame);
      }
    }

  }

}
