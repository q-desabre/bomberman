
#ifndef _RAYCUBE_HPP_
# define _RAYCUBE_HPP_

#include <iostream>
#include <sstream>
#include "AActor.hpp"
#include "RayCollisionBox.hpp"

namespace bomber
{
  const float CUBE_SIZE = 1.0f;
  const float CUBE_HEIGHT = 1.0f;
  
  class RayCube : public AActor, public ICollidable
  {
  public:
    RayCube(Vec3<float> p = Vec3<float>(0, 0, 0),
	    Color c = WHITE) : color(c)
    {
      this->isTextured = false;
      this->size.x = CUBE_SIZE;
      this->size.y = CUBE_HEIGHT;
      this->size.z = CUBE_SIZE;
      this->position.x = p.x;
      this->position.y = p.y;
      this->position.z = p.z;
      this->collisionBox = new RayCollisionBox(this->position, this->size);
    }

    RayCube(Vec3<float> p = Vec3<float>(0, 0, 0),
	    const std::string& texture_path = "../assets/default.png")
    {
      this->isTextured = true;
      this->color = WHITE;
      texture = LoadTexture(texture_path.c_str());
      //      SetTextureFilter(this->texture, TEXTURE_FILTER_TRILINEAR); 
      this->size.x = CUBE_SIZE;
      this->size.y = CUBE_HEIGHT;
      this->size.z = CUBE_SIZE;
      this->position.x = p.x;
      this->position.y = p.y;
      this->position.z = p.z;
      this->collisionBox = new RayCollisionBox(this->position, this->size);
    }

    ~RayCube()
    {

    }

    const ACollider&	getCollider() const
    {
      return *(this->collisionBox);
    }

    bool		collide(const ACollider& other) const
    {
      return this->collisionBox->collide(other);
    }


    void		draw(int frame = 1)
    {
      DrawCubeTexture(this->texture, (Vector3){position.x, position.y, position.z},
	       size.x, size.y, size.z, color);
      DrawCubeWires((Vector3){position.x, position.y, position.z},
		    size.x, size.y, size.z, DARKGRAY);
    }

    void		draw()
    {
      // DrawCube((Vector3){position.x, position.y, position.z},
      // 	       size.x, size.y, size.z, color);
      DrawCubeTexture(this->texture, (Vector3){position.x, position.y, position.z},
      	       size.x, size.y, size.z, color);
      // DrawCubeWires((Vector3){position.x, position.y, position.z},
      // 		    size.x, size.y, size.z, BLACK);
    }

    void		setSize(const Vec3<float>& s)
    {
      this->size.x = s.x;
      this->size.y = s.y;
      this->size.z = s.z;
    }
    
    bool		hasTexture() const
    {
      return this->isTextured;
    }
    
  protected:
    bool	isTextured;
    ACollider	*collisionBox;
    Texture2D	texture;
    Vec3<float>	size;
    Color	color;
  };
  
    
}


#endif /* _RAYCUBE_HPP_ */
