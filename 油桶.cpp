
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
		double init(double h1,double r1)
		{
			r=r1;
			h=h1; 
			
		}
		double getvolumn()
		{
			
			return PI*r*r*h;
		}
		double getarea()
		{
			
			return 2*PI*r*r+2*r*h*PI;
		}
	
	
}; 

int  main() 
{ 
        double  d,h; 
        cin>>d>>h; 
        cylinder can;
        
        
        can.init(h,d/2); 
        cout<<fixed<<setprecision(6); 
        cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<"  "<<endl; 
        cout<<"��Ƥ�������"<<can.getarea()<<endl; 
} 
