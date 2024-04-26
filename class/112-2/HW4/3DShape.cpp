#include <iostream>
#include <string>
//#include "function.h"
using namespace std;
namespace oj
{
	class Shape3D
	{	
		double volume;

	public:
		double getVolume();
	
	protected:      // 只有子class能拜訪
		void setVolume(double volume);
	};

	class Sphere : public Shape3D       // Shape3D的子class
	{
		double radius;
		double pi;
	
	public:
		Sphere(double, double);
	};

	class Cone : public Shape3D
	{
		double radius;
		double height;
		double pi;

	public:
		Cone(double, double, double);
	};

	class Cuboid : public Shape3D
	{
		double length;
		double width;
		double height;
	
	public:
		Cuboid(double, double, double);
	};

	class Cube : public Cuboid
	{
	public:
		Cube(double);
	};
}
namespace oj
{   
    void Shape3D::setVolume(double v)
    {
        volume = v;
    }

    double Shape3D::getVolume()
    {
        return volume;
    }
}

namespace oj    // my function
{
    Sphere::Sphere(double r, double pi){
        if(r<0||pi<0) r=0;
        setVolume(4.0/3.0*pi*r*r*r);
    }

    Cone::Cone(double r, double h, double pi){
        if(r<0||h<0||pi<0) r=0;
        setVolume(1.0/3.0*r*r*pi*h);
    }

    Cuboid::Cuboid(double x, double y, double z){
        if(x<0||y<0||z<0) x=0;
        setVolume(x*y*z);
    }

    Cube::Cube(double x):Cuboid(x,x,x){          // important
        if(x<0) x=0;
        setVolume(x*x*x);
    }
}
// 在 C++ 中，當派生類別的構造函數被呼叫時，它會自動調用其基類別的預設構造函數。
// 但是如果基類別沒有預設構造函數，或者需要呼叫不同的基類別構造函數，就必須在派生
// 類別的構造函數初始化列表中指定要調用的基類別構造函數。

// 在這段程式碼中，Cube 類別繼承自 Cuboid 類別，而 Cuboid 類別並沒有預設的無參數
// 構造函數，它的構造函數需要三個參數 x、y 和 z。因此，在 Cube 類別的構造函數中，
// 需要使用初始化列表來呼叫 Cuboid 類別的構造函數並提供適當的參數。

// 這就是為什麼在 Cube 類別的構造函數初始化列表中需要指定 Cuboid(x, x, x)，而其他
// 類別則不需要。因為其他類別要麼有預設的無參數構造函數（例如 Sphere、Cone、Cuboid），
// 要麼不需要呼叫不同的基類別構造函數（例如 Shape3D）。


int main(void)
{   
    using namespace oj;

    string s;
    double a, b, c;
    double totalVolume = 0.0, totalPerimeter = 0.0;

    while(cin >> s) {
        if(s == "Sphere") {
            cin >> a >> b;
            Sphere sphere(a, b);
            totalVolume += sphere.getVolume();
            //cout << "Ball: " << sphere.getVolume() << endl;
        }
        if(s == "Cone") {
            cin >> a >> b >> c;
            Cone cone(a, b, c);
            totalVolume += cone.getVolume();
            //cout << "Cone: " << cone.getVolume() << endl;
        }
        if(s == "Cuboid") {
            cin >> a >> b >> c;
            Cuboid cuboid(a, b, c);
            totalVolume += cuboid.getVolume();
            //cout << "Cuboid: " << cuboid.getVolume() << endl;
        }
        if(s == "Cube") {
            cin >> a;
            Cube cube(a);
            totalVolume += cube.getVolume();
            //cout << "Cube: " << cube.getVolume() << endl;
        }
    }

    cout << totalVolume << endl;

    return 0;
}