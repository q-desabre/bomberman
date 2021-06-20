
#include <iostream>
#include "GameLevel.hpp"
#include "Core.hpp"

void		bomber::GameLevel::update(Core &c)
{
  p1->update(c.getKeybind(), *this->map);
  p2->update(c.getKeybind(), *this->map);
  if (!p1->isAlive()) {
    // map->removeActor(map->getActorByUid(p1->getUid()));
  }

  
  static float	radius = 0;
  static float	degree = 90;
  static bool	first = true;
  if (isStarting == true)
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
