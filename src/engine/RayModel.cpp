
#include "RayModel.hpp"
#include "TextureManager.hpp"

namespace engine
{
  RayModel::RayModel(const v3 pos, const std::string& path, const std::string& tm)
  {
    this->position = pos;
    this->model = LoadModel(path.c_str());
    if (tm != "none") {
      this->texture = TextureManager<Texture2D>::getInstance().getTexture(tm);
      this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->texture;
    }
  }

  void		RayModel::draw()
  {
    DrawModelEx(model, (Vector3){position.x, position.y, position.z},
		(Vector3){rotation.x, rotation.y, rotation.z},
		angleRotation,
		(Vector3){scale.x, scale.y, scale.z}, WHITE);
  }
    

}
