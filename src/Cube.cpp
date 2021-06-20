
#include "Cube.hpp"
#include "PowerUpFlame.hpp"
#include "Map.hpp"

namespace bomber
{
  Cube::Cube(Vec3<float> p, const std::string& textureName, BlockType t)
    : engine::RayCube(p, textureName), type(t)
  {
  }

  BlockType	Cube::getType() const
  {
    return this->type;
  }
  
  void		Cube::spawnPowerUp(const v3& pos, Map &map)
  {
    std::shared_ptr	bonus = std::make_shared<PowerUpFlame>(pos);

    map.addActor(bonus);
    map.addCollidableActor(bonus);
  }

}
