#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Stop.hpp"
#include "AudioHelper.hpp"
#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Stop.hpp"
#include "AudioHelper.hpp"
#include "SlowBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"

//Defense(std::string imgDefense, float x, float y, float radius, float coolDown, int hp, int id, float shootRadius);
Stop::Stop(float x, float y) :
    Defense("play/enemy-2.png", x, y, 20, 1, 50, 4, 1.5 * PlayScene::BlockSize) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
}

void Stop::CreateBullet(Engine::Point pt) {
    int dx = pt.x - Position.x;
    int dy = pt.y - Position.y;
    double len = sqrt(pow(dx, 2) + pow(dy, 2));
    Engine::Point diff = Engine::Point(dx / len, dy / len);
    Engine::Point rotateDiff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(rotateDiff.y, rotateDiff.x) + ALLEGRO_PI / 2;
    PlayScene* scene = getPlayScene();
    if (!Enabled)
        return;
    int ey;
    for (auto& it : scene->ArmyGroup->GetObjects()) {
        ey = static_cast<int>(floor(it->Position.y / PlayScene::BlockSize));
        if (InShootingRange(it->Position)) {
            getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(Position, diff, rotation, this));
            AudioHelper::PlayAudio("gun.wav");
            break;
        }
    }
    
}
/*
void Stop::Update(float deltaTime) {
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

}*/


