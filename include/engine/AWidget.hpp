
#ifndef _AWIDGET_HPP_
# define _AWIDGET_HPP_

# include "Vector.hpp"
# include "IDrawable.hpp"

namespace engine
{
  class AWidget : public IDrawable
  {
  public:
    virtual void	draw() = 0;
    void		update();
    
    const v2&		getPosition() const;
    void		setPosition(const v2& v);
    DrawableType	getDrawableType() const;
    
    
  protected:
    v2		position;
  };
}



#endif /* _AWIDGET_HPP_ */
