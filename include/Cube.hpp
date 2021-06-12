
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
    Cube(Vec3<float> p, const std::string& texture_path, BlockType t = UNBREAKABLE)
      : engine::RayCube(p, texture_path), type(t)
    {
    }

    ~Cube() {}

    BlockType	getType() const
    {
      return this->type;
    }
    
  private:
    BlockType	type;

  };
}



#endif /* _CUBE_HPP_ */