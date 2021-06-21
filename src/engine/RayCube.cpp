
#include "RayCube.hpp"

namespace engine
{
  RayCube::RayCube(const v3& p)
  {
    this->color = WHITE;
    this->isTextured = false;
    this->size.x = CUBE_SIZE;
    this->size.y = CUBE_HEIGHT;
    this->size.z = CUBE_SIZE;
    this->position.x = p.x;
    this->position.y = p.y;
    this->position.z = p.z;
    this->collisionBox = new RayCollisionBox(this->position, this->size);
  }

  RayCube::RayCube(const v3& p, const std::string& textureName)
  {
    this->isTextured = true;
    this->color = WHITE;
    texture = TextureManager<Texture2D>::getInstance().getTexture(textureName);
    this->size.x = CUBE_SIZE;
    this->size.y = CUBE_HEIGHT;
    this->size.z = CUBE_SIZE;
    this->position.x = p.x;
    this->position.y = p.y;
    this->position.z = p.z;
    this->collisionBox = new RayCollisionBox(this->position, this->size);
  }


  int			RayCube::getUid() const
  {
    return uid;
  }

  const engine::ACollider&	RayCube::getCollider() const
  {
    return *(this->collisionBox);
  }

  bool		RayCube::collide(const engine::ACollider& other) const
  {
    return this->collisionBox->collide(other);
  }


  void		RayCube::draw()
  {
    if (isTextured)
      DrawCubeTexture(this->texture, (Vector3){position.x, position.y, position.z},
		      size.x, size.y, size.z, color);
    else
      DrawCube((Vector3){position.x, position.y, position.z},
	       size.x, size.y, size.z, color);
    // DrawCubeWires((Vector3){position.x, position.y, position.z},
    // 		    size.x, size.y, size.z, BLACK);
  }

  void		RayCube::setSize(const Vec3<float>& s)
  {
    this->size.x = s.x;
    this->size.y = s.y;
    this->size.z = s.z;
  }
    
  bool		RayCube::hasTexture() const
  {
    return this->isTextured;
  }
    

}
