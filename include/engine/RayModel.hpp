
#ifndef _RAYMODEL_HPP_
# define _RAYMODEL_HPP_

# include <iostream>
# include "raylib.h"
# include "AActor.hpp"

namespace engine
{
  class RayModel : public engine::AActor
  {
  public:
    RayModel(const v3 pos, const std::string& path, const std::string& pathTexture)
    {
      this->position = pos;
      this->model = LoadModel(path.c_str());
      if (pathTexture != "none") {
	this->texture = LoadTexture(pathTexture.c_str());
	this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
      }
    }

    ~RayModel()
    {

    }

    void		draw()
    {
      DrawModelEx(model, (Vector3){position.x, position.y, position.z},
		(Vector3){rotation.x, rotation.y, rotation.z},
		angleRotation,
		(Vector3){scale.x, scale.y, scale.z}, WHITE);
    }
    
  private:
    Texture2D	texture;
    Model	model;
  };
}


#endif /* _RAYMODEL_HPP_ */
