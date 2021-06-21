
#ifndef _PLAY_BUTTON_HPP_
# define _PLAY_BUTTON_HPP_

# include "ARayButton.hpp"

namespace bomber
{
  class Core;
  
  class PlayButton : public engine::ARayButton
  {
  public:
    PlayButton(const v2& pos, const std::string& t, const std::string& tH, const std::string& tC);

    void		onClick(Core &core);
  };
}


#endif /* _PLAY_BUTTON_HPP_ */
