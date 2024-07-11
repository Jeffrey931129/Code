#ifndef Turrent4_HPP
#define Turrent4_HPP
#include "Turret.hpp"

class Turrent4: public Turret {
public:
	static const int Price;
    Turrent4(float x, float y);
    void CreateBullet() override;
};
#endif // Turrent4_HPP
