
#ifndef _RAYCUBE_HPP_
# define _RAYCUBE_HPP_

#include <iostream>
#include <sstream>
#include "AActor.hpp"
#include "RayCollisionBox.hpp"
#include "TextureManager.hpp"

namespace engine
{
  const float CUBE_SIZE = 1.0f;
  const float CUBE_HEIGHT = 1.0f;
  
  class RayCube : public AActor, public ICollidable
  {
  public:
    RayCube(const v3& p = Vec3<float>(0, 0, 0));
    RayCube(const v3& p = Vec3<float>(0, 0, 0), const std::string& textureName = "default");

    int				getUid() const;
    void			draw();
    void			setSize(const Vec3<float>& s);
    bool			hasTexture() const;
    const engine::ACollider&	getCollider() const;
    bool			collide(const engine::ACollider& other) const;
    
  protected:
    bool	isTextured;
    ACollider	*collisionBox;
    Texture2D	texture;
    Vec3<float>	size;
    Color	color;
  };
  
    
}


#endif /* _RAYCUBE_HPP_ */
