#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
void sort(vector<double> &a)
{
	int cnt = a.size();
	int i , j;
	for(i = 0 ; i < cnt ; i++)
	{
		for(j = 0 ; j < cnt - i -1; j++)
		{
			if(a[j] > a[j+1])
			{
				double temp = a[j];
				a[j]=a[j+1];
				a[j+1]= temp;
			}
		}
	}
}
int main()
{
	vector<double>a;
	ifstream in("a.txt");

	double temp;
	while (in>>temp)
	{
		
	
		
		a.push_back(temp);
		
	}
	in.close();
	sort(a);
	ofstream out("b.txt");

	for(int i = 0;i < a.size();i++)
	{
		out<<a[i]<<" ";
	}
	out.close();
	return 0;
	
	
	
}
