
#ifndef _BOMB_HPP_
# define _BOMB_HPP_

#include <memory>
#include "AActor.hpp"
#include "RayModel.hpp"
#include "Timer.hpp"
#include "Flame.hpp"
#include "Map.hpp"

namespace bomber
{
  class Cube;
  
  class Bomb : public engine::AActor, public engine::ICollidable
  {
  public:
    Bomb(const v3& pos, int p)
      : lifespan(3), power(p)
    {
      this->alive = true;
      this->exploded = false;
      std::cout << "Player -> " << pos;
      snapToGrid(pos); // check other side of map
      this->model = std::make_unique<engine::RayModel>(position,
						       "../assets/bomb/bomb.obj",
						       "../assets/bomb/bomb.png");
      this->scale.x = 0.4f;
      this->scale.y = 0.4f;
      this->scale.z = 0.4f;
      this->model->setScale(this->scale);
      this->model->rotate(180);
      this->collisionBox = std::make_unique<engine::RayCollisionBox>(this->model->getPosition(),
								     v3(0.55, 0.55, 0.55));
    }
    ~Bomb()
    {

    }

    void		lineFlame(Map &map, const v3& direction);
	  

    void		update(Map &map)
    {
      if (timer.getElapsedTime() > lifespan && exploded == false) {
	exploded = true;
	std::shared_ptr<Flame> flame = std::make_shared<Flame>(v3(position.x, position.y, position.z));
	map.addActor(flame);
	flames.push_back(flame);
	lineFlame(map, v3(1, 0, 0));
	lineFlame(map, v3(-1, 0, 0));
	lineFlame(map, v3(0, 0, 1));
	lineFlame(map, v3(0, 0, -1));
	this->model->setPosition(v3(position.x, position.y - 5, position.z));
	timer.restart();
      }
      if (timer.getElapsedTime() > lifespan && exploded) {
	for (int i = 0; i != flames.size(); i++)
	  {
	    map.removeActor(flames[i]);
	    alive = false;
	  }
	flames.clear();
      }
    }
      
    
    void		draw()
    {
      model->draw();
    }

    const engine::ACollider&	getCollider() const
    {
      return *(this->collisionBox);
    }

    bool		collide(const engine::ACollider& other) const
    {
      return this->collisionBox->collide(other);
    }

    bool			isAlive() const
    {
      return alive;
    }

    int			getUid() const
    {
      return uid;
    }

  private:

    void		snapToGrid(const v3 pos)
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

    void		collideWithCube(Map & map, int i);
    void		collideWithPlayer(Map & map, int i);
    void		collideWithBomb(Map & map, int i);
    
  private:
    bool		alive;
    bool		exploded;
    float		lifespan;
    int			power;
    engine::Timer	timer;
    std::vector<std::shared_ptr<Flame>>	flames;
    std::unique_ptr<engine::RayModel>	model;
    std::unique_ptr<engine::ACollider>	collisionBox;
  };
};

#endif /* _BOMB_HPP_ */
