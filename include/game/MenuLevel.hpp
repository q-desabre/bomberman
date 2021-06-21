
#ifndef MENU_LEVEL_HPP
# define MENU_LEVEL_HPP

# include "ALevel.hpp"
# include "RayImage.hpp"
# include "RaySkyBox.hpp"
# include "PlayButton.hpp"

namespace bomber
{
  class Core;
  
  class	MenuLevel : public ALevel
  {
  public:
    MenuLevel(Core &core);
    
    void		update(Core &c);

  private:
    std::shared_ptr<PlayButton>				playButton;
    std::shared_ptr<engine::RaySkyBox>			skybox;
    std::shared_ptr<engine::RayImage>			test;
  };

}
#endif /* MENU_LEVEL_HPP */
