
#ifndef _RAY_RENDERER_HPP_
# define _RAY_RENDERER_HPP_

# include "RayWindow.hpp"
# include "RayCamera.hpp"
# include "ARenderer.hpp"

namespace engine
{
  const int WINDOW_WIDTH = 1600;
  const int WINDOW_HEIGHT = 900;
  
  class	RayRenderer : public ARenderer
  {
  public:
    RayRenderer()
    {
      Vec3<float>	CameraPosition(0, 17, 3.2);
      Vec3<float>	CameraTarget(0, 0, 0);
      Vec3<float>	CameraUp(0, 10, 0);
      
      initWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bomberman by Quentin");
      initCamera(CameraPosition, CameraTarget, CameraUp, 45);
      setFps(60);
    }

    ~RayRenderer()
    {

    }

    void		updateEvents()
    {

    }

    void		initCamera(const v3& pos, const v3& target,
				   const v3& up, float fovy)
    {
      this->camera = std::make_unique<RayCamera>();
      this->camera->initCamera(pos, target, up, fovy);
    }


    void	initWindow(const int width, const int height,
			   const std::string& name)
    {
      this->window = std::make_unique<RayWindow>(width, height, name);
    }

    void	draw(const std::vector<IDrawable*>& drawables)
    {
      BeginDrawing();
      camera->setMode3D(true);

      for (int i = 0; i != drawables.size(); i++) {
	if (drawables[i]->getDrawableType() == ACTOR)
	  drawables[i]->draw();
      }


      camera->setMode3D(false);

      for (int i = 0; i != drawables.size(); i++) {
      	if (drawables[i]->getDrawableType() == WIDGET)
      	  drawables[i]->draw();
      }
      // // for widget
      DrawRectangle(0, 0, WINDOW_WIDTH, 50, GRAY);
      DrawRectangle(0, 50, WINDOW_WIDTH, 2, BLACK);
      DrawFPS(10, 10);
      // DrawText("Welcome to the third dimension!", 10, 40, 20, DARKGRAY);

      EndDrawing();
    }

    void	draw(const std::vector<std::shared_ptr<AActor>>& actors)
    {
      BeginDrawing();
      camera->setMode3D(true);

      for (int i = 0; i != actors.size(); i++) {
	if (actors[i]->getDrawableType() == ACTOR)
	  actors[i]->draw();
      }


      camera->setMode3D(false);
      EndDrawing();
    }


    void	setFps(int maxFps)
    {
      SetTargetFPS(maxFps);
    }
  };
}

#endif /* _RAY_RENDERER_HPP_ */
