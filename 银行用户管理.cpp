
#include  <iostream> 
#include  <iomanip> 
using  namespace  std; 
class Account
{
	private:
		int age;
		string id,name,gender;
		double money2=0;//money2����� 
	public:
		void init(string a,string b,string c,int m,double n)
		{
			id=a;name=b;gender=c;age=m;
			char buffer[100];
			sprintf(buffer,"%.3lf",n);
			int i;
			int t=0,flag=1;//t��С����λ�� 
			for(i=0;buffer[i]!=0;i++)
			{
				if (flag==1)
				if(buffer[i]=='.')
				{
					flag=0;
					continue;
				}
				if(flag==0)
				{
					if(t<2)  t++;
					else 
					
					if(buffer[i]!='0')  t++;
					
				}
			}
			if(t>2)
			{
				cout<<"������Ľ��Ϸ�"<<endl; 
			}
			else
			
			
			  money2=n;
			
			return;
			 
		}
	
		void deposit(double money1)//money1�Ǵ����Ǯ 
		{
			char buffer[100];
			sprintf(buffer,"%.3lf",money1);
			int i;
			int t=0,flag=1;//t��С����λ�� 
			for(i=0;buffer[i]!=0;i++)
			{
				if (flag==1)
				if(buffer[i]=='.')
				{
					flag=0;
					continue;
				}
				if(flag==0)
				{
					if(t<2)  t++;
					else if(buffer[i]!='0')  t++;
					
				}
			}
			if(t>2)
			{
				cout<<"������Ľ��Ϸ�"<<endl; 
			}
			else
			  money2=money1+money2;
			  
			
		}
		void printmoney()
		{
			cout<<fixed<<setprecision(2);
			cout<<name<<"�Ĵ��Ϊ"<<money2<<endl;
			return;
			 
		}
		void withdraw(double money1) //�����money1��ȡ�ߵ�Ǯ 
		{
			char buffer[100];
			sprintf(buffer,"%.3lf",money1);
			int i;
			int t=0,flag=1;//t��С����λ�� 
			for(i=0;buffer[i]!=0;i++)
			{
				if (flag==1)
				if(buffer[i]=='.')
				{
					flag=0;
					continue;
				}
				if(flag==0)
				{
					if(t<2)  t++;
					else if(buffer[i]!='0')  t++;
					
				}
			}
			if(t>2)
			{
				cout<<"������Ľ��Ϸ�"<<endl; 
			}
			else if(money2<money1)
			{
				cout<<"���Ĵ�����"<<endl; 
			} 
			else
			
				money2=money2-money1;
			
		}
}; 

int  main() 
{ 
        Account  tom; 
        tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom.deposit(89.471);//�����������Ľ��Ϸ� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom.deposit(10000); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89 
        tom.withdraw(10001); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom.withdraw(10000.123);//�����������Ľ��Ϸ� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom.withdraw(10000.9);//��������Ĵ����� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        Account  jerry; 
        jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ� 
        jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00 
}
