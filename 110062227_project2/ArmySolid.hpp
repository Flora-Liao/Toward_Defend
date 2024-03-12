#ifndef ArmySolid_hpp
#define ArmySolid_hpp

#include "Army.hpp"

class ArmySolid : public Army {
public:
    ArmySolid(int x, int y);
    void CreateBullet(Engine::Point pt) override;
};

#endif /* ArmySolid_hpp */
