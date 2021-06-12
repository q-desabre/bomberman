
#ifndef ILEVEL_HPP_
# define ILEVEL_HPP_

# include <vector>
# include "IDrawable.hpp"

namespace bomber
{
  class Core;
  
  class ALevel
  {
  public:
    virtual void update(Core &c) = 0;

    const std::vector<engine::IDrawable*>& getDrawables() const
    {
      return this->drawables;
    }

  protected:
    std::vector<engine::IDrawable*>	drawables;

  };

}

#endif /* ILEVEL_HPP_ */
