
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

    // possible map on ptr method
    void		spawnPowerFlame(const v3& pos, Map &map);
    void		spawnPowerBomb(const v3& pos, Map &map);
    void		spawnPowerSpeed(const v3& pos, Map &map);
    void		spawnPowerWallPass(const v3& pos, Map &map);
    
    BlockType		getType() const;

  private:
    BlockType	type;

  };
}



#endif /* _CUBE_HPP_ */
