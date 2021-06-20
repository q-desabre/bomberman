
#include "Utils.hpp"

namespace engine
{
  int		generateUid()
  {
    static int		i = 0;

    i++;
    return (i);
  }
}
