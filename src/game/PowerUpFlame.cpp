
#include "PowerUpFlame.hpp"

namespace bomber
{
  // FLAME
  
  PowerUpFlame::PowerUpFlame(const v3& p) : APowerUp(p, "PowerFlame")
  {
    
  }

  void		PowerUpFlame::effect(Player &player)
  {
    player.setPower(player.getPower() + 1);
  }

  // BOMB
  
  PowerUpBomb::PowerUpBomb(const v3& p) : APowerUp(p, "PowerBomb")
  {
    
  }

  void		PowerUpBomb::effect(Player &player)
  {
    player.setBombMax(player.getBombMax() + 1);
  }

  // SPEED

  PowerUpSpeed::PowerUpSpeed(const v3& p) : APowerUp(p, "PowerSpeed")
  {
    
  }

  void		PowerUpSpeed::effect(Player &player)
  {
    player.setSpeed(player.getSpeed() + 0.1f);
  }

  // Wall PASS

  PowerUpWallPass::PowerUpWallPass(const v3& p) : APowerUp(p, "PowerWallPass")
  {
    
  }

  void		PowerUpWallPass::effect(Player &player)
  {
    player.setWallPass(true);
  }
  
  
  
}
