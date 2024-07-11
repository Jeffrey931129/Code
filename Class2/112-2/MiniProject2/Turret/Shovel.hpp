#ifndef Shovel_HPP
#define Shovel_HPP
#include "Turret.hpp"

class Shovel: public Turret {
public:
	static const int Price;
    Shovel(float x, float y);
    void CreateBullet() override;
};
#endif // Shovel_HPP
