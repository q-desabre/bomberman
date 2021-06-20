
#ifndef _IDRAWABLE_HPP_
# define _IDRAWABLE_HPP_

namespace engine
{
  enum DrawableType
    {
     ACTOR,
     WIDGET
    };
  
  class IDrawable
  {
  public:
    virtual void		draw() = 0; // ? est ce que je dois le prévoir ?
    virtual DrawableType	getDrawableType() const = 0; 
  };
}

#endif /* _IDRAWABLE_HPP_ */
