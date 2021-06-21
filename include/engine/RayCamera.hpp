

#ifndef _RayCamera_HPP_
# define _RayCamera_HPP_

# include "ACamera.hpp"
# include "raylib.h"

namespace engine
{  
  class	RayCamera : public ACamera
  {
  public:
    RayCamera();

    void		initCamera(const v3& _pos, const v3& _target, const v3& _up, float _fovy);
    void		setPosition(const v3& newPos);
    void		setTarget(const v3& newTarget);
    void		setMode3D(bool status);
    
  private:
    Camera3D	camera;
  };
}

  
#endif /* _RayCamera _HPP_ */
