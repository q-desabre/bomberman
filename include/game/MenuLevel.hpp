
#ifndef MENU_LEVEL_HPP
# define MENU_LEVEL_HPP

# include "ALevel.hpp"

namespace bomber
{
  class Core;
  
  class	MenuLevel : public ALevel
  {
  public:
    MenuLevel();
    
    void		update(Core &c);
  };

}
#endif /* MENU_LEVEL_HPP */
