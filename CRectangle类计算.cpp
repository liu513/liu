#include  <iostream> 
using  namespace  std;
class CPoint
{
	public:
		int x,y;
    	CPoint(int X =0 ,int Y =0 )
    	{
    		x=X;
    		y=Y;
    		cout<<"CPoint contstructor with default value(0,0) is called." << endl;
		}
		 
	
		
} ;
class CRectangle
{
	private:
    	int c1, c2;
    
	public:
 		CRectangle()
    		{
        		cout << "CPoint contstructor with default value(0,0) is called." << endl;
				cout << "CPoint contstructor with default value(0,0) is called." << endl;
       			c1 = 0;
       			c2 = 0;
       	 		cout << "CRectangle default contstructor is called." << endl;
    		}
    	CRectangle(const CPoint &a,const CPoint &b)
    		{
        		cout << "CPoint copy contstructor is called." << endl;
				cout << "CPoint copy contstructor is called." << endl;
				cout << "CPoint copy contstructor is called." << endl; 
				cout << "CPoint copy contstructor is called." << endl;
        		c1 = b.x - a.x;
        		c2 = b.y - a.y;
        		cout << "CRectangle contstructor with (CPoint,CPoint) is called." << endl;
    		}
    	CRectangle(int a, int b, int c, int d)
    		{
        		cout << "CPoint contstructor with default value(0,0) is called." << endl; 
				cout << "CPoint contstructor with default value(0,0) is called." << endl;
        		c1 = c - a;
        		c2 = d - b;
        		cout << "CRectangle contstructor with (int,int,int,int) is called." << endl;
    		}
    	CRectangle(CRectangle& a)
    		{
        		cout << "CPoint copy contstructor is called." << endl; 
				cout << "CPoint copy contstructor is called." << endl;
        		c1 = a.c1;
        		c2 = a.c2;
        		cout << "CRectangle copy contstructor is called." << endl;
    		}
    	int GetArea()
    	{
        	return c1*c2;
    	}
};




int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl; 
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl; 
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl; 
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl; 
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl; 
        system("pause"); 
        return  0; 
}
