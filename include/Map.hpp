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
	blocks.push_back(tmp);
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
	std::cout << width << " " << height << std::endl;
	std::cout << "[" << y << "][" << x << "]" << map[y][x] << std::endl;
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
	collidableBlocks.push_back(tmp);
      blocks.push_back(tmp);
    }

    
    // Map(int w, int h) : width(w), height(h)
    // {
    //   Cube	*tmp;
    //   Cube 	*tmp2;
    //   v3	pos(w  * -(engine::CUBE_SIZE / 2) + (engine::CUBE_SIZE / 2),
    // 		    engine::CUBE_HEIGHT / 2,
    // 		    h * (engine::CUBE_SIZE / 2) - (engine::CUBE_SIZE / 2));

    //   blocks.push_back(tmp);

    //   int maxCube = 50 + rand() % 20;
    //   for (int i = 0; i != maxCube; i++)
    // 	{
    // 	  int tmpX = rand() % 17;
    // 	  int tmpY = rand() % 11;
    // 	  v3 tmpPos = pos;

    // 	  tmpPos.x += tmpX;
    // 	  tmpPos.z -= tmpY;
    // 	  tmp = new Cube(tmpPos, "../assets/block_brick.png");
    // 	  blocks.push_back(tmp);
    // 	}
      
      
    //   for (int i = 0; i != width; i++) {
    // 	pos.z = h * (engine::CUBE_SIZE / 2) - (engine::CUBE_SIZE / 2);
    // 	for (int j = 0; j != height; j++) {
    // 	  if (j == 0 || j == height - 1 || i == 0 || i == width - 1) {

    // 	    tmp = new Cube(pos, "../assets/block4.png");
    // 	    blocks.push_back(tmp);
    // 	    collidableBlocks.push_back(tmp);
    // 	  } else if (i % 2 == 0 && j % 2 == 0) {
    // 	    tmp = new Cube(pos, "../assets/block4.png");
    // 	    blocks.push_back(tmp);
    // 	    collidableBlocks.push_back(tmp);
    // 	  } else {
    // 	    pos.y -= 1;
    // 	    tmp2 = new Cube(pos, "../assets/block5.png");
    // 	    blocks.push_back(tmp2);
    // 	    pos.y += 1;
    // 	  }
	    
    // 	  pos.z -= engine::CUBE_SIZE;
    // 	}
    // 	pos.x += engine::CUBE_SIZE;
    //   }

    // }
    ~Map() {}

    const std::vector<Cube *>&	getBlocks() const
    {
      return (this->blocks);
    }

    const std::vector<Cube *>&	getCollidableBlocks() const
    {
      return (this->collidableBlocks);
    }

      
  private:
    int				width;
    int				height;
    std::vector<std::string>	map;
    std::vector<Cube *>		blocks;
    std::vector<Cube *>		collidableBlocks;
  };
}

#endif /* _MAP_HPP_ */
