
#include "ABind.hpp"

namespace engine
{
  bool			ABind::isEvent(Event e) const
  {
    return (values.at(e));
  }

  const v2&		ABind::getMousePosition() const
  {
    return mousePose;
  }

  bool			ABind::isMouseClicked() const
  {
    return mouseClicked;
  }

}
