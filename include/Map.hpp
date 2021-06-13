#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <memory>
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
      std::shared_ptr<Cube>		tmp;
      int				y = 0;
      std::string			line;
      std::ifstream			myFile;
      
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
	      addBlock(v3(i, -1, height - (y - 1)), "../assets/block5.png", false);
	      if (line[i] == 'X') {
		addBlock(v3(i, 0, height - (y - 1)), "../assets/block4.png", true);
	      }
	    }
	  }
	  y++;
	}
	tmp = std::make_shared<Cube>(v3(0, -engine::CUBE_HEIGHT / 2 - 1, 0),
				     "../assets/block_background.png");
	tmp->setSize(v3(2.5f * width, 0.2f, height * 2.5f));
	addActor(tmp);
      }
      myFile.close();
           // generateBreakable();
    }

    void		generateBreakable()
    {
      int		x = 0;
      int		y = 0;
      
      for (int j = 0; j != height; j++)
	std::cout << map[j] << std::endl;
      for (int i = 0; i != 80 + rand() % 20;) {
	x = rand() % (width - 1);
	y = rand() % (height - 1);
	if (isSpawnOk(map, y, x)) {
	  addBlock(v3(x, 0, y), "../assets/block_brick.png", true, BREAKABLE);
	  map[y][x] = 'b';
	  i++;
	}
      }
    }
  
    void		addBlock(const v3& pos, const std::string& path, bool collide,
				 BlockType t = UNBREAKABLE)
    {
      std::shared_ptr<Cube>		tmp;

      tmp = std::make_shared<Cube>(v3(width * -(engine::CUBE_SIZE / 2) +
				      (engine::CUBE_SIZE / 2) + pos.x,
				      (engine::CUBE_HEIGHT / 2) + pos.y,
				      height * (engine::CUBE_SIZE / 2) -
				      (engine::CUBE_SIZE / 2) - pos.z),
				   path.c_str(), t);
      if (collide)
	collidableActors.push_back(tmp);
      addActor(tmp);
    }

    ~Map() {}

    const std::vector<std::shared_ptr<engine::AActor>>&	getActors() const
    {
      return (this->actors);
    }

    const std::vector<std::shared_ptr<engine::ICollidable>>&	getCollidableActors() const
    {
      return (this->collidableActors);
    }

    const std::vector<std::string>&		getData() const
    {
      return map;
    }
    
    void			addActor(std::shared_ptr<engine::AActor> actor)
    {
      actors.push_back(actor);
    }
      
    void			removeActor(std::shared_ptr<engine::AActor> actor)
    {
      std::cout << "Remove id : " << actor->getUid() << " / " << actors.size() << std::endl;
      for (int i = 0; i != actors.size(); i++) {
	if (actors[i]->getUid() == actor->getUid()) {
	  actors.erase(actors.begin() + i);
	  break;
	}
      }
    }

    void			removeCollidableActor(std::shared_ptr<engine::ICollidable> actor)
    {
      for (int i = 0; i != collidableActors.size(); i++) {
	if (collidableActors[i]->getUid() == actor->getUid()) {
	  collidableActors.erase(collidableActors.begin() + i);
	  break;
	}
      }
    }

    std::shared_ptr<engine::AActor>	getActorByUid(int uid)
    {
      for (int i = 0; i!= actors.size(); i++) {
	if (actors[i]->getUid() == uid)
	  return actors[i];
      }
      return nullptr;
    }
    
    void			addCollidableActor(std::shared_ptr<engine::ICollidable> actor)
    {
      collidableActors.push_back(actor);
    }
      
  private:
    int				width = 0;
    int				height = 0;
    std::vector<std::string>	map;
    std::vector<std::shared_ptr<engine::AActor>>	actors;
    std::vector<std::shared_ptr<engine::ICollidable>>	collidableActors;
  };
}

#endif /* _MAP_HPP_ */
