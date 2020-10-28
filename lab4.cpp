#include <iostream>
using namespace std;
class Uncopyable
{
	protected:
	Uncopyable(){}
	~Uncopyable(){}
	private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};
class Rectangle:private Uncopyable {
  private:
    int width, height;
  public:
    Rectangle(int,int);
    Rectangle(const Rectangle& rhs){}
    int area() {return width*height;}
    ~Rectangle();
    Rectangle &operator=(const Rectangle& rhs){}
};
/*
void Rectangle::set_values (int x, int y) {
  width = x; //assignments, not initializations
  height = y;
}
*/
Rectangle::Rectangle(int x, int y):width(x),height(y)
{}
Rectangle::~Rectangle()
{}


int main () {
  Rectangle r1=Rectangle(3, 4);
  Rectangle r3=Rectangle(1, 4);
  cout << "area: " << r1.area();
  Rectangle r2(r1);
  r2=r1;
  cout << "area: " << r3.area();
  return 0;
}

