
#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

# include <iostream>

template <class T>
class		Vec2
{
public:
  Vec2()
  {
    x = 0;
    y = 0;
  }
  Vec2(T _x, T _y) : x(_x), y(_y) {}
  
  Vec2(const Vec2<T>& other)
  {
    this->x = other.x;
    this->y = other.y;
  }

  Vec2<T>&	operator=(const Vec2<T>& other)
  {
    this->x = other.x;
    this->y = other.y;
    return (*this);
  }
  
  ~Vec2() {}
      
  T	x;
  T	y;
};


template <class T>
class		Vec3
{
public:
  Vec3()
  {
    x = 0;
    y = 0;
    z = 0;
  }
  Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
  
  Vec3(const Vec3<T>& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
  }

  Vec3<T>&	operator=(const Vec3<T>& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return (*this);
  }
  
  ~Vec3() {}



  T	x;
  T	y;
  T	z;
};


template <class T>
std::ostream& operator<<( std::ostream &flux, Vec3<T> const& v )
{
  return flux << "x -> " << v.x << " y -> " << v.y << " z -> " << v.z << std::endl;
}


typedef Vec3<float> v3;
typedef Vec2<float> v2;

#endif /* _VECTOR_HPP_ */
