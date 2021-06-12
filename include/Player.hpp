
#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

# include "RayModel.hpp"
# include "RayCollisionBox.hpp"
# include "RayBind.hpp"
# include "Map.hpp"

namespace bomber
{

  class Player : public engine::AActor, public engine::ICollidable
  {
  public:
    Player(int _id) : id(_id)
    {
      this->isMoving = false;
      if (id == 1) 
	this->model = new engine::RayModel("../assets/steve/steve_0000",
					   "../assets/steve/skin.png", 40);
      else if (id == 2)
	this->model = new engine::RayModel("../assets/steve/steve_0000",
					   "../assets/steve/skin2.png", 40);
      	
      this->collisionBox = new engine::RayCollisionBox(this->model->getPosition(),
					       Vec3<float>(0.55, 0.55, 0.55));
    }
    
    ~Player()
    {

    }

    void		update(const engine::ABind& key, const Map& map)
    { // change to std::map<event, ptr method> depends on id
      Vec3<float> tmpPos = this->position;
      
      if (id == 1) {
	this->isMoving = false;
	if (key.isEvent(engine::PLAYER1_DOWN)) moveDown(map);
	if (key.isEvent(engine::PLAYER1_UP)) moveUp(map);
	if (key.isEvent(engine::PLAYER1_RIGHT)) moveRight(map);
	if (key.isEvent(engine::PLAYER1_LEFT)) moveLeft(map);
      } else if (id == 2) {
	this->isMoving = false;
	if (key.isEvent(engine::PLAYER2_DOWN)) moveDown(map);
	if (key.isEvent(engine::PLAYER2_UP)) moveUp(map);
	if (key.isEvent(engine::PLAYER2_RIGHT)) moveRight(map);
	if (key.isEvent(engine::PLAYER2_LEFT)) moveLeft(map);
      }
      this->collisionBox->setPosition(this->position);
      for (int i = 0; i != map.getCollidableBlocks().size(); i++) {
	if (map.getCollidableBlocks()[i]->collide(*collisionBox)) {
	    this->position = tmpPos;
	    this->isMoving = false;
	    this->collisionBox->setPosition(this->position);
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
      this->collisionBox->setPosition(this->position);
      this->model->setPosition(this->position);
      if (isMoving)
	this->model->draw();
      else
	this->model->draw(0);
      // DrawCubeWires((Vector3){position.x, position.y + 0.5, position.z}, 0.55,
      // 		    0.55, 0.55, RED);
    }

    void	draw(int frame = 1)
    {
      this->collisionBox->setPosition(this->position);
      this->model->setPosition(this->position);
      if (isMoving)
	this->model->draw();
      else
	this->model->draw(0);
      //      DrawCubeWires((Vector3){position.x, position.y + 1.6f, position.z}, 1, 3.2, 1, RED);
    }

  private:
    bool	isMoving;
    int		id;
    engine::AActor	*model;
    engine::ACollider	*collisionBox;
  };

}
#endif /* _PLAYER_HPP_ */
