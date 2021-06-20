
#include "Flame.hpp"

namespace bomber
{
  Flame::Flame(const v3& pos)
  {
    v3 newPos(pos.x - std::fmod(pos.x, 1.0f), pos.y, pos.z - std::fmod(pos.z, 1.0f));
      
    this->randScale = 0.75f + (rand() % 25) / 100;
    this->currentTexture = 0;
    this->position = newPos;
    this->collisionBox = std::make_unique<engine::RayCollisionBox>(newPos, v3(0.55, 0.55, 0.55));
    this->model = LoadModelFromMesh(GenMeshSphere(0.5f, 32, 32));
    this->texture = engine::TextureManager<Texture2D>::getInstance().getTexture("flame0");
    // this->texture[1] = engine::TextureManager<Texture2D>::getInstance().getTexture("flame1");
    // this->texture[2] = engine::TextureManager<Texture2D>::getInstance().getTexture("flame1");
    // this->texture[3] = engine::TextureManager<Texture2D>::getInstance().getTexture("flame3");
    // this->texture[4] = engine::TextureManager<Texture2D>::getInstance().getTexture("flame4");
    this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
  }


  void				Flame::draw()
  {
    if (timerAnimation.getElapsedTime() >= 0.16f)
      {
	this->randScale = 0.75f + (float)(rand() % 25) / 100.0f;
	// this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture[currentTexture];
	// currentTexture++;
	// if (currentTexture == 3)
	//   currentTexture = 0;
	timerAnimation.restart();
      }
    DrawModel(model, (Vector3){position.x, position.y, position.z}, randScale, WHITE);
  }
    
  int				Flame::getUid() const
  {
    return uid;
  }

  const engine::ACollider&	Flame::getCollider() const
  {
    return *(this->collisionBox);
  }

  bool				Flame::collide(const engine::ACollider& other) const
  {
    return this->collisionBox->collide(other);
  }

}
