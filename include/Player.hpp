
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
  public:
    Player(int _id) : id(_id)
    {
      this->bombMax = 1;
      this->power = 2;
      this->alive = true;
      this->isMoving = false;
      if (id == 1) 
	this->model = std::make_unique<engine::RayAnimation>("../assets/steve/steve_0000",
							     "player1", 40);
      else if (id == 2)
	this->model = std::make_unique<engine::RayAnimation>("../assets/steve/steve_0000",
							     "player2", 40);
      this->collisionBox = std::make_unique<engine::RayCollisionBox>(this->model->getPosition(),
								     Vec3<float>(0.55, 0.55, 0.55));
    }
    
    ~Player()
    {
      std::cout << __func__ << std::endl;
    }


    int			getUid() const
    {
      return uid;
    }

    void		update(const engine::ABind& key, Map& map)
    { // change to std::map<event, ptr method> depends on id
      Vec3<float> tmpPos = this->position;

      for (int i = 0; i != bombs.size(); i++) {
	bombs[i]->update(map);
	if (!bombs[i]->collide(this->getCollider()))
	    bombs[i]->setIsOverOwner(false);
	if (bombs[i]->isAlive() == false) {
	  map.removeActor(bombs[i]);
	  bombs.erase(bombs.begin() + i);
	  i = -1;
	  continue;
	}
      }

      if (isAlive()) {
	if (id == 1) {
	  this->isMoving = false;
	  if (key.isEvent(engine::PLAYER1_DOWN)) moveDown(map);
	  if (key.isEvent(engine::PLAYER1_UP)) moveUp(map);
	  if (key.isEvent(engine::PLAYER1_RIGHT)) moveRight(map);
	  if (key.isEvent(engine::PLAYER1_LEFT)) moveLeft(map);
	  if (key.isEvent(engine::PLAYER1_ACTION)) spawnBomb(map);
	} else if (id == 2) {
	  this->isMoving = false;
	  if (key.isEvent(engine::PLAYER2_DOWN)) moveDown(map);
	  if (key.isEvent(engine::PLAYER2_UP)) moveUp(map);
	  if (key.isEvent(engine::PLAYER2_RIGHT)) moveRight(map);
	  if (key.isEvent(engine::PLAYER2_LEFT)) moveLeft(map);
	}
	this->collisionBox->setPosition(this->position);
	for (int i = 0; i != map.getCollidableActors().size(); i++) {
	  if (map.getCollidableActors()[i]->getUid() != this->getUid() &&
	      map.getCollidableActors()[i]->collide(*collisionBox)) {
	    Bomb * b = dynamic_cast<Bomb*>(map.getCollidableActors()[i].get());
	    if (b && b->getOwnerUid() == getUid() && b->getIsOverOwner())
	      continue;
	    this->position = tmpPos;
	    this->isMoving = false;
	    this->collisionBox->setPosition(this->position);
	  }
	}
      }
    }
    
    void		moveUp(const Map& map)
    {
      this->isMoving = true;
      this->model->rotate(0.0f);
      this->position.z -= 0.1f;
    }

    void		moveDown(const Map& map)
    {
      this->isMoving = true;
      this->model->rotate(180.0f);
      this->position.z += 0.1f;
    }

    void		moveLeft(const Map& map)
    {
      this->isMoving = true;
      this->model->rotate(90.0f);
      this->position.x -= 0.1f;
    }

    void		moveRight(const Map& map)
    {
      this->isMoving = true;
      this->model->rotate(-90.0f);
      this->position.x += 0.1f;
    }
    
    const engine::ACollider&	getCollider() const
    {
      return *(this->collisionBox);
    }

    bool		collide(const engine::ACollider& other) const
    {
      return this->collisionBox->collide(other);
    }

    void	draw()
    {
      if (isAlive()) {
	this->collisionBox->setPosition(this->position);
	this->model->setPosition(this->position);
	if (isMoving)
	  this->model->draw();
	else
	  this->model->draw(0);
      }
      // DrawCubeWires((Vector3){position.x, position.y + 0.5, position.z}, 0.55,
      // 		    0.55, 0.55, RED);
    }

    void	draw(int frame = 1)
    {
      if (isAlive()) {
	this->collisionBox->setPosition(this->position);
	this->model->setPosition(this->position);
	if (isMoving)
	  this->model->draw();
	else
	  this->model->draw(0);
	//      DrawCubeWires((Vector3){position.x, position.y + 1.6f, position.z},
	// 1, 3.2, 1, RED);
      }
    }

    void	spawnBomb(Map& map)
    {
      for (int i = 0; i != bombs.size(); i++) {
	if (this->collide(bombs[i]->getCollider()))
	  return;
      }
      
      std::shared_ptr<Bomb>	b = std::make_shared<Bomb>(v3(this->position.x,
							      this->position.y + 0.5f,
							      this->position.z), 2,
							   getUid());

      map.addActor(b);
      map.addCollidableActor(b);
      bombs.push_back(b);
    }

    int		getPower() const
    {
      return this->power;
    }

    int		getBombMax() const
    {
      return this->power;
    }

    bool	isAlive() const
    {
      return this->alive;
    }

    void	setPower(int p)
    {
      this->power = p;
    }

    void	setBombMax(int bm)
    {
      this->bombMax = bm;
    }

    void	die()
    {
      this->alive = false;
    }

  private:
    int						power;
    int						bombMax;
    bool					alive;
    bool					isMoving;
    int						id;
    std::vector<std::shared_ptr<Bomb>>		bombs;
    std::unique_ptr<engine::RayAnimation>	model;
    std::unique_ptr<engine::ACollider>		collisionBox;
  };

}
#endif /* _PLAYER_HPP_ */
