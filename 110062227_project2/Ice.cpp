#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Ice.hpp"
#include "IceEffect.hpp"
#include "AudioHelper.hpp"
//#include "ArmyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
//#include "ArcherBullet.hpp"
#include <random>
#include <string>
#include "IceEffect.hpp"
#include "Collider.hpp"
#include "DirtyEffect.hpp"
#include "Defense.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"

//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id = 3, float shootRadius);
Ice::Ice(int x, int y) : Army("play/ice2.png", x, y, 20, 1, 0, 10000, 3, 1.5 * PlayScene::BlockSize) {
    // Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
    // and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void Ice::CreateBullet(Engine::Point pt) {}

void Ice::OnExplode(Defense* defense) {
    // Delete
    getPlayScene()->EffectGroup->AddNewObject(new IceEffect(defense->Position.x, defense->Position.y));
}
void Ice::Hit(float damage) {
    if (damage == 1) {
        if (speed != 0)speed = 30;
    }
    HP -= damage;
    if (HP <= 0) {
        // Remove all Defense's reference to target.
        for (auto& it : lockedDefenses)
            it->Target = nullptr;
        getPlayScene()->ArmyGroup->RemoveObject(objectIterator);
    }
}
void Ice::Update(float deltaTime) {
    if (isPreview)return;
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    /*
    Engine::Sprite* sprite;
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x - PlayScene::BlockSize, this->Position.y - PlayScene::BlockSize));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x - PlayScene::BlockSize, this->Position.y));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x - PlayScene::BlockSize, this->Position.y + PlayScene::BlockSize));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x, this->Position.y - PlayScene::BlockSize));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x, this->Position.y));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x, this->Position.y + PlayScene::BlockSize));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x + PlayScene::BlockSize, this->Position.y - PlayScene::BlockSize));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x + PlayScene::BlockSize, this->Position.y));
    getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x + PlayScene::BlockSize, this->Position.y + PlayScene::BlockSize));*/
    // Can be improved by Spatial Hash, Quad Tree, ...
    // However simply loop through all enemies is enough for this program.
   // int l_x, r_x;
    //int l_y, r_y;
    //l_x = this->Position.x - PlayScene::BlockSize;
    //r_x = this->Position.x + PlayScene::BlockSize;
    //l_y = this->Position.y - PlayScene::BlockSize;
    //r_y = this->Position.y + PlayScene::BlockSize;
    int x1, x2;
    int y1, y2;
    x1 = this->Position.x;
    y1 = this->Position.y;
    icetime -= deltaTime;
    if (icetime <= 0) {
        Hit(INFINITY);
        return;
    }
    else {
        //Defense* tmp;
        /*
        Engine::Sprite* sprite;
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x - PlayScene::BlockSize, this->Position.y - PlayScene::BlockSize));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x - PlayScene::BlockSize, this->Position.y));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x - PlayScene::BlockSize, this->Position.y + PlayScene::BlockSize));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x, this->Position.y - PlayScene::BlockSize));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x, this->Position.y));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x , this->Position.y + PlayScene::BlockSize));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x + PlayScene::BlockSize, this->Position.y - PlayScene::BlockSize));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x + PlayScene::BlockSize, this->Position.y));
        getPlayScene()->GroundEffectGroup->AddNewObject(sprite = new DirtyEffect("play/snow.png", 1, this->Position.x + PlayScene::BlockSize, this->Position.y + PlayScene::BlockSize));
        */
        for (auto& it : scene->DefenseGroup->GetObjects()) {
            x2 = it->Position.x;
            y2 = it->Position.y;
            Defense* tmp;
            if(abs(x1-x2)<=PlayScene::BlockSize && abs(y1-y2)<=PlayScene::BlockSize){
            //if (l_x <= it->Position.x && it->Position.x <= r_x)
              //  if (l_y <= it->Position.y && it->Position.y <= r_y) {
               tmp = dynamic_cast<Defense*>(it);
               tmp->ice = 1;
                    //Target = dynamic_cast<Defense*>(it);
                    //Target->ice = 1;
                    //Target->lockedArmies.push_back(this);
                    //lockedArmyIterator = std::prev(Target->lockedArmies.end());
             }
        }
    }

    
}
