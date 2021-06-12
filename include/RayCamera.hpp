

#ifndef _RayCamera_HPP_
# define _RayCamera_HPP_

# include "ACamera.hpp"
# include "raylib.h"

namespace engine
{  
  class	RayCamera : public ACamera
  {
  public:
    RayCamera()
    {
      this->camera = {0};
    }
    ~RayCamera() {}

    void		initCamera(const v3& _pos, const v3& _target,
				   const v3& _up, float _fovy)
    {
      setPosition(_pos);
      setTarget(_target);
      this->camera.target = (Vector3){_target.x, _target.y, _target.z};
      this->camera.up = (Vector3){_up.x, _up.y, _up.z};
      this->camera.fovy = _fovy;
      this->camera.projection = CAMERA_PERSPECTIVE;
    }
    
    void		setPosition(const v3& newPos)
    {
      this->position = newPos;
      this->camera.position = (Vector3){newPos.x, newPos.y, newPos.z};
    }
     
    void		setTarget(const v3& newTarget)
    {
      this->target = newTarget;
      this->camera.target = (Vector3){newTarget.x, newTarget.y, newTarget.z};
    }
     
    void		setMode3D(bool status)
    {
      if (status)
	BeginMode3D(this->camera);
      else
	EndMode3D();
    }
  
  private:
    Camera3D	camera;
  };
}

  
#endif /* _RayCamera _HPP_ */
