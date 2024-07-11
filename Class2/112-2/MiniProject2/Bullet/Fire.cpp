#include <cmath>
#include <random>
#include <string>
#include <utility>

#include "UI/Animation/DirtyEffect.hpp"
#include "Enemy/Enemy.hpp"
#include "Engine/Group.hpp"
#include "Engine/IObject.hpp"
#include "Fire.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
// 來不及轉就射出去---------------------共有問題
// 調整攻擊距離--解決
class Turret;

Fire::Fire(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Bullet("play/fire.png", 400, 0.1, position, forwardDirection, rotation + ALLEGRO_PI / 2, parent) {
}
void Fire::OnExplode(Enemy* enemy) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(4, 10);
	getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-3.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
