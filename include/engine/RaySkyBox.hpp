

#ifndef _SKYBOX_HPP
# define _SKYBOX_HPP

# include <iostream>
# include "rlgl.h"
# include "AActor.hpp"
# include "Timer.hpp"

namespace engine
{
  class RaySkyBox : public AActor
  {
  public:
    RaySkyBox(int size, const std::string& tm);
    
    void		draw();
    
  private:
    Timer		timer;
    Model		model;
    Texture2D		texture;
  };

}


#endif /* _SKYBOX_HPP */
