
#include "RaySkyBox.hpp"
#include "TextureManager.hpp"

namespace engine
{
  RaySkyBox::RaySkyBox(int size, const std::string& tm)
  {
    this->model = LoadModelFromMesh(GenMeshSphere(size, 64, 64));
    this->texture = TextureManager<Texture2D>::getInstance().getTexture(tm);
    this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
    this->rotation.y = 0;
    this->rotation.z = 1;
  }

    

  void		RaySkyBox::draw()
  {
    rlDisableBackfaceCulling();
    if (timer.getElapsedTime() >= 0.16f)
      {
	this->rotate(this->getAngleRotation() + 0.12f);
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
    
}
