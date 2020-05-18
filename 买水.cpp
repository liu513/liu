#include <iostream>
using namespace std;
int num(int a,int b,int c)//a是饮料数  b是瓶数  c是瓶盖数 
{
	if(b<2&&c<3)  return a;
	
	int cnt=b/2+c/3;
	a+=cnt;
	b=b%2+cnt;
	c=c%3+cnt;
	return num(a,b,c);
}
int main()
{
	int x,y,z;
	int money;
	cin>>money;
	x=money;y=money;z=money;
	cout<<num(x,y,z);
	return 0;
}
