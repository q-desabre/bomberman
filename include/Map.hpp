

#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <vector>
# include "RayCube.hpp"

namespace bomber
{
  class Map
  {
  public:
    Map(int w, int h) : width(w), height(h)
    {
      Vec3<float>	pos(w * -(CUBE_SIZE / 2) + (CUBE_SIZE / 2),
			    CUBE_HEIGHT / 2,
			    h * (CUBE_SIZE / 2) - (CUBE_SIZE / 2));

      ground = new RayCube(Vec3<float>(0, 0, 0),
			   "../assets/floor2.png");
      ground->setSize(Vec3<float>(w - 1, 0.1f, h - 1));
      
      for (int i = 0; i != width; i++) {
	pos.z = h * (CUBE_SIZE / 2) - (CUBE_SIZE / 2);
	for (int j = 0; j != height; j++) {
	  if (j == 0 || j == height - 1 || i == 0 || i == width - 1) {
	    RayCube *tmp;
	    RayCube *tmp2;

	    tmp = new RayCube(pos, "../assets/stone3.png");
	    blocks.push_back(tmp);
	    pos.y -= 1.0f;
	    tmp2 = new RayCube(pos, "../assets/stone3.png");
	    blocks.push_back(tmp2);
	    pos.y += 1.0f;
	  }
	  else if (i % 2 == 0 && j % 2 == 0) {
	    blocks.push_back(new RayCube(pos, "../assets/stone3.png"));
	  }
	  pos.z -= CUBE_SIZE;
	}
	pos.x += CUBE_SIZE;
      }

    }
    ~Map() {}

    const std::vector<RayCube *>&	getBlocks() const
    {
      return (this->blocks);
    }

    RayCube*				getGround()
    {
      return (ground);
    }
      
  private:
    RayCube			*ground;
    int				width;
    int				height;
    std::vector<RayCube *>	blocks;
  };
}

#endif /* _MAP_HPP_ */
