
#ifndef _UTILS_BOMBER_HPP_
# define _UTILS_BOMBER_HPP_

#include <vector>
#include <iostream>

namespace bomber
{
  bool		isCharInString(const std::string & str, char c);
  bool		isSpawnOk(const std::vector<std::string>& map, int y, int x);
}


#endif /* _UTILS_BOMBER_HPP_ */
