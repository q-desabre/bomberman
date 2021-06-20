
#ifndef _RAYANIMATION_HPP_
# define _RAYANIMATION_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <Vector.hpp>
#include <sstream>
#include "AActor.hpp"
#include "raylib.h"

namespace engine
{
  class RayAnimation : public engine::AActor
  {
  public:
    RayAnimation(const std::string& path, const std::string& textureName, int nbFrames);
    virtual void	draw();
    virtual void	draw(int);
    
  protected:
    int			nbFrames;
    int			currentFrame;
    Texture2D		texture;
    Color		color;
    std::vector<Model>	models;
  };
  
    
}


#endif /* _CUBE_HPP_ */
