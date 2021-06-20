
#ifndef _ANIMATED_CUBE_HPP_
# define _ANIMATED_CUBE_HPP_

# include <vector>
# include "RayCube.hpp"
# include "Timer.hpp"

namespace engine
{
  class RayAnimatedCube : public engine::RayCube
  {
  public:
    RayAnimatedCube(const v3& p, const std::string& path, int nbFrames);

    void			draw();

  protected:
    Timer			timer;
    int				maxFrames;
    int				currentFrame;
    std::vector<Texture2D>	textures;
  };
}


#endif /* _ANIMATED_CUBE_HPP_ */
