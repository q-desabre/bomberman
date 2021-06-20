
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
    Core()
    {
      srand(time(NULL));
      this->running = true;
      this->keybind = std::make_unique<engine::RayBind>();
      this->renderer = std::make_unique<engine::RayRenderer>();
      this->init();
      this->levels.push(std::make_unique<GameLevel>());
    }

    ~Core()
    {

    }

    void		init()
    {
      engine::TextureManager<Texture2D>&	tm = engine::TextureManager<Texture2D>::getInstance();
      tm.loadTexture("player1", LoadTexture("../assets/steve/skin.png"));
      tm.loadTexture("player2", LoadTexture("../assets/steve/skin2.png"));
      tm.loadTexture("flame0", LoadTexture("../assets/flame/flame0.png"));
      tm.loadTexture("flame1", LoadTexture("../assets/flame/flame1.png"));
      tm.loadTexture("flame2", LoadTexture("../assets/flame/flame2.png"));
      tm.loadTexture("flame3", LoadTexture("../assets/flame/flame3.png"));
      tm.loadTexture("flame4", LoadTexture("../assets/flame/flame4.png"));
      tm.loadTexture("floorBlock", LoadTexture("../assets/block5.png"));
      tm.loadTexture("unbreakableBlock", LoadTexture("../assets/block4.png"));
      tm.loadTexture("breakableBlock", LoadTexture("../assets/block_brick.png"));
      tm.loadTexture("background", LoadTexture("../assets/block_background.png"));	     
    }
    void		update()
    {
      //      std::cout << __PRETTY_FUNCTION__ << std::endl;
      this->keybind->update();
      this->levels.top()->update(*this);
      //std::cout << "end of " << __PRETTY_FUNCTION__ << std::endl;
    }

    void		draw()
    {
      //std::cout << __PRETTY_FUNCTION__ << std::endl;
      this->renderer->clear();
      this->renderer->draw(this->levels.top()->getMap().getActors());
      //std::cout << "end of " << __PRETTY_FUNCTION__ << std::endl;
    }

    bool			isRunning() const
    {
      return (this->running);
    }

    void			stop()
    {
      this->running = false;
    }
    
    engine::ARenderer&		getRenderer()
    {
      return (*this->renderer);
    }

    engine::ABind&		getKeybind()
    {
      return (*this->keybind);
    }
    
  private:
    bool				running;
    std::stack<std::unique_ptr<ALevel>>	levels;
    std::unique_ptr<engine::ABind>	keybind;
    std::unique_ptr<engine::ARenderer>	renderer;
  };
}


#endif /* _CORE_HPP_ */
