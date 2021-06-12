
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
    GameLevel() : map("../maps/map1.data")
    {
      p1.setPosition(Vec3<float>(-8.0f, 0, 5.0f));
      p2.setPosition(Vec3<float>(8.0f, 0, -5.0f));
      isStarting = true;
      this->drawables.push_back(&p1);
      this->drawables.push_back(&p2);
      for (int i = 0; i != map.getBlocks().size(); i++) {
	this->drawables.push_back(map.getBlocks()[i]);
      }
    }
    ~GameLevel() {}
    
    void		update(Core &c);
    
  private:
    Player		p1 = Player(1);
    Player		p2 = Player(2);
    engine::Timer	timer;
    bool		isStarting;
    Map			map;

  };

}
#endif /* MENU_LEVEL_HPP */
