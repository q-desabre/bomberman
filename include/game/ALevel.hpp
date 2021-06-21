
#ifndef ILEVEL_HPP_
# define ILEVEL_HPP_

# include <memory>
# include <vector>
# include "Map.hpp"
# include "AActor.hpp"
# include "AWidget.hpp"

namespace bomber
{
  class Core;
  
  class ALevel
  {
  public:
    virtual void	update(Core &c) = 0;
    void		addWidget(std::shared_ptr<engine::AWidget> widg);
    
    const std::vector<std::shared_ptr<engine::AWidget>>&	getWidgets() const;
    const std::vector<std::shared_ptr<engine::AActor>>&		getActors() const;
    const Map&							getMap() const;
    
  protected:
    std::vector<std::shared_ptr<engine::AWidget>>	widgets;
    std::unique_ptr<Map>				map;
  };

}

#endif /* ILEVEL_HPP_ */
