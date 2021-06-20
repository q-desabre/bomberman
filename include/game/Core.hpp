
#ifndef _CORE_HPP_
# define _CORE_HPP_

# include <stack>
# include "GameState.hpp"
# include "RayBind.hpp"
# include "RayRenderer.hpp"
# include "MenuLevel.hpp"
# include "GameLevel.hpp"
# include "TextureManager.hpp"

namespace bomber
{
  class Core
  {
  public:
    Core();

    void			init();
    void			update();
    void			draw();
    bool			isRunning() const;
    void			stop();    
    engine::ARenderer&		getRenderer();
    engine::ABind&		getKeybind();
    
  private:
    bool				running;
    std::stack<std::unique_ptr<ALevel>>	levels;
    std::unique_ptr<engine::ABind>	keybind;
    std::unique_ptr<engine::ARenderer>	renderer;
  };
}


#endif /* _CORE_HPP_ */
