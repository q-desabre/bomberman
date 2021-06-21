

#ifndef _RAY_IMAGE_HPP_
# define _RAY_IMAGE_HPP_

# include <iostream>
# include "raylib.h"
# include "AWidget.hpp"

namespace engine
{
  class RayImage : public AWidget
  {
  public:
    RayImage(const v2& pos, const std::string& tm, float scale = 1.0f);

    void		draw();


    void		setScale(float s);
    float		getScale() const;
    void		setTint(Color c);

  protected:
    Texture2D		texture;
    float		scale;
    Color		color;

  };

}

#endif 
