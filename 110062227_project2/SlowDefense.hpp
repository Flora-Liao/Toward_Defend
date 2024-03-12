#ifndef SlowDefense_hpp
#define SlowDefense_hpp

#include "Defense.hpp"

class SlowDefense : public Defense {
public:
    SlowDefense(float x, float y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* SlowDefense_hpp */
