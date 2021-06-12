
#ifndef _RAYKEYBIND_HPP_
# define _RAYKEYBIND_HPP_

# include "ABind.hpp"
# include "raylib.h"

namespace engine
{
  class RayBind : public ABind
  {
  public:
    RayBind()
    {
      init();
    }

    ~RayBind()
    {

    }

    void		init()
    {
      addBind(Event::NONE, 0);
      addBind(Event::PLAYER1_RIGHT, KEY_RIGHT);
      addBind(Event::PLAYER1_LEFT, KEY_LEFT);
      addBind(Event::PLAYER1_UP, KEY_UP);
      addBind(Event::PLAYER1_DOWN, KEY_DOWN);
      addBind(Event::PLAYER1_ACTION1, -1);
      addBind(Event::PLAYER1_ACTION2, -1);
      addBind(Event::PLAYER2_RIGHT, KEY_D);
      addBind(Event::PLAYER2_LEFT, KEY_A);
      addBind(Event::PLAYER2_UP, KEY_W);
      addBind(Event::PLAYER2_DOWN, KEY_S);
      addBind(Event::PLAYER2_ACTION1, -1);
      addBind(Event::PLAYER2_ACTION2, -1);
    }

    void		update()
    {
      std::map<Event, int>::iterator it;

      for (it = binds.begin(); it != binds.end(); it++) {
	  this->values[it->first] = IsKeyDown(it->second);
      }
    }

    void		addBind(Event e, int key)
    {
      this->binds[e] = key;
    }

  };
}
#endif /* _RAYKEYBIND_HPP_ */
