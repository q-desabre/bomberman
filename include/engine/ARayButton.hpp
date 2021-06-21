

#ifndef _RAY_BUTTON_HPP
# define _RAY_BUTTON_HPP

# include "raylib.h"
# include "AWidget.hpp"

namespace bomber
{
  class Core;
}

namespace engine
{
  enum ButtonState
    {
     DEFAULT,
     HOVER,
     CLICKED
    };
  
  class ARayButton : public AWidget
  {
  public:
    ARayButton(const v2& pos, const std::string& t, const std::string& tH,
	       const std::string& tC);


    void			draw();
    void			update(bomber::Core &core);
    
    virtual void		onClick(bomber::Core & core) = 0;

  protected:
    ButtonState			state;			
    Rectangle			hitBox;
    Texture2D			texture;
    Texture2D			textureHover;
    Texture2D			textureClicked;
    Color			tint;
  };
}


#endif /* _RAY_BUTTON_HPP */
