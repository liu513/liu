#include  <iostream> 
#include<iomanip> 
#include  <cmath> 
using  namespace  std; 

const  double  PI=3.1415926; 
class cylinder
{
	private:
		double r,h;
	public:
		cylinder(double h1,double r1)
		{
			r=r1;
			h=h1; 
			cout<<"构造函数被调用"<<endl; 
		}
		double getvolumn()
		{
			
			return PI*r*r*h;
		}
		double getarea()
		{
			
			return 2*PI*r*r+2*r*h*PI;
		}
		~cylinder()
		{
			cout<<"析构函数被调用"<<endl; 
		}
	
}; 

int  main() 
{ 
        double  d,h; 
        cin>>d>>h; 
        
        
        
        cylinder can(h,d/2); 
        cout<<fixed<<setprecision(6); 
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl; 
        cout<<"铁皮的面积是"<<can.getarea()<<endl; 
}