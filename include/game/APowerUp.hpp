
#ifndef _POWER_UP_HPP
# define _POWER_UP_HPP

# include "Player.hpp"
# include "Cube.hpp"

namespace bomber
{
  class APowerUp : public bomber::Cube
  {
  public:
    APowerUp(const v3& p, const std::string& textureName) : bomber::Cube(p, textureName, BONUS) {}

    virtual void	effect(Player &player) = 0;
  };
  
}

#endif /* _POWER_UP_HPP */
