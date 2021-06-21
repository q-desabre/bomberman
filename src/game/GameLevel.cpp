
#include <iostream>
#include "GameLevel.hpp"
#include "Core.hpp"

namespace bomber
{

  GameLevel::GameLevel(Core &core)
  {
    test = std::make_shared<engine::RayImage>(v2(10, 10), "flame0");
    map = std::make_unique<Map>("../maps/map1.data", 2);
    for (int i = 0; i != core.getNbPlayer(); i++) {
      std::shared_ptr<Player> p = std::make_shared<Player>(i + 1);
      players.push_back(p);
      p->setPosition(map->getPlayerStart(i + 1));
      map->addActor(p);
      map->addCollidableActor(p);
    }
    addWidget(this->test);
    isStarting = true;
  }    


  void			GameLevel::update(Core &c)
  {
    int			playerAlive = 0;
    startAnim(c);
    for (int i = 0; i != c.getNbPlayer(); i++) {
      if (players[i]->isAlive())
	playerAlive++;
      players[i]->update(c.getKeybind(), *this->map);
    }

    if (playerAlive == 1) {
      std::cout << "We have a winner !" << std::endl;
    } else if ( playerAlive == 0) {
      std::cout << "It's a draw :( !" << std::endl;
    }
    // check win con
    
  }

  void			GameLevel::startAnim(Core &c)
  {
    static float	radius = 0;
    static float	degree = 90;
    static bool		first = true;

    if (!isStarting == true)
      {
	if (first) {
	  c.getRenderer().setPosition(v3(0, 1, 0));
	  first = false;
	} else if (degree != 450) {
	  if (timer.getElapsedTime() >= 0.0000016f) {
	    v3 tmp = c.getRenderer().getPosition();
	    tmp.x = (float)radius * (float)cos(degree * 0.0174532925);
	    tmp.z = (float)radius * (float)sin(degree * 0.0174532925);
	    tmp.y += 17 / 180.0f;
	    radius += 3.2f / 180.0f;
	    c.getRenderer().setPosition(v3(tmp.x, tmp.y, tmp.z));
	    degree +=2;
	    timer.restart();
	  }
	}
	else {
	  c.getRenderer().setPosition(v3(0, 17, 3.2));
	}
      }
  }

}
