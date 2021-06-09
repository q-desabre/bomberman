
#ifndef _ACAMERA_HPP_
# define _ACAMERA_HPP_

# include "Vector.hpp"

namespace bomber
{
  class ACamera
  {
  public:
    ACamera() {}
    ~ACamera() {}

    virtual void		initCamera(Vec3<float> pos, Vec3<float> target,
					   Vec3<float> up, float fovy) = 0;
    virtual void		setPosition(Vec3<float> newPos) = 0;
    virtual void		setTarget(Vec3<float> newTarget) = 0;
    virtual void		setMode3D(bool status) = 0;
    
  protected:
    Vec3<float> position;
    Vec3<float> target;
    Vec3<float> up;
    float	fovy;
  };

}

#endif /* _ACAMERA_HPP_ */
