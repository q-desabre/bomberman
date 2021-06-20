
#include "Core.hpp"

namespace engine
{
  template <>
  TextureManager<Texture2D>	*TextureManager<Texture2D>::instance = nullptr;
}

int main(void)
{
  bomber::Core			core;

  while (core.isRunning())
    {
      core.update();
      core.draw();
    }
  return 0;
}

