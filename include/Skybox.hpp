

#ifndef _SKYBOX_HPP
# define _SKYBOX_HPP

# include "rlgl.h"
# include "IDrawable.hpp"
# include "Timer.hpp"

namespace engine
{
  class RaySkyBox : public AActor
  {
  public:
    RaySkyBox(int size, const std::string& texture_path)
    {
      this->model = LoadModelFromMesh(GenMeshSphere(size, 64, 64));
      this->texture = LoadTexture(texture_path.c_str());
      this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
    }

    

    void		draw()
    {
      rlDisableBackfaceCulling();
      if (timer.getElaspedTime() >= 0.16f)
      	{
      	  this->rotate(this->getAngleRotation() + 1.0f);
      	  if (this->getAngleRotation() >= 360)
      	    this->rotate(0.0f);
      	}
	
      DrawModelEx(model,
		  (Vector3){position.x, position.y, position.z},
		  (Vector3){rotation.x, rotation.y, rotation.z},
		  angleRotation,
		  (Vector3){scale.x, scale.y, scale.z}, WHITE);
      rlEnableBackfaceCulling();      
    }
    
    void		draw(int f = 0)
    {
      rlDisableBackfaceCulling();
      DrawModel(this->model, (Vector3){0, 0, 0}, 1.0f, WHITE);
      rlEnableBackfaceCulling();      
    }

  private:
    Timer		timer;
    Model		model;
    Texture2D		texture;
  };

}


#endif /* _SKYBOX_HPP */
