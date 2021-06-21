
#include "RayRenderer.hpp"

namespace engine
{
  RayRenderer::RayRenderer()
  {
    Vec3<float>	CameraPosition(0, 17, 3.2);
    Vec3<float>	CameraTarget(0, 0, 0);
    Vec3<float>	CameraUp(0, 10, 0);
      
    initWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bomberman by Quentin");
    initCamera(CameraPosition, CameraTarget, CameraUp, 45);
    setFps(60);
  }

  void		RayRenderer::initCamera(const v3& pos, const v3& target,
					const v3& up, float fovy)
  {
    this->camera = std::make_unique<RayCamera>();
    this->camera->initCamera(pos, target, up, fovy);
  }


  void		RayRenderer::initWindow(const int width, const int height,
					const std::string& name)
  {
    this->window = std::make_unique<RayWindow>(width, height, name);
  }

  void		RayRenderer::draw(const std::vector<std::shared_ptr<AActor>>& actors,
				  const std::vector<std::shared_ptr<AWidget>>& widgets)
  {
    BeginDrawing();
    camera->setMode3D(true);

    for (int i = 0; i != actors.size(); i++) {
      if (actors[i]->getDrawableType() == ACTOR)
	actors[i]->draw();
    }
    camera->setMode3D(false);
    for (int i = 0; i != widgets.size(); i++) {
      if (widgets[i]->getDrawableType() == WIDGET)
	widgets[i]->draw();
    }
    EndDrawing();
  }


  void	RayRenderer::setFps(int maxFps)
  {
    SetTargetFPS(maxFps);
  }

}
