
#include "PowerUpFlame.hpp"

namespace bomber
{
  PowerUpFlame::PowerUpFlame(const v3& p) : APowerUp(p, "PowerUpFlame")
  {
    
  }

  void		PowerUpFlame::effect(Player &player)
  {
    player.setPower(player.getPower() + 1);
  }

}
