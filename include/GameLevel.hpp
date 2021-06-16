
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
      p1 = std::make_shared<Player>(1);
      p2 = std::make_shared<Player>(2);
      map = std::make_unique<Map>("../maps/map1.data");
      p1->setPosition(Vec3<float>(-8.0f, 0, 5.0f));
      p2->setPosition(Vec3<float>(8.0f, 0, -5.0f));
      isStarting = true;
      map->addActor(p1);
      map->addCollidableActor(p1);
      map->addActor(p2);
      map->addCollidableActor(p2);
    }
    ~GameLevel() {}
    
    void		update(Core &c);
    
  private:
    std::shared_ptr<Player>		p1;
    std::shared_ptr<Player>		p2;
    engine::Timer			timer;
    bool				isStarting;
  };

}
#endif /* MENU_LEVEL_HPP */
