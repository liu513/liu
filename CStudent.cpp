#include  <iostream> 
#include  <string> 
using  namespace  std; 
class CStudent
{
	private:
		string name;
		int age;
		static int count;
	public:
		CStudent()
		{
			
			cout<<"noname is contructing"<<endl;
			name = "noname";
			age = 0;
			count ++;
		}
		CStudent(const std::string &n,int a)
		{
			name = n;
			age = a;
			cout<<name<<" is contructing"<<endl;
			count ++;
		}
		~CStudent()
		{
			cout<<name<<" is destructing"<<endl;
			count --; 
		}
		void printname()
		{
			cout<<"name:"<<name<<endl;
		}
		static int getcount()
		{
			return count;
		}
} ;
int CStudent::count=0;






int  main() 
{ 
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        { 
                CStudent  stuB[5]; 
                stuB[4].printname(); 
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        } 
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        { 
                CStudent  stuA[2]  =  {CStudent("Tom",  3),  CStudent("Jerry",  2)}; 
                for  (int  i  =  0;  i  <  2;  i++) 
                { 
                        stuA[i].printname(); 
                } 
                cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 
        } 
        cout  <<  "现在有学生"  <<  CStudent::getcount()  <<  endl; 

        return  0; 
}
