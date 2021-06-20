
#ifndef _CUBE_HPP_
# define _CUBE_HPP_

# include "RayCube.hpp"

namespace bomber
{

  enum BlockType
    {
     BREAKABLE,
     UNBREAKABLE
    };
  
  class Cube : public engine::RayCube
  {
  public:
    Cube(Vec3<float> p, const std::string& textureName, BlockType t = UNBREAKABLE)
      : engine::RayCube(p, textureName), type(t)
    {
      type = t;
    }

    ~Cube() {}

    void		spawnPowerUp()
    {
      std::cout << __func__ << std::endl;
    }

    BlockType	getType() const
    {
      return this->type;
    }
    
  private:
    BlockType	type;

  };
}



#endif /* _CUBE_HPP_ */
