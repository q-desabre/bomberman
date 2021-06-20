
#include "Map.hpp"

namespace bomber
{
  Map::Map(const std::string& path, int nbPlayer = 2)
  {
    baseInit(path);
    generateBreakable();
  }

  void				Map::baseInit(const std::string &path)
  {
    std::shared_ptr<Cube>	tmp;
    int				y = 0;
    std::string			line;
    std::ifstream		myFile;
      
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
	    addBlock(v3(i, -1.0f, height - (y - 1)), "floorBlock", false);
	    if (line[i] == 'X') {
	      addBlock(v3(i, -0.5f, height - (y - 1)), "unbreakableBlock", true);
	    }
	  }
	}
	y++;
      }
      tmp = std::make_shared<Cube>(v3(0, -engine::CUBE_HEIGHT / 2 - 1, 0), "background");
      tmp->setSize(v3(2.5f * width, 0.2f, height * 2.5f));
      addActor(tmp);
    }
    myFile.close();
  }
    
  void				Map::generateBreakable()
  {
    int		x = 0;
    int		y = 0;
      
    for (int j = 0; j != height; j++)
      std::cout << map[j] << std::endl;
    for (int i = 0; i != 80 + rand() % 20;) {
      x = rand() % (width - 1);
      y = rand() % (height - 1);
      if (isSpawnOk(map, y, x)) {
	addBlock(v3(x, -0.5f, y), "breakableBlock", true, BREAKABLE);
	map[y][x] = 'b';
	i++;
      }
    }
  }
  
  void				Map::addBlock(const v3& pos, const std::string& textureName,
					      bool collide, BlockType t)
  {
    std::shared_ptr<Cube>		tmp;

    tmp = std::make_shared<Cube>(v3(width * -(engine::CUBE_SIZE / 2) +
				    (engine::CUBE_SIZE / 2) + pos.x,
				    (engine::CUBE_HEIGHT / 2) + pos.y,
				    height * (engine::CUBE_SIZE / 2) -
				    (engine::CUBE_SIZE / 2) - pos.z),
				 textureName, t);
    if (collide)
      collidableActors.push_back(tmp);
    addActor(tmp);
  }

  void				Map::addAnimatedBlock(const v3& pos, const std::string& textureName,
						      bool collide, BlockType t)
  {
    // Need new specific gestion to handle multiple texture
    // std::shared_ptr<AnimatedCube>		tmp;

    // tmp = std::make_shared<AnimatedCube>(v3(width * -(engine::CUBE_SIZE / 2) +
    // 					      (engine::CUBE_SIZE / 2) + pos.x,
    // 					      (engine::CUBE_HEIGHT / 2) + pos.y  - 0.48f,
    // 					      height * (engine::CUBE_SIZE / 2) -
    // 					      (engine::CUBE_SIZE / 2) - pos.z),
    // 					   textureName, 5);
    // if (collide)
    // 	collidableActors.push_back(tmp);
    // addActor(tmp);
  }


  // -------------------------------------------------------------------------------------------
  // ---------------------------------    GESTION ACTOR   --------------------------------------
  // -------------------------------------------------------------------------------------------
    
  void				Map::addActor(std::shared_ptr<engine::AActor> actor)
  {
    actors.push_back(actor);
  }
      
  void				Map::removeActor(std::shared_ptr<engine::AActor> actor)
  {
    for (int i = 0; i != actors.size(); i++) {
      if (actors[i]->getUid() == actor->getUid()) {
	std::cout << " remove actor " << actors[i]->getUid() << " nb " << i << std::endl;
	actors.erase(actors.begin() + i);
	break;
      }
    }
  }

  void				Map::removeCollidableActor(std::shared_ptr<engine::ICollidable> actor)
  {
    for (int i = 0; i != collidableActors.size(); i++) {
      if (collidableActors[i]->getUid() == actor->getUid()) {
	std::cout << " remove collidable nb " << i << " of " << collidableActors.size() << std::endl;
	collidableActors.erase(collidableActors.begin() + i);
	break;
      }
    }
  }
    
  void				Map::addCollidableActor(std::shared_ptr<engine::ICollidable> actor)
  {
    collidableActors.push_back(actor);
  }

  // -------------------------------------------------------------------------------------------
  // --------------------------------       GETTER      ----------------------------------------
  // -------------------------------------------------------------------------------------------

  const std::vector<std::string>&	Map::getData() const
  {
    return map;
  }

  std::shared_ptr<engine::AActor>	Map::getActorByUid(int uid)
  {
    for (int i = 0; i!= actors.size(); i++) {
      if (actors[i]->getUid() == uid)
	return actors[i];
    }
    return nullptr;
  }
    
  std::shared_ptr<engine::ICollidable>	Map::getCollidableActorByUid(int uid)
  {
    for (int i = 0; i!= collidableActors.size(); i++) {
      if (collidableActors[i]->getUid() == uid)
	return collidableActors[i];
    }
    return nullptr;
  }
  
  const std::vector<std::shared_ptr<engine::AActor>>&		Map::getActors() const
  {
    return (this->actors);
  }

  const std::vector<std::shared_ptr<engine::ICollidable>>&	Map::getCollidableActors() const
  {
    return (this->collidableActors);
  }

  

}
