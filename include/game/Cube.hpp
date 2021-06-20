
#ifndef _CUBE_HPP_
# define _CUBE_HPP_

# include "RayCube.hpp"

namespace bomber
{
  class Map;
  
  enum BlockType
    {
     BREAKABLE,
     UNBREAKABLE,
     BONUS
    };
  
  class Cube : public engine::RayCube
  {
  public:
    Cube(Vec3<float> p, const std::string& textureName, BlockType t = UNBREAKABLE);

    void		spawnPowerUp(const v3& pos, Map &map);
    BlockType		getType() const;

  private:
    BlockType	type;

  };
}



#endif /* _CUBE_HPP_ */
