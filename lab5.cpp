#include <iostream>
using namespace std;

class Rectangle {
  protected:
    int width, height;
  public:
    Rectangle(int,int);
    Rectangle(const Rectangle& rhs);
    int area() {return width*height;}
    virtual ~Rectangle();
    Rectangle &operator=(const Rectangle& rhs);
};
class Cube:public Rectangle{
  private:
    int lenght;
	Rectangle *pb;
  public:
    Cube(int,int,int);
    Cube(const Cube& rhs);
    int volume() {return width*height*lenght;}
    virtual ~Cube();
    Cube &operator=(const Cube& rhs);
};
class Triangle {
  protected:
    int base, height;
  public:
    Triangle(int, int);
    Triangle(const Triangle& rhs);
    int area() {return base*height/2;}
    virtual ~Triangle();
    Triangle &operator=(const Triangle& rhs);
    
};
class Pyramid:public Triangle {
  private:
    int lenght;
	Triangle *pb;
  public:
    Pyramid(int, int, int);
    Pyramid(const Pyramid& rhs);
    int volume() {return base*height*lenght/3;}
    virtual ~Pyramid();
    Pyramid &operator=(const Pyramid& rhs); 
};
/*
void Rectangle::set_values (int x, int y) {
  width = x; //assignments, not initializations
  height = y;
}
*/
Rectangle::Rectangle(int x, int y):width(x),height(y)
{}
Cube::Cube(int x, int y, int z):Rectangle(x, y),lenght(z)
{}
Rectangle::~Rectangle()
{}
Rectangle* getRectangle();
Pyramid& Pyramid::operator=(const Pyramid& rhs)
{
	Triangle *pOrig=pb;
	pb = new Triangle(*rhs.pb);
	delete pOrig;
	return *this;
}
Cube::Cube(const Cube& rhs):Rectangle(rhs),lenght(rhs.lenght)
{
	//"Cube copy constructor"
}
Cube& Cube::operator=(const Cube& rhs)
{
	//"Cube copy assignment constructor"
	Cube::operator=(rhs);
	lenght=rhs.lenght;
	return *this;
}
int main () {
  Rectangle r1=Rectangle(3, 4);
  Rectangle r3=Rectangle(1, 4);
  cout << "area: " << r1.area();
  Rectangle r2(r1);
  r2=r1;
  cout << "area: " << r3.area();
  return 0;
  Rectangle *ptk = getRectangle();
  delete ptk;
}

