
#ifndef _ARENDERER_HPP_
# define _ARENDERER_HPP_

# include <vector>
# include "AActor.hpp"

namespace engine
{
  class ARenderer : public IWindow , public ACamera
  {
  public:
    ARenderer() {}
    virtual ~ARenderer() {}

    virtual void        draw(std::vector<IDrawable*>) = 0;
    virtual void        updateEvents() = 0;
    virtual void	setFps(int fpsMax) = 0;
    virtual void	initWindow(const int, const int, const std::string&) = 0;
    virtual void	initCamera(const v3& pos, const v3& target,
				   const v3& up, float fovy) = 0;

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

    void		setPosition(const v3& newPos)
    {
      this->camera->setPosition(newPos);
    }

    const v3&		getPosition() const
    {
      v3 tmp = this->camera->getPosition();
      //      std::cout << "tmp.x " << tmp.x << " tmp.y " << tmp.y << " tmp.z " << tmp.z << std::endl;
      return this->camera->getPosition();
    }
    
    void		setTarget(const v3& newTarget)
    {
      this->camera->setTarget(newTarget);
    }
    
    void		setMode3D(bool status)
    {
      this->camera->setMode3D(status);
    }

    
  protected:
    ACamera	*camera;
    IWindow	*window;
  };
}

#endif /* _RENDERER_HPP_ */
