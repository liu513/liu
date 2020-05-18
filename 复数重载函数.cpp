
#include  <iostream> 
#include  <iomanip> 
using  namespace  std; 

struct  complex 
{ 
        double  r; 
        double  i; 
};
complex   add(complex c1,complex c2)
{
	complex c;
	c.r=c1.r+c2.r;
	c.i=c1.i+c2.i;
	return c;
}
complex   add(complex c1,double c3)
{
	complex c;
	c.r=c1.r+c3;
	c.i=c1.i;
	return c;
}
complex   add(double c3,complex c2)
{
	complex c;
	c.r=c3+c2.r;
	c.i=c2.i;
	return c;
}



 

int  main() 
{ 
        double  num; 
        complex  a,  b,  c; 
        cin  >>  a.r  >>  a.i; 
        cin  >>  b.r  >>  b.i; 
        cin  >>  num; 
        c  =  add(a,  b); 
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl; 
        c  =  add(a,  num); 
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl; 
        c  =  add(num,  b); 
        cout  <<  c.r  <<  "+"  <<  c.i  <<  "i"  <<  endl; 
} 
