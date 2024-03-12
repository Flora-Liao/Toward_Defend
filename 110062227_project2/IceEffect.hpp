#ifndef ICEEFFECT_HPP
#define ICEEFFECT_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>

#include "Sprite.hpp"

class PlayScene;

class IceEffect : public Engine::Sprite {
protected:
	PlayScene* getPlayScene();
	float timeTicks;
	std::vector<std::shared_ptr<ALLEGRO_BITMAP>> bmps;
	float timeSpan = 0.5;
public:
	IceEffect(float x, float y);
	void Update(float deltaTime) override;
};
#endif // ICEEFFECT_HPP
