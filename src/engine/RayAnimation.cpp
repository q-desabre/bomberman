
#include "RayAnimation.hpp"
#include "TextureManager.hpp"

namespace engine
{
    RayAnimation::RayAnimation(const std::string& pathObj, const std::string& textureName,
	     int _nbFrames) : nbFrames(_nbFrames), models(_nbFrames)
    {
      this->scale.x = 0.25f;
      this->scale.y = 0.25f;
      this->scale.z = 0.25f;
      this->rotation.x = 0;
      this->rotation.y = 1;
      this->rotation.z = 0;
      currentFrame = 0;
      for (int i = 1; i <= nbFrames; i++) {
	std::stringstream	ss;

	ss << pathObj;
	if (i < 10)
	  ss << "0";
	ss << i << ".obj";
	models[i - 1] = LoadModel(ss.str().c_str());
	texture = TextureManager<Texture2D>::getInstance().getTexture(textureName);
	models[i - 1].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
      }
    }

    void		RayAnimation::draw()
    {
      DrawModelEx(models[currentFrame],
		  (Vector3){position.x, position.y, position.z},
		  (Vector3){rotation.x, rotation.y, rotation.z},
		  angleRotation,
		  (Vector3){scale.x, scale.y, scale.z}, WHITE);
      currentFrame++;
      if (currentFrame >= nbFrames)
	currentFrame = 0;
    }

    void		RayAnimation::draw(int frame)
    {
      currentFrame = 0;
      DrawModelEx(models[0],
		  (Vector3){position.x, position.y, position.z},
		  (Vector3){rotation.x, rotation.y, rotation.z},
		  angleRotation,
		  (Vector3){scale.x, scale.y, scale.z}, WHITE);
    }
  
}
