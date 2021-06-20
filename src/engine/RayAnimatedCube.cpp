
#include "RayAnimatedCube.hpp"

namespace engine
{
  RayAnimatedCube::RayAnimatedCube(const v3& p, const std::string& path, int nbFrames)
    : RayCube(p, "../assets/water1.png")
  {
    maxFrames = nbFrames;
    currentFrame = 0;
    for (int i = 1; i <= nbFrames; i++) {
      std::stringstream	ss;
      
      ss << path;
      ss << i << ".png";
      textures.push_back(LoadTexture(ss.str().c_str()));
    }
    texture = textures[0];
  }
      
  void		RayAnimatedCube::draw()
  {
    this->texture = textures[currentFrame];
    RayCube::draw();
    if (timer.getElapsedTime() >= 0.16f)
      {
	timer.restart();
	currentFrame++;
	if (currentFrame >= maxFrames)
	  currentFrame = 0;
      }
  }


}
