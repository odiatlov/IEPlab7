#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

class Rectangle {
  protected:
    int width, height;
  public:
    Rectangle(int,int);
    Rectangle(const Rectangle& rhs){}
    int area() {return width*height;}
    ~Rectangle()
	{
		cout<<"Destructor is called"<<endl;
	}
    Rectangle &operator=(const Rectangle& rhs){}
    Rectangle* CreateRectangle(int x, int y)
    {
	Rectangle* obj = new Rectangle(x, y);
	return obj;
    }
};

class Cube:public Rectangle{
  private:
    int lenght;
	Rectangle *pb;
  public:
    Cube(int,int,int);
    Cube(const Cube& rhs);
    int volume() {return width*height*lenght;}
    ~Cube()
	{
		cout<<"Destructor is called"<<endl;
	}
    Cube &operator=(const Cube& rhs);
    Cube* CreateCube(int x, int y, int z)
    {
	Cube* obj = new Cube(x, y, z);
	return obj;
    }
};
class Triangle {
  protected:
    int base, height;
  public:
  /*  explicit Lock(Mutex *pm): mutexPtr(pm, unlock)
	{
		lock(mutexPtr.get());
	}*/
    Triangle(int, int);
    Triangle(const Triangle& rhs);
    int area() {return base*height/2;}
    ~Triangle()
	{
		cout<<"Destructor is called"<<endl;
	}
    Triangle &operator=(const Triangle& rhs);
  private:
	//std::tr1::shared_ptr<Mutex> mutexPtr;
};
class Pyramid:public Triangle {
  private:
    int lenght;
	Triangle *pb;
  public:
    Pyramid(int, int, int);
    Pyramid(const Pyramid& rhs);
    int volume() {return base*height*lenght/3;}
    ~Pyramid()
	{
		cout<<"Destructor is called"<<endl;
	}
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
Triangle::Triangle(int x, int y):base(x),height(y)
{}
Rectangle* CreateRectangle(int x, int y)
    {
	Rectangle* obj = new Rectangle(x, y);
	return obj;
    }
Cube* CreateCube(int x, int y, int z)
    {
	Cube* obj = new Cube(x, y, z);
	return obj;
    }
Triangle* CreateTriangle(int x, int y)
{
	Triangle* obj = new Triangle(x, y);
	return obj;
}

void manage()
{
	
	std::shared_ptr<Rectangle> plnv1(CreateRectangle(3, 4));
	std::shared_ptr<Rectangle> plnv2(plnv1);
	plnv1=plnv2;

	
}



int main () {
  Rectangle r1=Rectangle(3, 4);
  Rectangle r3=Rectangle(1, 4);
  Cube c1=Cube(5, 4, 5);
  
  cout << "area: " << r1.area()<<endl;
  cout << "volume: " << c1.volume()<<endl;
  Rectangle r2(r1);
  r2=r1;
  cout << "area: " << r3.area()<<endl;
  return 0;
}

