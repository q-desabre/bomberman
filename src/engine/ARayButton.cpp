
#include "ARayButton.hpp"
#include "TextureManager.hpp"
#include "Core.hpp"

namespace engine
{
  ARayButton::ARayButton(const v2& pos, const std::string& t, const std::string& tH,
			 const std::string& tC)
  {
    this->position.x = pos.x;
    this->position.y = pos.y;
    state = DEFAULT;
    this->tint = WHITE;
    texture = TextureManager<Texture2D>::getInstance().getTexture(t);
    textureHover = TextureManager<Texture2D>::getInstance().getTexture(tH);
    textureClicked = TextureManager<Texture2D>::getInstance().getTexture(tC);
    hitBox = { (GetScreenWidth() / 100.0f) * pos.x - texture.width / 2.0f,
	       (GetScreenHeight() / 100.0f) * pos.y - texture.height / 2.0f,
	       (float)texture.width,
	       (float)texture.height };
  }


  void			ARayButton::draw()
  {
    switch (state) {
    case DEFAULT:
      DrawTexture(this->texture,
		  (GetScreenWidth() / 100.0f) * position.x - this->texture.width / 2,
		  (GetScreenHeight() / 100.0f)  * position.y - this->texture.height / 2,
		  this->tint);
      break;
    case HOVER:
      DrawTexture(this->textureHover,
		  (GetScreenWidth() / 100.0f) * position.x - this->texture.width / 2,
		  (GetScreenHeight() / 100.0f)  * position.y - this->texture.height / 2,
		  this->tint);
      break;
    case CLICKED:
      DrawTexture(this->textureClicked,
		  (GetScreenWidth() / 100.0f) * position.x - this->texture.width / 2,
		  (GetScreenHeight() / 100.0f)  * position.y - this->texture.height / 2,
		  this->tint);
      break;
    default:
      break;
    }
  }
  
  void			ARayButton::update(bomber::Core &core)
  {
    static bool		b = false;
    Vector2		mouse;

    mouse.x = core.getKeybind().getMousePosition().x;
    mouse.y = core.getKeybind().getMousePosition().y;

    state = DEFAULT;
    if (core.getKeybind().isMouseClicked() == false)
      b = false;
    if (CheckCollisionPointRec(mouse,hitBox) && core.getKeybind().isMouseClicked() && !b) {
      std::cout << "Clicked ! " << std::endl;
      state = CLICKED;
      this->onClick(core);
      b = true;
    } else if (CheckCollisionPointRec(mouse,hitBox)) {
      state = HOVER;
    } else {
      state = DEFAULT;
    }
    
  }

}
