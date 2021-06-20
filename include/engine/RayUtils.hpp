
#ifndef _RAY_UTILS_HPP
# define _RAY_UTILS_HPP

# include "Vector.hpp"

namespace bomber
{
  Vector3	toVector3(Vec3<float> v)
  {
    return (Vector3){v.x, v.y, v.z};
  }
};

#endif /* _RAY_UTILS_HPP */
