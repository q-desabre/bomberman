
#ifndef _RAYKEYBIND_HPP_
# define _RAYKEYBIND_HPP_

# include "ABind.hpp"
# include "raylib.h"

namespace engine
{
  class RayBind : public ABind
  {
  public:
    RayBind();
    
    void		init();
    void		update();
    void		addBind(Event e, int key);
  };
}
#endif /* _RAYKEYBIND_HPP_ */
