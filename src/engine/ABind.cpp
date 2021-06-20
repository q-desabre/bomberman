
#include "ABind.hpp"

namespace engine
{
  bool		ABind::isEvent(Event e) const
  {
    return (values.at(e));
  }

}
