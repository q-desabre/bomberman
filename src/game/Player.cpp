
#include "Player.hpp"
#include "APowerUp.hpp"

namespace bomber
{
  Player::Player(int _id) : id(_id)
  {
    this->bombMax = 1;
    this->power = 2;
    this->alive = true;
    this->canSpawnBomb = true;
    this->wallPass = false;
    this->isMoving = false;
    if (id == 1) 
      this->model = std::make_unique<engine::RayAnimation>("../assets/steve/steve_0000",
							   "player1", 40);
    else if (id == 2)
      this->model = std::make_unique<engine::RayAnimation>("../assets/steve/steve_0000",
							   "player2", 40);
    this->collisionBox = std::make_unique<engine::RayCollisionBox>(this->model->getPosition(),
								   Vec3<float>(0.55, 0.55, 0.55));
    std::cout << "create player id " << id << std::endl;
  }
    

  void		Player::update(const engine::ABind& key, Map& map)
  { // change to std::map<event, ptr method> depends on id
    updateBombs(map);
    action(key, map);
  }

  void		Player::action(const engine::ABind& key, Map& map)
  {
    if (isAlive()) {
      Vec3<float> tmpPos = this->position;
      if (id == 1) {
	this->isMoving = false;
	if (key.isEvent(engine::PLAYER1_DOWN)) moveDown(map);
	if (key.isEvent(engine::PLAYER1_UP)) moveUp(map);
	if (key.isEvent(engine::PLAYER1_RIGHT)) moveRight(map);
	if (key.isEvent(engine::PLAYER1_LEFT)) moveLeft(map);
	movementCollide(tmpPos, map);
	if (key.isEvent(engine::PLAYER1_ACTION)) spawnBomb(map);
      } else if (id == 2) {
	this->isMoving = false;
	if (key.isEvent(engine::PLAYER2_DOWN)) moveDown(map);
	if (key.isEvent(engine::PLAYER2_UP)) moveUp(map);
	if (key.isEvent(engine::PLAYER2_RIGHT)) moveRight(map);
	if (key.isEvent(engine::PLAYER2_LEFT)) moveLeft(map);
	movementCollide(tmpPos, map);

      }
    }
  }

  void		Player::updateBombs(Map &map)
  {
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
  }

  void		Player::movementCollide(const v3& tmpPos, Map &map)
  {
    this->collisionBox->setPosition(this->position);
    for (int i = 0; i != map.getCollidableActors().size(); i++) {
      if (map.getCollidableActors()[i]->getUid() != this->getUid() &&
	  map.getCollidableActors()[i]->collide(*collisionBox)) {
	if (collideWithFlame(tmpPos, map, i)) return;
	
	if (collideWithBomb(tmpPos, map, i)) return;

	if (collideWithCube(tmpPos, map, i)) return;
      }
    }
  }
    
  bool		Player::collideWithCube(const v3& tmpPos, Map &map, int i)
  {
    Cube * c = dynamic_cast<Cube*>(map.getCollidableActors()[i].get());
    if (c && (c->getType() == BREAKABLE || c->getType() == UNBREAKABLE)) {
      if (this->wallPass && c->getType() == BREAKABLE) {
	canSpawnBomb = false;
	return false;
      }
      this->position = tmpPos;
      this->isMoving = false;
      this->collisionBox->setPosition(this->position);
      return true;
    } else if (c && c->getType() == BONUS) {
      APowerUp *p = dynamic_cast<APowerUp*>(c);
      p->effect(*this);
      map.removeActor(map.getActorByUid(c->getUid()));
      map.removeCollidableActor(map.getCollidableActorByUid(c->getUid()));
      return true;
    }
    return false;
  }

  bool		Player::collideWithFlame(const v3& tmpPos, Map &map, int i)
  {
    Flame * f = dynamic_cast<Flame*>(map.getCollidableActors()[i].get());
    if (f) {
      this->die();
      return true;
    }
    return false;
  }

  bool		Player::collideWithBomb(const v3& tmpPos, Map &map, int i)
  {
    Bomb * b = dynamic_cast<Bomb*>(map.getCollidableActors()[i].get());
    if (b && b->getOwnerUid() == getUid() && b->getIsOverOwner()) {
      return false;
    } else if (b) {
      this->position = tmpPos;
      this->isMoving = false;
      this->collisionBox->setPosition(this->position);
      return true;
    } else
      return false;
  }
    

  void		Player::spawnBomb(Map& map)
  {
    if (!canSpawnBomb)
      return;
    for (int i = 0; i != bombs.size(); i++) {
      if (this->collide(bombs[i]->getCollider()))
	return;
    }
    if (bombs.size() == bombMax)
      return ;
    v3 p(this->position.x, this->position.y + 0.5f, this->position.z);
    std::shared_ptr<Bomb>	b = std::make_shared<Bomb>(p, this->power, getUid());
    map.addActor(b);
    map.addCollidableActor(b);
    bombs.push_back(b);
  }

  void		Player::draw()
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

  void		Player::moveUp(const Map& map)
  {
    canSpawnBomb = true;
    this->isMoving = true;
    this->model->rotate(0.0f);
    this->position.z -= 0.1f;
  }

  void		Player::moveDown(const Map& map)
  {
    canSpawnBomb = true;
    this->isMoving = true;
    this->model->rotate(180.0f);
    this->position.z += 0.1f;
  }

  void		Player::moveLeft(const Map& map)
  {
      canSpawnBomb = true;
    this->isMoving = true;
    this->model->rotate(90.0f);
    this->position.x -= 0.1f;
  }

  void		Player::moveRight(const Map& map)
  {
      canSpawnBomb = true;
    this->isMoving = true;
    this->model->rotate(-90.0f);
    this->position.x += 0.1f;
  }

  const engine::ACollider&	Player::getCollider() const
  {
    return *(this->collisionBox);
  }

  bool				Player::collide(const engine::ACollider& other) const
  {
    return this->collisionBox->collide(other);
  }

  int		Player::getPower() const
  {
    return this->power;
  }

  int		Player::getBombMax() const
  {
    return this->power;
  }

  bool	Player::isAlive() const
  {
    return this->alive;
  }

  void	Player::setPower(int p)
  {
    this->power = p;
  }

  void	Player::setBombMax(int bm)
  {
    this->bombMax = bm;
  }

  void	Player::setSpeed(float newSpeed)
  {
    if (newSpeed <= 0.8f)
      this->speed = newSpeed;
  }

  void			Player::setWallPass(bool b)
  {
    this->wallPass = b;
  }

  float			Player::getSpeed() const
  {
    return this->speed;
  }
  
  int			Player::getUid() const
  {
    return uid;
  }
  
  void	Player::die()
  {
    this->alive = false;
  }

}
