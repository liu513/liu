#include  <iostream> 
using  namespace  std; 
const  float  pi=3.14159;
class Shape 
{
	private:
		int m_ID;
	public:
		void SetID(int ID);
		int GetID();
		int getArea();
		Shape(int a);
		~Shape();
};
void Shape::SetID(int ID)
{
	this->m_ID = ID;
}
int Shape::GetID()
{
	return this -> m_ID;
}
Shape::Shape(int a)
{
	this -> m_ID=a;
	cout<<"Shape constructor called:"<<m_ID<<endl;
}
Shape::~Shape()
{
	cout<<"Shape destructor called:"<<m_ID<<endl;
}
int Shape::getArea()
{
	return 0;
}
class Circle:public Shape
{
	private:
		int r;
	public:
		void SetR (int R);
		int GetR();
		float getArea();
		Circle(int i,int j);
		~ Circle(); 
};
void Circle::SetR(int R)
{
	this->r=R;
} 
int Circle::GetR()
{
	return r;
}
float Circle::getArea()
{
	return pi*r*r;
}
Circle::Circle(int i,int j):Shape(j)
{
	this->r = i;
	cout<<"Circle constructor called:2"<<endl;
} 
Circle::~Circle()
{
	cout<<"Circle destructor called:2"<<endl;
}
class Rectangle:public Shape
{
	private:
		int h,w;
	public:
		void SetH(int H);
		int GetH();
		void SetW(int W);
		int GetW();
		int getArea();
		Rectangle(int i,int j,int k);
		~Rectangle();
};
void Rectangle::SetH(int H)
{
	this->h=H;
}
int Rectangle::GetH()
{
	return h;
}
void Rectangle::SetW(int W)
{
	this->w=W;
}
int Rectangle::GetW()
{
	return w;
}
int Rectangle::getArea()
{
	return w*h;
}
Rectangle::Rectangle(int i,int j,int k):Shape(k)
{
	this->h = i;
	this->w = j;
	cout<<"Rectangle constructor called:3"<<endl; 
}
Rectangle::~Rectangle()
{
	cout<<"Rectangle destructor called:3"<<endl;
}



int  main() 
{ 
        Shape  s(1);//1��ʾID 
        Circle  c(4,2);//4��ʾ�뾶��2��ʾID 
        Rectangle  r(4,  5,3);//4��5��ʾ���Ϳ�3��ʾID 
        cout<<"Shape�����"<<s.getArea()<<endl; 
        cout<<"Circle�����"<<c.getArea()<<endl; 
        cout<<"Rectangle�����"<<r.getArea()<<endl; 
}
