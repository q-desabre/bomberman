
#include "ARenderer.hpp"

namespace engine
{
  void		ARenderer::clear()
  {
    this->window->clear();
  }
    
  void	ARenderer::close()
  {
    this->window->close();
  }
    
  bool	ARenderer::isOpen() const
  {
    return this->window->isOpen();
  }

  void		ARenderer::setPosition(const v3& newPos)
  {
    this->camera->setPosition(newPos);
  }

  const v3&		ARenderer::getPosition() const
  {
    return this->camera->getPosition();
  }
    
  void		ARenderer::setTarget(const v3& newTarget)
  {
    this->camera->setTarget(newTarget);
  }
    
  void		ARenderer::setMode3D(bool status)
  {
    this->camera->setMode3D(status);
  }
}
