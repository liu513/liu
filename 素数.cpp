#include  <iostream> 
 
using  namespace  std; 
int isPrime(unsigned short int x)
{
    int i;
    for(i=0;i<=sqrt(x);i++)
    {
        if (x%i==0)  return 0;
 }
 } 
int  main() 
{ 
        unsigned  short  a; 
        cin>>a; 
        if  (isPrime(a)) 
                cout<<"Y"<<endl; 
        else 
                cout<<"N"<<endl; 
}
