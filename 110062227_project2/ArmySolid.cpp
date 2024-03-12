#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "ArmySolid.hpp"
#include "AudioHelper.hpp"
//#include "ArmyBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Army.hpp"
//#include "ArcherBullet.hpp"

//Army(std::string img, float x, float y, float radius, float coolDown, float speed, float hp, int id, float shootRadius);
ArmySolid::ArmySolid(int x, int y) : Army("play/turret-2.png", x, y, 20, 1, 0, 25, 2, 1.5 * PlayScene::BlockSize) {
    // Use bounding circle to detect collision is for simplicity, pixel-perfect collision can be implemented quite easily,
    // and efficiently if we use AABB collision detection first, and then pixel-perfect collision.
}

void ArmySolid::CreateBullet(Engine::Point pt) {}
