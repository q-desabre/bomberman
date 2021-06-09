
#ifndef _ICOLLIDABLE_HPP_
# define _ICOLLIDABLE_HPP_

# include "ACollider.hpp"

namespace bomber
{
  
  class ICollidable
  {
  public:
    virtual const ACollider&	getCollider() const = 0;
    virtual bool		collide(const ACollider& other) const = 0; 
  };

}

#endif /* _ICOLLIDABLE_HPP_ */
