
#include "ALevel.hpp"

namespace bomber
{
  void			ALevel::addWidget(std::shared_ptr<engine::AWidget> widg)
  {
    this->widgets.push_back(widg);
  }
  
  const std::vector<std::shared_ptr<engine::AWidget>>&	ALevel::getWidgets() const
  {
    return this->widgets;
  }
  
  
  const std::vector<std::shared_ptr<engine::AActor>>&	ALevel::getActors() const
  {
    return map->getActors();
  }
  
  const Map&				ALevel::getMap() const
  {
    return *map;
  }

}
