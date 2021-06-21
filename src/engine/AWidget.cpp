
#include "AWidget.hpp"

namespace engine
{
  void			AWidget::update()
  {

  }

  const v2&		AWidget::getPosition() const
  {
    return this->position;
  }

  void			AWidget::setPosition(const v2& v)
  {
    this->position = v;
  }
  
  DrawableType		AWidget::getDrawableType() const
  {
    return WIDGET;
  }
}
