
#include <iostream>
#include "raylib.h"
#include "RayRenderer.hpp"
#include "Player.hpp"
#include "Event.hpp"
#include "Map.hpp"
#include "RayCube.hpp"
#include "RayKeybind.hpp"

int main(void)
{
  bomber::AKeybind		*keybind = new bomber::RayKeybind();
  bomber::ARenderer		*graphic = new bomber::RayRenderer();

  bomber::Player		p1(1);
  bomber::Player		p2(2);

  bomber::Map			map(15, 15);

  graphic->addActor(map.getGround());
  for (int i = 0; i != map.getBlocks().size(); i++) {
    graphic->addActor(map.getBlocks()[i]);
  }
  
  graphic->addActor(&p1);
  graphic->addActor(&p2);

  p1.setPosition(Vec3<float>(-6.0f, 0, 6.0f));
  p2.setPosition(Vec3<float>(6.0f, 0, -6.0f));
  
  while (graphic->isOpen())
    {
      keybind->update();
      p1.update(*keybind, map);
      p2.update(*keybind, map);
      graphic->clear();
      graphic->draw();
    }

  return 0;
}

