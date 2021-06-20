
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
}

#endif /* _FLAME_POWER_UP_ */
