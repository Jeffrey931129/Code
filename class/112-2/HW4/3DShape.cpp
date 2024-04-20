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
	
	protected:
		void setVolume(double volume);
	};

	class Sphere : public Shape3D
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
namespace oj
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