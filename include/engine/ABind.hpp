
#ifndef _KEYBINDS_HPP_
# define _KEYBINDS_HPP_

# include <map>
# include "Event.hpp"

namespace engine
{
  class ABind
  {
  public:
    virtual void	init() = 0;
    virtual void	addBind(Event e, int key) = 0;
    virtual void	update() = 0;

    bool		isEvent(Event e) const;
    
  protected:
    std::map<Event, int>	binds;
    std::map<Event, bool>	values;
  };
}

#endif /* _KEYBINDS_HPP_ */
