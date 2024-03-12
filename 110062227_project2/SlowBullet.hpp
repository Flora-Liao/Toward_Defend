#ifndef SlowBullet_hpp
#define SlowBullet_hpp

#include "Bullet.hpp"

class Army;
class Defense;
namespace Engine {
    struct Point;
}  // namespace Engine

class SlowBullet : public Bullet {
public:
    explicit SlowBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Defense* parent);
};

#endif /* SlowBullet_hpp */
