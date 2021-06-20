
#include "Bomb.hpp"
#include "Cube.hpp"
#include "Player.hpp"

namespace bomber
{
  Bomb::Bomb(const v3& pos, int p, int uid) : lifespan(2), power(p), ownerUid(uid)
  {
    this->isOverOwner = true;
    this->alive = true;
    this->exploded = false;
    snapToGrid(pos);
    this->model = std::make_unique<engine::RayModel>(position, "../assets/AquaBomb/AquaBomb.obj",
						     "none");
    this->scale.x = 0.08f;
    this->scale.y = 0.08f;
    this->scale.z = 0.08f;
    this->model->setScale(this->scale);
    this->model->rotate(180);
    this->collisionBox = std::make_unique<engine::RayCollisionBox>(this->model->getPosition(),
								   v3(0.55, 0.55, 0.55));
  }

  void			Bomb::explode(Map &map)
  {
    if (!exploded) {
      exploded = true;
      std::shared_ptr<Flame> flame = std::make_shared<Flame>(v3(position.x, position.y, position.z));
      map.addActor(flame); // MOVE IT
      flames.push_back(flame);  // MOVE IT
      lineFlame(map, v3(1, 0, 0));
      lineFlame(map, v3(-1, 0, 0));
      lineFlame(map, v3(0, 0, 1));
      lineFlame(map, v3(0, 0, -1));
      this->model->setPosition(v3(position.x, position.y - 5, position.z));
      map.removeActor(map.getActorByUid(getUid()));
      map.removeCollidableActor(map.getCollidableActorByUid(getUid()));
      timer.restart();
    }
  }
    
  void			Bomb::update(Map &map)
  {
    if (timer.getElapsedTime() > lifespan && !exploded) 
      explode(map);
    if (timer.getElapsedTime() > lifespan && exploded) {
      for (int i = 0; i != flames.size(); i++)
	{
	  map.removeActor(flames[i]);
	  alive = false;
	}
      flames.clear();
    }
  }
      
    
  void		Bomb::draw()
  {
    model->draw();
  }


  void		Bomb::snapToGrid(const v3& pos)
  {
    this->position = pos;
    float fmody = std::fmod(position.z, 1.0f);
    if (fmody >= 0.5f)
      this->position.z += (1 - fmody);
    else if (fmody >= 0)
      this->position.z -= fmody;
    else if (fmody < 0 && fmody >= -0.5f)
      this->position.z += (-fmody);
    else if (fmody < -0.5f) {
      this->position.z -= (1 + fmody);
    }
    float fmodx = std::fmod(position.x, 1.0f);
    if (fmodx < -0.5f)
      position.x -= (1 + std::fmod(position.x, 1.0f));
    else if (fmodx < 0 && fmodx >= -0.5f)
      position.x += (-fmodx);
    else if (fmodx >= 0 && fmodx < 0.5f)
      position.x -= fmodx;
    else if (fmodx >= 0.5f)
      position.x +=  (1 - fmodx);
  }

  
  bool		Bomb::collideWithCube(Map & map, int i)
  {
    Cube *c =  dynamic_cast<Cube *>(map.getCollidableActors()[i].get());
    if (c && c->getType() == BREAKABLE) {
      c->spawnPowerUp(c->getPosition(), map);
      map.removeActor(map.getActorByUid(c->getUid()));
      map.removeCollidableActor(map.getCollidableActors()[i]);
      return true;
    }
    return (c != NULL);
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

  bool				Bomb::isAlive() const
  {
    return this->alive;
  }
  
  int				Bomb::getUid() const
  {
    return this->uid;
  }
  
  int				Bomb::getOwnerUid() const
  {
    return this->ownerUid;
  }
  
  bool				Bomb::getIsOverOwner() const
  {
    return this->isOverOwner;
  }
  
  void				Bomb::setIsOverOwner(bool b)
  {
    this->isOverOwner = b;
  }
  
  bool				Bomb::collide(const engine::ACollider& other) const
  {
    return this->collisionBox->collide(other);
  }
  
  const engine::ACollider&	Bomb::getCollider() const
  {
    return *(this->collisionBox);
  }


}
