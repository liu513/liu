#include <iostream>
using namespace std;
class Point
{
	private :
		int m_x,m_y;
	public :
		Point& operator ++();
		Point operator ++(int);
		Point(int a,int b)
		{
			m_x = a;
			m_y = b;
		}
		friend ostream& operator <<(ostream& ,const Point&);
} ;

Point& Point::operator ++()
{
	m_x++;
	m_y++;
	return *this;
}

Point Point::operator ++(int)
{
	Point temp=*this;
	++*this;
	return temp;
}
ostream& operator << (ostream& output,const Point& a)
{
  	output<<"("<<a.m_x<<","<<a.m_y<<")"<<endl;
  	return output;
}
int  main() 
{ 
        Point  a(1,3); 
        cout<<a; 
        cout<<a++; 
        cout<<++a; 
        return  0; 
}

