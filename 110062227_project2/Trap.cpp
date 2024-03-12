#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Trap.hpp"
#include "AudioHelper.hpp"
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Trap.hpp"
#include "AudioHelper.hpp"
#include "CannonBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"

//Defense(std::string imgDefense, float x, float y, float radius, float coolDown, int hp, int id, float shootRadius);
Trap::Trap(float x, float y) :
    Defense("play/trap.png", x, y, 20, 1, 50, 4, 1.5 * PlayScene::BlockSize) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}

void Trap::CreateBullet(Engine::Point pt) {}

void Trap::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    if (!Enabled)
        return;

    
        // Lock first seen target.
        // Can be improved by Spatial Hash, Quad Tree, ...
        // However simply loop through all enemies is enough for this program.
        int ey;
        for (auto& it : scene->ArmyGroup->GetObjects()) {
            ey = static_cast<int>(floor(it->Position.y / PlayScene::BlockSize));
            if (InShootingRange(it->Position)) {
                Target = dynamic_cast<Army*>(it);
                Target->lockedDefenses.push_back(this);
                lockedDefenseIterator = std::prev(Target->lockedDefenses.end());
                Target->Hit(INFINITY);
                Hit(INFINITY);
                break;
            }
        }
    
}


