
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
    RayRenderer();

    void        initCamera(const v3& pos, const v3& target, const v3& up, float fovy);
    void	initWindow(const int width, const int height, const std::string& name);
    void        draw(const std::vector<std::shared_ptr<AWidget>>&);
    void	draw(const std::vector<std::shared_ptr<AActor>>& actors);
    void	setFps(int maxFps);
  };
}

#endif /* _RAY_RENDERER_HPP_ */
