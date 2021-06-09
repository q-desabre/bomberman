
#ifndef _IWINDOW_HPP_
# define _WINDOW_HPP_

namespace bomber
{
  class IWindow
  {
  public:
    virtual void	initWindow(const int, const int, const std::string&) = 0;
    virtual bool	isOpen() const = 0;
    virtual void	close() = 0;
    virtual void	clear() = 0;
  };
};

#endif /* _IWINDOW_HPP_ */
