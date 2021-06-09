

#ifndef _RayCamera_HPP_
# define _RayCamera_HPP_

# include "ACamera.hpp"
# include "raylib.h"

namespace bomber
{  
  class	RayCamera : public ACamera
  {
  public:
    RayCamera()
    {
      this->camera = {0};
    }
    ~RayCamera() {}

    void		initCamera(Vec3<float> _pos, Vec3<float> _target,
				   Vec3<float> _up, float _fovy)
    {
      this->camera.position = (Vector3){_pos.x, _pos.y, _pos.z};
      this->camera.target = (Vector3){_target.x, _target.y, _target.z};
      this->camera.up = (Vector3){_up.x, _up.y, _up.z};
      this->camera.fovy = _fovy;
      this->camera.projection = CAMERA_PERSPECTIVE;
    }
    
    void		setPosition(Vec3<float> newPos)
    {
      this->position = newPos;
      this->camera.position = (Vector3){newPos.x, newPos.y, newPos.z};
    }
     
    void		setTarget(Vec3<float> newTarget)
    {
      this->target = newTarget;
      this->camera.target = (Vector3){newTarget.x, newTarget.y, newTarget.z};
    }
     
    void		setMode3D(bool status)
    {
      if (status)
	{
	  BeginMode3D(this->camera);
	}
      else
	EndMode3D();
    }
  
  private:
    Camera3D	camera;
  };
}

  
#endif /* _RayCamera _HPP_ */
