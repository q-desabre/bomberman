
#ifndef _WINDOW_HPP_
# define _WINDOW_HPP_

# include "IWindow.hpp"
# include "raylib.h"

namespace engine
{  
  class RayWindow : public IWindow
  {
  public:
    RayWindow(const int screenWidth, const int screenHeight, const std::string& name)
    {
      initWindow(screenWidth, screenHeight, name);
    }
    
    ~RayWindow()
    {
      close();
    }

    void		initWindow(const int screenWidth, const int screenHeight,
			     const std::string & name)
    {
      InitWindow(screenWidth, screenHeight, name.c_str());
    }
    
    bool		isOpen() const
    {
      return !WindowShouldClose();
    }

    void		close()
    {
      CloseWindow();
    }

    void		clear()
    {
      ClearBackground(BLUE);
    }
  };

}
  
#endif /* _WINDOW_HPP_ */

