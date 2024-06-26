#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>

#include "Engine/AudioHelper.hpp"
#include "Engine/Group.hpp"
#include "Bullet/Fire.hpp"
#include "Turrent4.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

const int Turrent4::Price = 400;
Turrent4::Turrent4(float x, float y) :
	Turret("play/tower-base.png", "play/turret-6.png", x, y, 200, Price, 0.01) {
}
void Turrent4::CreateBullet() {
	Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
	float rotation = atan2(diff.y, diff.x);
	Engine::Point normalized = diff.Normalize();
	getPlayScene()->BulletGroup->AddNewObject(new Fire(Position + normalized * 10, diff, rotation, this));
	static int rec_time=0;
	if(rec_time==90) {AudioHelper::PlayAudio("fire.wav"); rec_time=0;}
	rec_time++;
}
