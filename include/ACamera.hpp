
#ifndef _ACAMERA_HPP_
# define _ACAMERA_HPP_

# include <iostream>
# include "Vector.hpp"

namespace engine
{
  class ACamera
  {
  public:
    ACamera() {}
    ~ACamera() {}

    virtual void		initCamera(const v3& pos, const v3& target,
					   const v3& up, float fovy) = 0;
    virtual void		setPosition(const v3& newPos) = 0;
    virtual void		setTarget(const v3& newTarget) = 0;
    virtual void		setMode3D(bool status) = 0;
    virtual const v3&		getPosition() const
    {
      return position;
    }
    
  protected:
    Vec3<float> position;
    Vec3<float> target;
    Vec3<float> up;
    float	fovy;
  };

}

#endif /* _ACAMERA_HPP_ */
