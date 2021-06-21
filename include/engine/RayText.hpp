
#ifndef _RAY_TEXT_HPP_
# define _RAY_TEXT_HPP_

# include <iostream>
# include "raylib.h"
# include "AWidget.hpp"

namespace engine
{
  class RayText : public AWidget
  {
  public:
    RayText(const v2& pos, const std::string& t, int fS, Color c);

    void		draw();

  protected:
    std::string		text;
    int			fontSize;
    Color		color;

  };

}


#endif /* _RAY_TEXT_HPP_ */
