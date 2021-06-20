
#ifndef _FLAME_HPP_
# define _FLAME_HPP_

# include <cmath>
# include "RayCollisionBox.hpp"
# include "AActor.hpp"
# include "ICollidable.hpp"
# include "Timer.hpp"
# include "TextureManager.hpp"

namespace bomber
{
  class Flame : public engine::AActor, public engine::ICollidable
  {
  public:
    Flame(const v3& pos);
    const engine::ACollider&		getCollider() const;
    bool				collide(const engine::ACollider& other) const;
    void				draw();
    int					getUid() const;
    
  private:
    std::unique_ptr<engine::ACollider>	collisionBox;
    engine::Timer			timer;
    float				randScale;
    float				randTime;
    Model				model;
    int					currentTexture;
    Texture2D				texture;
    // Texture2D				texture[5];
    engine::Timer			timerAnimation;
  };
}

#endif /* _FLAME_HPP_ */
