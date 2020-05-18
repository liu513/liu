#include <iostream>
#include<cmath>
using namespace std;
class Car;
class Boat
{
	public:
	int weight;
	friend int totalWeight(Boat &b, Car &c);
	Boat(int a):weight(a){}
};

class Car
{
	public:
	int weight;
	friend int totalWeight(Boat &b, Car &c);
	Car(int a):weight(a){}
};

int  totalweight(Boat&  b,Car&  c) 
{ 
        return  b.weight+c.weight; 
} 
int  main() 
{ 
        Boat  b(100); 
        Car  c(200); 
        cout<<totalweight(  b,  c)<<endl; 
        return  0; 
} 
