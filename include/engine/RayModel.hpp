
#ifndef _RAYMODEL_HPP_
# define _RAYMODEL_HPP_

# include <iostream>
# include "raylib.h"
# include "AActor.hpp"

namespace engine
{
  class RayModel : public engine::AActor
  {
  public:
    RayModel(const v3 pos, const std::string& path, const std::string& tm);
    
    void		draw();
    
  private:
    Texture2D	texture;
    Model	model;
  };
}


#endif /* _RAYMODEL_HPP_ */
