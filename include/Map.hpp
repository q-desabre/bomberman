#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <fstream>
# include <vector>
# include "Cube.hpp"
# include "Utils.hpp"
# include "AnimatedCube.hpp"

namespace bomber
{
  class Map
  {
  public:
    Map(const std::string& path, int nbPlayer = 2)
    {
      Cube		*tmp;
      int		y = 0;
      std::string	line;
      std::ifstream	myFile;
      
      myFile.open(path);
      if (myFile.is_open()) {
	while (getline(myFile, line)) {
	  if (y == 0)
	    width = std::atoi(line.c_str());
	  else if (y == 1)
	    height = std::atoi(line.c_str());
	  else {
	    map.push_back(line);
	    for (int i = 0; i != line.size(); i++) {
	      addBlock(v3(i, -1, y - 2), "../assets/block5.png", false);
	      if (line[i] == 'X') {
		addBlock(v3(i, 0, y - 2), "../assets/block4.png", true);
	      }
	    }
	  }
	  y++;
	}
	tmp = new Cube(v3(0, -engine::CUBE_HEIGHT / 2 - 1, 0),
		       "../assets/block_background.png");
	tmp->setSize(v3(2.5f * width, 0.2f, height * 2.5f));
	actors.push_back(tmp);
      }
      myFile.close();
      generateBreakable();
    }

    void		generateBreakable()
    {
      int		x;
      int		y;
      
      for (int j = 0; j != height; j++)
	std::cout << map[j] << std::endl;
      for (int i = 0; i != 80 + rand() % 20;) {
	x = rand() % (width - 1);
	y = rand() % (height - 1);
	if (isSpawnOk(map, y, x)) {
	  addBlock(v3(x, 0, y), "../assets/block_brick.png", true);
	  map[y][x] = 'b';
	  i++;
	}
      }
    }
  
    void		addBlock(const v3& pos, const std::string& path, bool collide)
    {
      Cube		*tmp;

      tmp = new Cube(v3(width * -(engine::CUBE_SIZE / 2) + (engine::CUBE_SIZE / 2) + pos.x,
			(engine::CUBE_HEIGHT / 2) + pos.y,
			height * (engine::CUBE_SIZE / 2) - (engine::CUBE_SIZE / 2) - pos.z),
		     path.c_str());
      if (collide)
	collidableActors.push_back(tmp);
      actors.push_back(tmp);
    }

    ~Map() {}

    const std::vector<engine::AActor *>&	getActors() const
    {
      return (this->actors);
    }

    const std::vector<engine::ICollidable *>&	getCollidableActors() const
    {
      return (this->collidableActors);
    }

    const std::vector<std::string>&		getData() const
    {
      return map;
    }
    
    void			addActor(engine::AActor *actor)
    {
      actors.push_back(actor);
    }
      
    void			removeActor(engine::AActor *actor)
    {
      std::cout << actors.size() << std::endl;
      for (int i = 0; i != actors.size(); i++) {
	if (actors[i]->getUid() == actor->getUid())
	  actors.erase(actors.begin() + i);
      }
      std::cout << actors.size() << std::endl;
    }
      
    void			addCollidableActor(engine::ICollidable *actor)
    {
      collidableActors.push_back(actor);
    }
      
  private:
    int				width;
    int				height;
    std::vector<std::string>	map;
    std::vector<engine::AActor *>	actors;
    std::vector<engine::ICollidable *>	collidableActors;
  };
}

#endif /* _MAP_HPP_ */
