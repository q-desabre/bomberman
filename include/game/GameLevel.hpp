
#ifndef GAME_LEVEL_HPP
# define GAME_LEVEL_HPP

# include "ALevel.hpp"
# include "Player.hpp"

namespace bomber
{
  class Core;
  
  class	GameLevel : public ALevel
  {
  public:
    GameLevel();

    void				startAnim(Core &c);
    void				update(Core &c);
    
  private:
    std::shared_ptr<Player>		p1;
    std::shared_ptr<Player>		p2;
    engine::Timer			timer;
    bool				isStarting;
  };

}
#endif /* MENU_LEVEL_HPP */
