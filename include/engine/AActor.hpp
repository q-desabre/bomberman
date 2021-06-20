
#ifndef _AACTOR_HPP_
# define _AACTOR_HPP_

# include "Utils.hpp"
# include "Vector.hpp"
# include "IDrawable.hpp"

namespace engine
{
  
  class AActor : public IDrawable
  {
    
  public:
    AActor();
    virtual void		draw() = 0;
    virtual void		update();

    DrawableType	getDrawableType() const;

    const v3&		getScale() const;
    void		setScale(const v3& newScale);

    const v3&		getPosition() const;
    void		setPosition(const v3& newPos);

    float		getAngleRotation() const;
    void		rotate(float angle);

    const v3&		getRotation() const;
    void		setRotation(const v3& newR);

    int			getUid() const;

    
    
  protected:
    int		uid;
    float	angleRotation = 0.0f;
    v3		position = v3(0, 0, 0);
    v3		scale = v3(1, 1, 1);
    v3		rotation = v3(0, 1, 0);
  };
};


#endif /* _AACTOR_HPP_ */
