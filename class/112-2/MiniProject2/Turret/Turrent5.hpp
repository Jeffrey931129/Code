#ifndef Turrent5_HPP
#define Turrent5_HPP
#include "Turret.hpp"

class Turrent5: public Turret {
public:
	static const int Price;
    Turrent5(float x, float y);
    void CreateBullet() override;
};
#endif // Turrent5_HPP
