
#ifndef _IMODEL_HPP_
# define _IMODEL_HPP_

# include "AActor.hpp"
# include "Vector.hpp"

namespace bomber
{
  class IModel : public AActor
  {
  public:
    virtual void	draw() = 0;
    virtual void	setScale(Vec3<float> scale) = 0;
    virtual Vec3<float>	getScale() const = 0;
    virtual Vec3<float> getPosition() const = 0;
    virtual void	setPosition(Vec3<float> position) = 0;
  };
  

};


#endif /* _IMODEL_HPP_ */
