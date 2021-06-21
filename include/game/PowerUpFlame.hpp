
#ifndef _FLAME_POWER_UP_
# define _FLAME_POWER_UP_

# include "APowerUp.hpp"

namespace bomber
{
  class PowerUpFlame : public APowerUp
  {
  public:
    PowerUpFlame(const v3& p);

    void		effect(Player &player);
  };

  class PowerUpBomb : public APowerUp
  {
  public:
    PowerUpBomb(const v3& p);

    void		effect(Player &player);
  };


  class PowerUpSpeed : public APowerUp
  {
  public:
    PowerUpSpeed(const v3& p);

    void		effect(Player &player);
  };

  class PowerUpWallPass : public APowerUp
  {
  public:
    PowerUpWallPass(const v3& p);

    void		effect(Player &player);
  };

}

#endif /* _FLAME_POWER_UP_ */
