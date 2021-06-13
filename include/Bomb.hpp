
#ifndef _BOMB_HPP_
# define _BOMB_HPP_

#include "AActor.hpp"
#include "RayModel.hpp"
#include "Timer.hpp"
#include "Flame.hpp"

namespace bomber
{
  class Bomb : public engine::AActor, public engine::ICollidable
  {
  public:
    Bomb(const v3& pos, int p)
      : lifespan(3), power(p), model(v3(pos.x - std::fmod(pos.x, 1.0f),
					pos.y,
					pos.z - std::fmod(pos.z, 1.0f)),
				     "../assets/bomb/bomb.obj", "../assets/bomb/bomb.png")
    {
      this->position = v3(pos.x - std::fmod(pos.x, 1.0f),
			  pos.y,
			  pos.z - std::fmod(pos.z, 1.0f));
      this->scale.x = 0.4f;
      this->scale.y = 0.4f;
      this->scale.z = 0.4f;
      this->model.setScale(this->scale);
      this->model.rotate(180);
      this->collisionBox = new engine::RayCollisionBox(this->model.getPosition(),
						       v3(0.55, 0.55, 0.55));
    }
    ~Bomb()
    {

    }

    void		update(Map &map)
    {
      if (timer.getElapsedTime() > lifespan) {
	lifespan = 20000;
	map.addActor(new Flame(v3(position.x, position.y, position.z)));
	for (int i = 0; i != power; i++) {
	  if (map.getData()[this->position.z + i][this->position.x] == ' ') {
	    std::cout << "!!!!!!!" << std::endl;
	  }
	}
	map.removeActor(this);
	//	std::cout << "Boom" << std::endl;
      }
    }
    
    void		draw()
    {
      model.draw();
    }

    const engine::ACollider&	getCollider() const
    {
      return *(this->collisionBox);
    }

    bool		collide(const engine::ACollider& other) const
    {
      return this->collisionBox->collide(other);
    }

    
  private:
    float		lifespan;
    int			power;
    engine::Timer	timer;
    engine::RayModel	model;
    engine::ACollider	*collisionBox;
  };
};

#endif /* _BOMB_HPP_ */
