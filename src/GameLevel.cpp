
#include <iostream>
#include "GameLevel.hpp"
#include "Core.hpp"

namespace bomber
{

  GameLevel::GameLevel()
  {
    p1 = std::make_shared<Player>(1);
    p2 = std::make_shared<Player>(2);
    map = std::make_unique<Map>("../maps/map1.data", 2);
    p1->setPosition(Vec3<float>(-8.0f, 0, 5.0f));
    p2->setPosition(Vec3<float>(8.0f, 0, -5.0f));
    isStarting = true;
    map->addActor(p1);
    map->addCollidableActor(p1);
    map->addActor(p2);
    map->addCollidableActor(p2);
  }    


  void			GameLevel::update(Core &c)
  {
    startAnim(c);
    p1->update(c.getKeybind(), *this->map);
    p2->update(c.getKeybind(), *this->map);

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
