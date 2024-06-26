#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/AudioHelper.hpp"
#include "Engine/Group.hpp"
#include "Bullet/Fire.hpp"
#include "Shovel.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

const int Shovel::Price = 0;
Shovel::Shovel(float x, float y) :
	Turret("play/shovel.png", "play/shovel.png", x, y, 200, Price, 0.1) {
}
void Shovel::CreateBullet() {
	return;
}