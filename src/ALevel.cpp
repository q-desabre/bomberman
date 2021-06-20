
#include "ALevel.hpp"

namespace bomber
{
  const std::vector<std::shared_ptr<engine::AActor>>& ALevel::getActors() const
  {
    return map->getActors();
  }
  
  const Map&				ALevel::getMap() const
  {
    return *map;
  }
}
