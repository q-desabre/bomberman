
#include "RayText.hpp"

namespace engine
{
  RayText::RayText(const v2& pos, const std::string& t, int fS, Color c)
    : text(t), fontSize(fS), color(c)
  {
    position.x = pos.x;
    position.y = pos.y;
  }
  
  void			RayText::draw()
  {
    DrawText(text.c_str(), position.x, position.y, fontSize, color);
  }


  
}
