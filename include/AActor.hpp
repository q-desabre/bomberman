
#ifndef _AACTOR_HPP_
# define _AACTOR_HPP_

# include "IDrawable.hpp"

namespace bomber
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

    Vec3<float>		getScale() const
    {
      return this->scale;
    }

    void		setScale(Vec3<float> newScale)
    {
      this->scale = newScale;
    }

    Vec3<float>		getPosition() const
    {
      return position;
    }

    void		setPosition(Vec3<float> newPos)
    {
      this->position = newPos;
    }

    void		rotate(float angle)
    {
      this->angleRotation = angle;
    }
    
    Vec3<float>		getRotation() const
    {
      return rotation;
    }

    void		setRotation(Vec3<float> newR)
    {
      this->rotation = newR;
    }
    
  protected:
    float		angleRotation;
    Vec3<float>		position;
    Vec3<float>		scale;
    Vec3<float>		rotation;
  };
};


#endif /* _AACTOR_HPP_ */
