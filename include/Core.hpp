
#ifndef _CORE_HPP_
# define _CORE_HPP_

# include <stack>
# include "GameState.hpp"
# include "RayBind.hpp"
# include "RayRenderer.hpp"
# include "MenuLevel.hpp"
# include "GameLevel.hpp"

namespace bomber
{
  class Core
  {
  public:
    Core()
    {
      srand(time(NULL));
      this->running = true;
      this->keybind = new engine::RayBind();
      this->renderer = new engine::RayRenderer();
      this->levels.push(new GameLevel());
    }

    ~Core()
    {

    }

    void		update()
    {
      this->keybind->update();
      this->levels.top()->update(*this);
    }

    void		draw()
    {
      this->renderer->clear();
      this->renderer->draw(this->levels.top()->getDrawables());
    }

    bool			isRunning() const
    {
      return (this->running);
    }

    void			stop()
    {
      this->running = false;
    }
    engine::ARenderer		*getRenderer()
    {
      return (this->renderer);
    }

    engine::ABind		*getKeybind()
    {
      return (this->keybind);
    }
    
  private:
    bool			running;
    std::stack<ALevel *>	levels;
    engine::ABind		*keybind;
    engine::ARenderer		*renderer;
  };
}


#endif /* _CORE_HPP_ */
