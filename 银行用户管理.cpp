
#include  <iostream> 
#include  <iomanip> 
using  namespace  std; 
class Account
{
	private:
		int age;
		string id,name,gender;
		double money2=0;//money2是余额 
	public:
		void init(string a,string b,string c,int m,double n)
		{
			id=a;name=b;gender=c;age=m;
			char buffer[100];
			sprintf(buffer,"%.3lf",n);
			int i;
			int t=0,flag=1;//t是小数点位数 
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
				cout<<"您输入的金额不合法"<<endl; 
			}
			else
			
			
			  money2=n;
			
			return;
			 
		}
	
		void deposit(double money1)//money1是存入的钱 
		{
			char buffer[100];
			sprintf(buffer,"%.3lf",money1);
			int i;
			int t=0,flag=1;//t是小数点位数 
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
				cout<<"您输入的金额不合法"<<endl; 
			}
			else
			  money2=money1+money2;
			  
			
		}
		void printmoney()
		{
			cout<<fixed<<setprecision(2);
			cout<<name<<"的存款为"<<money2<<endl;
			return;
			 
		}
		void withdraw(double money1) //这里的money1是取走的钱 
		{
			char buffer[100];
			sprintf(buffer,"%.3lf",money1);
			int i;
			int t=0,flag=1;//t是小数点位数 
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
				cout<<"您输入的金额不合法"<<endl; 
			}
			else if(money2<money1)
			{
				cout<<"您的存款金额不足"<<endl; 
			} 
			else
			
				money2=money2-money1;
			
		}
}; 

int  main() 
{ 
        Account  tom; 
        tom.init("32020320011001876X",  "Tom  Black",  "男",  19,  2000.89); 
        tom.printmoney();//输出：Tom  Black的存款为2000.89 
        tom.deposit(89.471);//输出：您输入的金额不合法 
        tom.printmoney();//输出：Tom  Black的存款为2000.89 
        tom.deposit(10000); 
        tom.printmoney();//输出：Tom  Black的存款为12000.89 
        tom.withdraw(10001); 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        tom.withdraw(10000.123);//输出：您输入的金额不合法 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        tom.withdraw(10000.9);//输出：您的存款金额不足 
        tom.printmoney();//输出：Tom  Black的存款为1999.89 
        Account  jerry; 
        jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法 
        jerry.printmoney();//输出：Jerry  Black的存款为0.00 
}
