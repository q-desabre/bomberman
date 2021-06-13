
#ifndef _ANIMATED_CUBE_HPP_
# define _ANIMATED_CUBE_HPP_

# include "Cube.hpp"
# include "Timer.hpp"

namespace bomber
{
  class AnimatedCube : public Cube
  {
  public:
    AnimatedCube(v3 p, const std::string& path, int nbFrames) : Cube(p, "../assets/water1.png")
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
      
    void		draw()
    {
      this->texture = textures[currentFrame];
      Cube::draw();
      if (timer.getElapsedTime() >= 0.16f)
	{
	  timer.restart();
	  currentFrame++;
	  if (currentFrame >= maxFrames)
	    currentFrame = 0;
	}
    }

  private:
    engine::Timer	timer;
    int			maxFrames;
    int			currentFrame;
    std::vector<Texture2D>	textures;
  };
}


#endif /* _ANIMATED_CUBE_HPP_ */
