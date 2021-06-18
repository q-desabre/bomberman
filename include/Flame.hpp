
#ifndef _FLAME_HPP_
# define _FLAME_HPP_

# include <cmath>
# include "RayCollisionBox.hpp"
# include "AActor.hpp"
# include "ICollidable.hpp"
# include "Timer.hpp"

namespace bomber
{
  class Flame : public engine::AActor, public engine::ICollidable
  {
  public:
    Flame(const v3& pos)
    {
      v3 newPos(pos.x - std::fmod(pos.x, 1.0f),
		pos.y,
		pos.z - std::fmod(pos.z, 1.0f));
      this->randTime = (rand() % 16) / 100;
      this->randScale = 0.75f + (rand() % 25) / 100;
      this->currentTexture = 0;
      this->position = newPos;
      this->collisionBox = std::make_unique<engine::RayCollisionBox>(newPos, v3(0.55, 0.55, 0.55));
      this->model = LoadModelFromMesh(GenMeshSphere(0.5f, 32, 32));
      this->texture[0] = LoadTexture("../assets/flame/flame0.png");
      this->texture[1] = LoadTexture("../assets/flame/flame1.png");
      this->texture[2] = LoadTexture("../assets/flame/flame2.png");
      this->texture[3] = LoadTexture("../assets/flame/flame3.png");
      this->texture[4] = LoadTexture("../assets/flame/flame4.png");
      this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture[0];
    }

    ~Flame()
    {

    }

    const engine::ACollider&	getCollider() const
    {
      return *(this->collisionBox);
    }

    bool		collide(const engine::ACollider& other) const
    {
      return this->collisionBox->collide(other);
    }

    void		draw()
    {
      if (timerAnimation.getElapsedTime() >= randTime)
	{
	  this->randTime = (rand() % 50) / 100;
	  this->randScale = 0.75f + (float)(rand() % 25) / 100.0f;
	  this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture[currentTexture];
	  currentTexture++;
	  if (currentTexture == 5)
	    currentTexture = 0;
	  timerAnimation.restart();
	}
      DrawModel(model, (Vector3){position.x, position.y, position.z}, randScale, WHITE);
    }
    
    int			getUid() const
    {
      return uid;
    }

    
  private:
    std::unique_ptr<engine::ACollider>	collisionBox;
    engine::Timer			timer;
    float				randScale;
    float				randTime;
    Model				model;
    int				currentTexture;
    Texture2D				texture[5];
    engine::Timer			timerAnimation;
  };
}

#endif /* _FLAME_HPP_ */
