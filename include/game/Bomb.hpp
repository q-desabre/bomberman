
#ifndef _BOMB_HPP_
# define _BOMB_HPP_

#include <memory>
#include "AActor.hpp"
#include "RayModel.hpp"
#include "Timer.hpp"
#include "Flame.hpp"
#include "Map.hpp"

namespace bomber
{
  class Cube;
  
  class Bomb : public engine::AActor, public engine::ICollidable
  {
  public:
    Bomb(const v3& pos, int p, int uid);
    
    void			lineFlame(Map &map, const v3& direction);
    void			explode(Map &map);
    void			update(Map &map);
    void			draw();
    bool			isAlive() const;
    int				getUid() const;
    int				getOwnerUid() const;
    bool			getIsOverOwner() const;
    void			setIsOverOwner(bool b);
    bool			collide(const engine::ACollider& other) const;
    const engine::ACollider&	getCollider() const;

  private:
    void		snapToGrid(const v3& pos);
    bool		collideWithCube(Map & map, int i);
    bool		collideWithPlayer(Map & map, int i);
    bool		collideWithBomb(Map & map, int i);
        
  private:
    bool		alive;
    bool		exploded;
    float		lifespan;
    int			power;
    int			ownerUid;
    bool		isOverOwner;
    engine::Timer	timer;
    std::vector<std::shared_ptr<Flame>>	flames;
    std::unique_ptr<engine::RayModel>	model;
    std::unique_ptr<engine::ACollider>	collisionBox;
  };
};

#endif /* _BOMB_HPP_ */
