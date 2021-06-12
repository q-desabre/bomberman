
#ifndef _TIMER_HPP_
# define _TIMER_HPP_

# include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock> vt;


namespace engine
{
  class Timer
  {
  public:
    Timer()
    {
      start = std::chrono::system_clock::now();
    }

    float		getElaspedTime() const
    {
      vt end = std::chrono::system_clock::now(); 
      std::chrono::duration<double> diff = end - start;
      return (diff.count());
    }


    void		restart()
    {
      start = std::chrono::system_clock::now();
    }
    
  private:
    vt start;
  };
  
  
}

#endif /* _TIMER_HPP_ */
