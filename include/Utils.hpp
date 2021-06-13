
#ifndef _UTILS_HPP_
# define _UTILS_HPP_


#include <vector>
#include <iostream>

namespace engine
{
  int		generateUid();
}

namespace bomber
{
  bool		isCharInString(const std::string & str, char c);
  bool		isSpawnOk(const std::vector<std::string>& map, int y, int x);
}


#endif /* _UTILS_HPP_ */
