#include<iostream>
using namespace std;
int main()
{
	int a[8][8];
	char str[10];
	int i,j,cnt,sum=0,t,asd;

	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			a[i][j]=0;
		}
	}
	cin>>str;

	for(i=0;i<8;i++)
	{
		if(str[i]!='*')
		{
			cnt=str[i]-'1';
			for(j=0;j<8;j++)
			{
				a[i][j]=1;
				a[j][cnt]=1;
			}
				t=i-1;
				asd=cnt-1;
				while(t>=0&&t<=7&&asd>=0&&asd<=7)
				{
					a[t--][asd--]=1;
				}
				t=i+1;
				asd=cnt+1;
				while(t>=0&&t<=7&&asd>=0&&asd<=7)
				{
					a[t++][asd++]=1;
				}
		}
	}
	
	cnt=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			
			if(a[i][j]==0)
			{
				cnt=j+1;
				sum++;
			}
		}
	
	}
	if(sum==1)
	{
		cout<<cnt<<endl;
	}
	else
	{
		cout<<"NO ANSWER";
	}
	return 0;
}

