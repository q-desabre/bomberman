
#include "Core.hpp"

namespace bomber
{
  Core::Core()
  {
    srand(time(NULL));
    this->running = true;
    this->keybind = std::make_unique<engine::RayBind>();
    this->renderer = std::make_unique<engine::RayRenderer>();
    this->init();
    this->levels.push(std::make_unique<GameLevel>());
  }

  void			Core::init()
  {
    engine::TextureManager<Texture2D>&	tm = engine::TextureManager<Texture2D>::getInstance();
    tm.loadTexture("player1", LoadTexture("../assets/steve/skin.png"));
    tm.loadTexture("player2", LoadTexture("../assets/steve/skin2.png"));
    tm.loadTexture("flame0", LoadTexture("../assets/flame/flame0.png"));
    tm.loadTexture("flame1", LoadTexture("../assets/flame/flame1.png"));
    tm.loadTexture("flame2", LoadTexture("../assets/flame/flame2.png"));
    tm.loadTexture("flame3", LoadTexture("../assets/flame/flame3.png"));
    tm.loadTexture("flame4", LoadTexture("../assets/flame/flame4.png"));
    tm.loadTexture("PowerUpFlame", LoadTexture("../assets/flame/fire.png"));
    tm.loadTexture("floorBlock", LoadTexture("../assets/block5.png"));
    tm.loadTexture("unbreakableBlock", LoadTexture("../assets/block4.png"));
    tm.loadTexture("breakableBlock", LoadTexture("../assets/block_brick.png"));
    tm.loadTexture("background", LoadTexture("../assets/block_background.png"));	     
  }

  void			Core::update()
  {
    this->keybind->update();
    this->levels.top()->update(*this);
  }

  void			Core::draw()
  {
    this->renderer->clear();
    this->renderer->draw(this->levels.top()->getMap().getActors());
  }

  bool			Core::isRunning() const
  {
    return (this->running);
  }

  void			Core::stop()
  {
    this->running = false;
  }
    
  engine::ARenderer&	Core::getRenderer()
  {
    return (*this->renderer);
  }

  engine::ABind&	Core::getKeybind()
  {
    return (*this->keybind);
  }
    

}
