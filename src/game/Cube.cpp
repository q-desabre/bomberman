
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
    int			spawnRand = rand() % 6;

    switch (spawnRand)
      {
      case 1:
	spawnPowerFlame(pos, map);
	break;
      case 2:
	spawnPowerBomb(pos, map);
	break;
      case 3:
	spawnPowerSpeed(pos, map);
	break;
      case 4:
	spawnPowerWallPass(pos, map);
	break;
      default:
	return;
      }
  }

  void		Cube::spawnPowerFlame(const v3& pos, Map &map)
  {
    std::shared_ptr bonus = std::make_shared<PowerUpFlame>(pos);
    map.addActor(bonus);
    map.addCollidableActor(bonus);
  }
  
  void		Cube::spawnPowerBomb(const v3& pos, Map &map)
  {
    std::shared_ptr bonus = std::make_shared<PowerUpBomb>(pos);
    map.addActor(bonus);
    map.addCollidableActor(bonus);
  }
  
  void		Cube::spawnPowerSpeed(const v3& pos, Map &map)
  {
    std::shared_ptr bonus = std::make_shared<PowerUpSpeed>(pos);
    map.addActor(bonus);
    map.addCollidableActor(bonus);
  }
  
  void		Cube::spawnPowerWallPass(const v3& pos, Map &map)
  {
    std::shared_ptr bonus = std::make_shared<PowerUpWallPass>(pos);
    map.addActor(bonus);
    map.addCollidableActor(bonus);
  }
  
}
