
#ifndef _FLAME_HPP_
# define _FLAME_HPP_

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

      this->position = newPos;
      this->collisionBox = new engine::RayCollisionBox(newPos, v3(0.55, 0.55, 0.55));
      this->model = LoadModelFromMesh(GenMeshSphere(0.5f, 32, 32));
      this->texture = LoadTexture("../assets/fire.png");
      this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
      
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
      DrawModel(model, (Vector3){position.x, position.y, position.z}, 1.0f, WHITE);
    }

    
  private:
    engine::ACollider	*collisionBox;
    engine::Timer	timer;
    Model		model;
    Texture2D		texture;

  };
}

#endif /* _FLAME_HPP_ */
