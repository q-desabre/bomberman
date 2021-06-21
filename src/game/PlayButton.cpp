
#include "PlayButton.hpp"
#include "Core.hpp"

namespace bomber
{
  PlayButton::PlayButton(const v2& pos, const std::string& t, const std::string& tH,
			 const std::string& tC) : engine::ARayButton(pos, t, tH, tC)
  {

  }

  void		PlayButton::onClick(Core &core)
  {
    core.startGame(2);
  }

}
