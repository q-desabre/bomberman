
#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

# include "RayAnimation.hpp"
# include "RayCollisionBox.hpp"
# include "RayBind.hpp"
# include "Bomb.hpp"
# include "Map.hpp"

namespace bomber
{

  class Player : public engine::AActor, public engine::ICollidable
  {
  private:
    int						power;
    int						bombMax;
    bool					alive;
    bool					isMoving;
    int						id;
    std::vector<std::shared_ptr<Bomb>>		bombs;
    std::unique_ptr<engine::RayAnimation>	model;
    std::unique_ptr<engine::ACollider>		collisionBox;

  public:
    Player(int _id);
    
    void		update(const engine::ABind& key, Map& map);    
    void		action(const engine::ABind& key, Map& map);
    void		spawnBomb(Map& map);
    void		updateBombs(Map &map);

    void		moveUp(const Map& map);
    void		moveDown(const Map& map);
    void		moveLeft(const Map& map);
    void		moveRight(const Map& map);
    
    void		movementCollide(const v3& tmpPos, Map &map);    
    bool		collideWithCube(const v3& tmpPos, Map &map, int i);
    bool		collideWithBomb(const v3& tmpPos, Map &map, int i);
    
    void		draw();
    
    void		die();
    bool		isAlive() const;
  
    void		setPower(int p);
    int			getPower() const;

    void		setBombMax(int bm);
    int			getBombMax() const;
    
    int			getUid() const;

    const engine::ACollider&	getCollider() const;
    bool			collide(const engine::ACollider& other) const;
  };

}
#endif /* _PLAYER_HPP_ */
