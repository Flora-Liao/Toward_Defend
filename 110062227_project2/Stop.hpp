#ifndef Stop_hpp
#define Stop_hpp

#include "Defense.hpp"

class Stop : public Defense {
public:
    Stop(float x, float y);
    void CreateBullet(Engine::Point pt) override;
    //void Update(float deltaTime) override;
};

#endif /* Stop_hpp */
