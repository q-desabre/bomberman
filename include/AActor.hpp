
#ifndef _AACTOR_HPP_
# define _AACTOR_HPP_

# include "Vector.hpp"
# include "IDrawable.hpp"

namespace engine
{
  class AActor : public IDrawable
  {
  public:
    virtual void		draw() = 0;
    virtual void		draw(int) = 0;
    
    DrawableType	getDrawableType() const
    {
      return DrawableType::ACTOR;
    }

    const v3&		getScale() const
    {
      return this->scale;
    }

    void		setScale(const v3& newScale)
    {
      this->scale = newScale;
    }

    const v3&		getPosition() const
    {
      return position;
    }

    void		setPosition(const v3& newPos)
    {
      this->position = newPos;
    }

    void		rotate(float angle)
    {
      this->angleRotation = angle;
    }

    float		getAngleRotation() const
    {
      return this->angleRotation;
    }
    
    const v3&		getRotation() const
    {
      return rotation;
    }

    void		setRotation(const v3& newR)
    {
      this->rotation = newR;
    }
    
  protected:
    float	angleRotation = 0.0f;
    v3		position = v3(0, 0, 0);
    v3		scale = v3(1, 1, 1);
    v3		rotation = v3(0, 1, 0);
  };
};


#endif /* _AACTOR_HPP_ */
