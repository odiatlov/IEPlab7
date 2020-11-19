#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

class Car {
  private: //item 22
	int year;
    	string name;
    	string model;
	bool sold;
	
	
  public:
	Car(int ,string ,string , bool);
	string Soldstatus()
	{
		if(sold==true)
			return "was";
		else
			return "was not";
	}
	int Year()
	{
		return year;
	}
	string Name() const //item 20
	{
		return name;
	}
	string Model()
	{
		return model;
	}
	bool Sold() const // item 20
	{
		return sold;
	}
};

Car::Car(int year,string name,string model, bool sold):year(year),name(name),model(model),sold(sold)
{}

//item 18
struct Day 
{                           
    explicit Day(int day): d(day) {}     
    int d;
}; 
  
struct Year 
{                         
    explicit Year(int year): y(year) {}  
    int y; 
};
  
class Month 
{
  public:
    static const Month Jan;              
    static const Month Feb;              
    static const Month Mar;
    static const Month Apr;
    static const Month May;
    static const Month Jun;
    static const Month Jul;
    static const Month Aug;
    static const Month Sep;
    static const Month Oct;
    static const Month Nov;    
    static const Month Dec;
    
    int number() const { return m; }     
  
  private:
    explicit Month(int month): m(month) {}                      
    int m;                               
};
  
const Month Month::Jan(1);             
const Month Month::Feb(2);             
const Month Month::Mar(3);
const Month Month::Apr(4);
const Month Month::May(5);
const Month Month::Jun(6);
const Month Month::Jul(7);
const Month Month::Aug(8);
const Month Month::Sep(9);
const Month Month::Oct(10);
const Month Month::Nov(11);
const Month Month::Dec(12);            
  
class Date 
{                                      
  public:                                           
    explicit Date(Month m, Day d, Year y);       
    explicit Date(Year y, Month m, Day d);      
    explicit Date(Day d, Month m, Year y)        
    : dNum(d.d), mNum(m.number()), yNum(y.y) 
    { 
     cout << "Date.Month.Year = " << dNum << '.' << mNum << '.' << yNum << '\n';
    }
  
  private:
    int dNum, mNum, yNum;
};

void checksold(const Car &c)//item 20
{
	if(c.Sold()==true)
		cout<<"The car "<<c.Name()<<" was sold!";
	else
		cout<<"The car "<<c.Name()<<" was not sold!";
}

int main () 
{
	Car c1= Car(2005, "BMW", "M3", true);
	Date today= Date(Day(10), Month::Jan, Year(2005));	//item 18
	cout << "Car " << c1.Name()<<" made in "<<c1.Year()<<", model "<<c1.Model()<<" "<<c1.Soldstatus()<<" sold"<<endl;//item 22
	checksold(c1);//item 20

}


