#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	a=1.00*a;
	
	double x,y;
	x=1.00*(a-c);
	y=1.00*(b-d);
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<x<<" "<<y; 

	return 0;
 } 
