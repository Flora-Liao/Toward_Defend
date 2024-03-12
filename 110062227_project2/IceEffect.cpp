#include <cmath>
#include <string>

#include "IceEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Resources.hpp"
// TODO 3 (2/2): You can imitate the 2 files: '"ExplosionEffect.hpp', '"ExplosionEffect.cpp' to create a Shoot Effect.
PlayScene* IceEffect::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
IceEffect::IceEffect(float x, float y) : Sprite("play/explosion-1.png", x, y), timeTicks(0) {
	for (int i = 1; i <= 5; i++) {
		bmps.push_back(Engine::Resources::GetInstance().GetBitmap("play/explosion-" + std::to_string(i) + ".png"));
	}
}
void IceEffect::Update(float deltaTime) {
	timeTicks += deltaTime;
	if (timeTicks >= timeSpan) {
		getPlayScene()->EffectGroup->RemoveObject(objectIterator);
		return;
	}
	int phase = floor(timeTicks / timeSpan * bmps.size());
	bmp = bmps[phase];
	Sprite::Update(deltaTime);
}