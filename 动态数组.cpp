#include  <iostream> 
using  namespace  std; 
class  Book 
{
	private:
		unsigned int m_ID;//���
    	string m_Name;//����
    	string m_Introduction;//���
    	string m_Author;//����
    	string m_Date;//����
    	unsigned int m_Page;//ҳ��
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
        b1.SetName("C++  ���Գ������(��4��)"); 
        b1.SetAuthor("֣��"); 
        b1.SetIntroduction("����C++����������֪ʶ"); 
        b1.SetDate("201007"); 
        b1.SetPage(529); 
        b2.SetID(2); 
        b2.SetName("��ɢ��ѧ"); 
        b2.SetAuthor("��Т��"); 
        b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��"); 
        b2.SetDate("198209"); 
        b2.SetPage(305); 
        b3.SetID(3); 
        b3.SetName("c�������"); 
        b3.SetAuthor("̷��ǿ"); 
        b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��"); 
        b3.SetDate("201006"); 
        b3.SetPage(355); 

        cout<<"��һ�������"<<endl; 
        s.in(b1); 
        cout<<"�ڶ��������"<<endl; 
        s.in(b2); 
        cout<<"�����������"<<endl; 
        s.in(b3); 
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl; 
        cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl; 
        Book  tmpbook=s.findbyName("��ɢ��ѧ"); 
        if(tmpbook.GetID()!=0) 
        { 
                s.out("��ɢ��ѧ"); 
                cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl; 
        } 
        else 
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl; 
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl; 

        cout  <<"����ͼ��  ID��3"  <<  endl; 
        tmpbook=s.findbyID(3); 
        if(tmpbook.GetID()!=0) 
                cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl; 
        else 
                cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl; 

        cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl; 
        tmpbook=s.findbyName("��ɢ��ѧ"); 
        if(tmpbook.GetID()!=0) 
                cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl; 
        else 
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl; 

        cout<<"������п��ͼ�����Ϣ"<<endl; 
        s.printList(); 
        cout<<"�������н���"<<endl; 
        return  0; 
} 
