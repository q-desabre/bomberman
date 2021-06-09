
#ifndef _ARENDERER_HPP_
# define _ARENDERER_HPP_

# include <vector>
# include "AActor.hpp"

namespace bomber
{
  class ARenderer : public IWindow , public ACamera
  {
  public:
    ARenderer() {}
    virtual ~ARenderer() {}

    virtual void        draw() = 0;
    virtual void        updateEvents() = 0;
    virtual void	setFps(int fpsMax) = 0;
    virtual void	initWindow(const int, const int, const std::string&) = 0;
    virtual void	initCamera(Vec3<float> pos, Vec3<float> target,
				   Vec3<float> up, float fovy) = 0;

    virtual void        clear()
    {
      this->window->clear();
    }
    
    virtual void	close()
    {
      this->window->close();
    }
    
    bool	isOpen() const
    {
      return this->window->isOpen();
    }

    void		setPosition(Vec3<float> newPos)
    {
      this->camera->setPosition(newPos);
    }
    
    void		setTarget(Vec3<float> newTarget)
    {
      this->camera->setTarget(newTarget);
    }
    
    void		setMode3D(bool status)
    {
      this->camera->setMode3D(status);
    }

    // METHOD
    
    void	addActor(AActor *actor)
    {
      actors.push_back(actor);
    }
    
  protected:
    std::vector<AActor *>	actors;
    
    bomber::ACamera	*camera;
    bomber::IWindow	*window;
  };
}

#endif /* _RENDERER_HPP_ */
