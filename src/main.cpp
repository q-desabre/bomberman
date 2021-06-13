
#include "Core.hpp"

int main(void)
{
  bomber::Core			core;

  // bomber::Player		p1(1);
  // bomber::Player		p2(2);

  // bomber::Map			map(15, 15);

  // graphic->addActor(map.getGround());
  // for (int i = 0; i != map.getBlocks().size(); i++) {
  //   graphic->addActor(map.getBlocks()[i]);
  // }
  
  // graphic->addActor(&p1);
  // graphic->addActor(&p2);

  // p2.setPosition(Vec3<float>(6.0f, 0, -6.0f));

  
  while (core.isRunning())
    {
      core.update();
      core.draw();
      // keybind->update();
      // p1.update(*keybind, map);
      // p2.update(*keybind, map);
      // graphic->clear();
      // graphic->draw();
    }

  return 0;
}

