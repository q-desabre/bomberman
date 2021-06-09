
#ifndef _CUBE_HPP_
# define _CUBE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <Vector.hpp>
#include <sstream>
#include "IModel.hpp"

namespace bomber
{
  class RayModel : public AActor
  {
  public:
    RayModel(const std::string& pathObj, const std::string& pathTexture,
	     int _nbFrames) : nbFrames(_nbFrames), models(_nbFrames)
    {
      this->scale.x = 0.15f;
      this->scale.y = 0.15f;
      this->scale.z = 0.15f;
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
	std::cout << ss.str() << std::endl;
	models[i - 1] = LoadModel(ss.str().c_str());
	texture = LoadTexture(pathTexture.c_str());
	//	SetTextureFilter(this->texture, TEXTURE_FILTER_ANISOTROPIC_16X); 
	models[i - 1].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
      }
    }

    ~RayModel()
    {

    }

    virtual void		draw()
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

    virtual void		draw(int frame)
    {
      currentFrame = 0;
      DrawModelEx(models[0],
		  (Vector3){position.x, position.y, position.z},
		  (Vector3){rotation.x, rotation.y, rotation.z},
		  angleRotation,
		  (Vector3){scale.x, scale.y, scale.z}, WHITE);
    }

  protected:
    int			nbFrames;
    int			currentFrame;
    Texture2D		texture;
    Color		color;
    std::vector<Model>	models;
  };
  
    
}


#endif /* _CUBE_HPP_ */
