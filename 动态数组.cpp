#include  <iostream> 
using  namespace  std; 
class  Book 
{
	private:
		unsigned int m_ID;//编号
    	string m_Name;//书名
    	string m_Introduction;//简介
    	string m_Author;//作者
    	string m_Date;//日期
    	unsigned int m_Page;//页数
    public:
    	void SetID(int a) ;
    	void SetName(string b) ;
    	void SetAuthor(string c);
    	void SetIntroduction(string d);
    	void SetDate(string e);
    	void SetPage(int f);
    	int GetID() ;
    	string GetName() ;
    	string GetAuthor();
    	string GetIntroduction();
    	string GetDate();
    	int GetPage();
    	Book()
    	{
    		m_ID=0;
		}
		virtual ~Book()
		{
			
		}
		Book(const Book& other);
};
void Book::SetID(int a)
{
	this->m_ID=a;
}
int Book::GetID()
{
	return this->m_ID;
}
void Book::SetName(string b)
{
	this->m_Name=b;
}
string Book::GetName()
{
	return this->m_Name;
}
void Book::SetAuthor(string c)
{
	this->m_Author=c;
}
string Book::GetAuthor()
{
	return this->m_Author;
}
void Book::SetIntroduction(string d)
{
	this->m_Introduction=d;
}
string Book::GetIntroduction()
{
	return this->m_Introduction;
}
void Book::SetDate(string e)
{
	this->m_Date=e;
}
string Book::GetDate()
{
	return this->m_Date;
}
void Book::SetPage(int f)
{
	this->m_Page=f;
}
int Book::GetPage()
{
	return this->m_Page;
}
Book::Book(const Book& other)
{
	m_ID = other.m_ID;
	m_Name = other.m_Name;
	m_Author = other.m_Author;
	m_Introduction =  other.m_Introduction;
	m_Date = other.m_Date;
	m_Page = other.m_Page;	
}

class  Store 
{
	private:
		Book *m_pBook;
		unsigned int m_Count;
	public:
		
		int GetCount();
		Store();
		Store(int n);
		virtual ~Store();
		Store(const Store& other);
		void in(Book &b);
		void out(string name);
		Book findbyID(int ID);
		Book findbyName(string name);
		void printList();
};

Store::GetCount()
{
	return m_Count;
}
Store::Store()
{
	m_Count = 0;
	m_pBook = 0;
	m_pBook = new Book[10];
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
	m_Count = n;
	m_pBook = new Book[n];
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::~Store()
{
	m_Count = 0;
	if(m_pBook!=0)
	{
	 	delete []m_pBook;
		cout<<"Store destructor called!"<<endl;
	}
}
Store::Store(const Store& other)
{
	m_Count = other.m_Count;
	m_pBook = new Book[m_Count];
	int i;
	for(i=0;i<m_Count;i++)
	{
		m_pBook[i] = other.m_pBook[i];
	}
}
void Store::in(Book& b) 
{
    m_Count++;
    m_pBook[m_Count - 1].SetID(b.GetID());
    m_pBook[m_Count - 1].SetName(b.GetName());
    m_pBook[m_Count - 1].SetAuthor(b.GetAuthor());
    m_pBook[m_Count - 1].SetIntroduction(b.GetIntroduction());
    m_pBook[m_Count - 1].SetDate(b.GetDate());
    m_pBook[m_Count - 1].SetPage(b.GetPage());
}
void Store::out(string name)
{
    for (unsigned int i = 0; i < this->m_Count; i++)
    {
        if (name == m_pBook[i].GetName())
        {
            for (; i < this->m_Count; i++)
            {
                if (i < this->m_Count - 1)   m_pBook[i] = m_pBook[i + 1];
            }
            this->m_Count--;
            return;
        }
    }
}
Book Store::findbyName(string name)
{
    for (unsigned int i = 0; i < this->m_Count; i++)
    {
        if (name == m_pBook[i].GetName())   return m_pBook[i];
    }
    Book a;
    a.SetID(0);
    return a;
}
Book Store::findbyID(int ID)
{
    for (unsigned int i = 0; i < this->m_Count; i++)
    {
        if (ID == m_pBook[i].GetID())    return m_pBook[i];
    }
    Book a;
    a.SetID(0);
    return a;
}
void Store::printList()
{
    cout << "There are totally " << this->m_Count << " Books:" << endl;
    for (unsigned int i = 0; i < this->m_Count; i++)
    {
        cout << "ID=" << m_pBook[i].GetID() << ";  " << "Name:" << m_pBook[i].GetName() << ";  " \
            << "Author:" << m_pBook[i].GetAuthor() <<";  "<< "Date:" << m_pBook[i].GetDate() <<';'<< endl;
    }
}


 
int  main() 
{ 
        Store  s; 
        Book  b1,b2,b3; 
        b1.SetID(1); 
        b1.SetName("C++  语言程序设计(第4版)"); 
        b1.SetAuthor("郑莉"); 
        b1.SetIntroduction("介绍C++及面向对象的知识"); 
        b1.SetDate("201007"); 
        b1.SetPage(529); 
        b2.SetID(2); 
        b2.SetName("离散数学"); 
        b2.SetAuthor("左孝凌"); 
        b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论"); 
        b2.SetDate("198209"); 
        b2.SetPage(305); 
        b3.SetID(3); 
        b3.SetName("c程序设计"); 
        b3.SetAuthor("谭浩强"); 
        b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等"); 
        b3.SetDate("201006"); 
        b3.SetPage(355); 

        cout<<"第一本书入库"<<endl; 
        s.in(b1); 
        cout<<"第二本书入库"<<endl; 
        s.in(b2); 
        cout<<"第三本书入库"<<endl; 
        s.in(b3); 
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl; 
        cout  <<"查找并出库图书：离散数学"  <<  endl; 
        Book  tmpbook=s.findbyName("离散数学"); 
        if(tmpbook.GetID()!=0) 
        { 
                s.out("离散数学"); 
                cout  <<"离散数学  已成功出库"  <<  endl; 
        } 
        else 
                cout<<"没有找到name为离散数学的书"<<endl; 
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl; 

        cout  <<"查找图书  ID：3"  <<  endl; 
        tmpbook=s.findbyID(3); 
        if(tmpbook.GetID()!=0) 
                cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl; 
        else 
                cout<<"没有找到ID为"<<3<<"的书"<<endl; 

        cout  <<"查找图书  name：离散数学"  <<  endl; 
        tmpbook=s.findbyName("离散数学"); 
        if(tmpbook.GetID()!=0) 
                cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl; 
        else 
                cout<<"没有找到name为离散数学的书"<<endl; 

        cout<<"输出所有库存图书的信息"<<endl; 
        s.printList(); 
        cout<<"程序运行结束"<<endl; 
        return  0; 
} 
