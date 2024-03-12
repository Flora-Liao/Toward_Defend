#ifndef Trap_hpp
#define Trap_hpp

#include "Defense.hpp"

class Trap : public Defense {
public:
    Trap(float x, float y);
    void CreateBullet(Engine::Point pt) override;
    void Update(float deltaTime) override;
};

#endif /* Trap_hpp */
