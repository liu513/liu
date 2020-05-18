#include <iostream>
using namespace std;

int main()
{
	int a[9],b[9],c[3][3];
	int i,j;
	for(i=0;i<9;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<9;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		c[i][j]=a[i*3]*b[j]+a[1+i*3]*b[j+3]+a[2+i*3]*b[j+6];
	}
	int s=0;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		cout<<c[i][j]<<" ";
		s++;
		if(s%3==0)
		cout<<endl;
	}
	cout<<endl;
	
	
}
