
#include "MenuLevel.hpp"
#include "Core.hpp"

namespace bomber
{

  MenuLevel::MenuLevel(Core &core)
  {
    this->playButton = std::make_shared<PlayButton>(v2(50, 30),
						    "ButtonBase",
						    "ButtonHover",
						    "ButtonClicked");
    this->addWidget(playButton);
    map = std::make_unique<Map>();
    test = std::make_shared<engine::RayImage>(v2(50, 10), "title");
    this->addWidget(this->test);
    this->skybox = std::make_shared<engine::RaySkyBox>(32, "background");
    this->map->addActor(this->skybox);
  }

  void		MenuLevel::update(Core &c)
  {
    playButton->update(c);
  }
  
}
