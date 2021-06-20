#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <memory>
# include <fstream>
# include <vector>
# include "Cube.hpp"
# include "Utils.hpp"
# include "UtilsBomber.hpp"
# include "TextureManager.hpp"

namespace bomber
{
  class Map
  {
  private:
    int							width = 0;
    int							height = 0;
    std::vector<std::string>				map;
    std::vector<std::shared_ptr<engine::AActor>>	actors;
    std::vector<std::shared_ptr<engine::ICollidable>>	collidableActors;

  public:
    Map(const std::string& path, int nbPlayer);

    void	baseInit(const std::string &path);
    void	generateBreakable();
    
    void	addBlock(const v3& p, const std::string& tm, bool c, BlockType t = UNBREAKABLE);
    void	addAnimatedBlock(const v3& p, const std::string& tm, bool c, BlockType t = UNBREAKABLE);

    void	addActor(std::shared_ptr<engine::AActor> actor);
    void	addCollidableActor(std::shared_ptr<engine::ICollidable> actor);
      
    void	removeActor(std::shared_ptr<engine::AActor> actor);
    void	removeCollidableActor(std::shared_ptr<engine::ICollidable> actor);
    
    

    const std::vector<std::shared_ptr<engine::AActor>>&		getActors() const;
    const std::vector<std::shared_ptr<engine::ICollidable>>&	getCollidableActors() const;
    const std::vector<std::string>&				getData() const;
    std::shared_ptr<engine::AActor>				getActorByUid(int uid);
    std::shared_ptr<engine::ICollidable>			getCollidableActorByUid(int uid);
  };
}

#endif /* _MAP_HPP_ */
