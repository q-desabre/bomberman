
#include "Utils.hpp"

namespace bomber
{
  bool		isCharInString(const std::string& str, char c)
  {
    for (int i = 0; i != str.size(); i++) {
      if (str[i] == c)
	return true;
    }
    return false;
  }
  
  bool		isSpawnOk(const std::vector<std::string>& map, int y, int x)
  {
    return (y != 0 && x != 0 && x != map[0].size() && y != map.size() &&
	    !isCharInString("1234", map[y + 1][x]) &&
	    !isCharInString("1234", map[y][x + 1]) &&
	    !isCharInString("1234", map[y - 1][x]) &&
	    !isCharInString("1234", map[y][x - 1]) &&
	    map[y][x] == ' ');
  }
}

