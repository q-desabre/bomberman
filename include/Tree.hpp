
#ifndef _TREE_HPP_
# define _TREE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <Vector.hpp>
#include <sstream>
#include "AActor.hpp"

namespace bomber
{
  class Tree : public engine::AActor
  {
  public:
    Tree(v3 pos)
    {
      srand(time(NULL));
      this->position = pos;
      this->scale.x = rand() % 100 * 0.00075f;
      this->scale.y = rand() % 100 * 0.00075f;
      this->scale.z = rand() % 100 * 0.00075f;
      this->rotation.x = 0;
      this->rotation.y = 1;
      this->rotation.z = 0;
      model = LoadModel("../assets/tree/myTree.obj");
      texture = LoadTexture("../assets/tree/MyTexture.png");
      model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    }

    ~Tree()
    {

    }

    virtual void		draw()
    {
      DrawModelEx(model,
		  (Vector3){position.x, position.y, position.z},
		  (Vector3){rotation.x, rotation.y, rotation.z},
		  angleRotation,
		  (Vector3){scale.x, scale.y, scale.z}, WHITE);
    }

    virtual void		draw(int frame)
    {
      DrawModelEx(model,
		  (Vector3){position.x, position.y, position.z},
		  (Vector3){rotation.x, rotation.y, rotation.z},
		  angleRotation,
		  (Vector3){scale.x, scale.y, scale.z}, WHITE);
    }

  protected:
    Texture2D		texture;
    Color		color;
    Model		model;
  };
  
    
}


#endif /* _TREE_HPP_ */
