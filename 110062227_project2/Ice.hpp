#ifndef Ice_hpp
#define Ice_hpp

#include "Army.hpp"

class Ice : public Army {
    float icetime = 2;
public:
    Ice(int x, int y);
    void CreateBullet(Engine::Point pt) override;
    void Update(float deltaTime) override;
    virtual void OnExplode(Defense* defense);
    void Hit(float damage) override;
};

#endif /* Ice_hpp */
