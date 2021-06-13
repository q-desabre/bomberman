
#ifndef ILEVEL_HPP_
# define ILEVEL_HPP_

# include <vector>
# include "Map.hpp"
# include "AActor.hpp"

namespace bomber
{
  class Core;
  
  class ALevel
  {
  public:
    virtual void update(Core &c) = 0;

    const std::vector<engine::AActor*>& getActors() const
    {
      return map->getActors();
    }

    const Map&				getMap() const
    {
      return *map;
    }
    
  protected:
    Map					*map;
    std::vector<engine::AActor*>	actors;
  };

}

#endif /* ILEVEL_HPP_ */
