
#ifndef _RAY_RENDERER_HPP_
# define _RAY_RENDERER_HPP_

# include "RayWindow.hpp"
# include "RayCamera.hpp"
# include "ARenderer.hpp"

namespace bomber
{
  class	RayRenderer : public ARenderer
  {
  public:
    RayRenderer()
    {
      Vec3<float>	CameraPosition(0, 15, 12);
      Vec3<float>	CameraTarget(0, 0, 0);
      Vec3<float>	CameraUp(0, 10, 0);
      
      initWindow(1024, 768, "Bomberman by Quentin");
      initCamera(CameraPosition, CameraTarget, CameraUp, 45);
      setFps(60);
    }

    ~RayRenderer()
    {

    }

    void		updateEvents()
    {

    }

    void		initCamera(Vec3<float> pos, Vec3<float> target,
				   Vec3<float> up, float fovy)
    {
      this->camera = new RayCamera();
      this->camera->initCamera(pos, target, up, fovy);
    }


    void	initWindow(const int width, const int height,
			   const std::string& name)
    {
      this->window = new RayWindow(width, height, name);
      ToggleFullscreen();
    }

    void	draw()
    {
      BeginDrawing();
      camera->setMode3D(true);
      for (int i = 0; i != actors.size(); i++) {
	actors[i]->draw();
      }
      camera->setMode3D(false);

      // for widget
      DrawRectangle(0, 0, 1024, 121, GRAY);
      DrawRectangle(0, 121, 1024, 2, BLACK);
      DrawFPS(10, 10);
      DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

      EndDrawing();
    }


    void	setFps(int maxFps)
    {
      SetTargetFPS(maxFps);
    }
  };
}

#endif /* _RAY_RENDERER_HPP_ */
