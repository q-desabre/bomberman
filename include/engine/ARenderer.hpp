
#ifndef _ARENDERER_HPP_
# define _ARENDERER_HPP_

# include <vector>
# include <memory>
# include "AActor.hpp"
# include "AWidget.hpp"
# include "IWindow.hpp"
# include "ACamera.hpp"

namespace engine
{
  class ARenderer : public IWindow , public ACamera
  {
  public:
    ARenderer() {}
    virtual ~ARenderer() {}

    virtual void        draw(const std::vector<std::shared_ptr<AWidget>>&) = 0;
    virtual void        draw(const std::vector<std::shared_ptr<AActor>>&) = 0;
    virtual void	setFps(int fpsMax) = 0;
    virtual void	initWindow(const int, const int, const std::string&) = 0;
    virtual void	initCamera(const v3& pos, const v3& target,
				   const v3& up, float fovy) = 0;

    virtual void        clear();
    virtual void	close();
    bool		isOpen() const;
    void		setPosition(const v3& newPos);
    const v3&		getPosition() const;
    void		setTarget(const v3& newTarget);
    void		setMode3D(bool status);
    
  protected:
    std::unique_ptr<ACamera>	camera;
    std::unique_ptr<IWindow>	window;
  };
}

#endif /* _RENDERER_HPP_ */
