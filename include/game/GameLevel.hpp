
#ifndef GAME_LEVEL_HPP
# define GAME_LEVEL_HPP

# include "ALevel.hpp"
# include "Player.hpp"
# include "RayImage.hpp"

namespace bomber
{
  class Core;
  
  class	GameLevel : public ALevel
  {
  public:
    GameLevel(Core &core);

    void				startAnim(Core &c);
    void				update(Core &c);
    
  private:
    std::shared_ptr<engine::RayImage>			test;
    std::vector<std::shared_ptr<Player>>		players;
    engine::Timer					timer;
    bool						isStarting;
  };

}
#endif /* MENU_LEVEL_HPP */
