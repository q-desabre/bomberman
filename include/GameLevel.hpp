
#ifndef GAME_LEVEL_HPP
# define GAME_LEVEL_HPP

# include "ALevel.hpp"
# include "Map.hpp"
# include "Skybox.hpp"
# include "Player.hpp"

namespace bomber
{
  class Core;
  
  class	GameLevel : public ALevel
  {
  public:
    GameLevel()
    {
      map = new Map("../maps/map1.data");
      p1.setPosition(Vec3<float>(-8.0f, 0, 5.0f));
      p2.setPosition(Vec3<float>(8.0f, 0, -5.0f));
      isStarting = true;
      map->addActor(&p1);
      map->addActor(&p2);
    }
    ~GameLevel() {}
    
    void		update(Core &c);
    
  private:
    Player		p1 = Player(1);
    Player		p2 = Player(2);
    engine::Timer	timer;
    bool		isStarting;
  };

}
#endif /* MENU_LEVEL_HPP */
