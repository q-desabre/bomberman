
#ifndef _TEXTURE_MANAGER_HPP_
# define _TEXTURE_MANAGER_HPP_

#include <map>
#include <memory>

namespace engine
{
  template <typename T>
  class TextureManager
  {
  public:
    static TextureManager<T> &getInstance()
    {
      if (!instance)
	instance = new TextureManager<T>;
      return *instance;
    }

    void		loadTexture(const std::string& name, T texture)
    {
      textures[name] = texture;
    }
  
    T			getTexture(const std::string& name)
    {
      return textures[name];
    }
  
    TextureManager(TextureManager &other) = delete;
    void operator=(const TextureManager &) = delete;


  protected:
    TextureManager() { }

    static TextureManager<T>	*instance;
    std::map<std::string, T>	textures;
  };

  
}



#endif /* _TEXTURE_MANAGER_HPP_ */
