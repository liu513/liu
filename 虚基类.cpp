#include  "iostream" 
using  namespace  std;
class vehicle
{
	private:
		int maxspeed,weight;
	public:
		void run();
		void stop();
		vehicle();
		~vehicle();
};
void vehicle::run()
{
	cout<<"vehicle run"<<endl;
}
void vehicle::stop()
{
	cout<<"vehicle stop"<<endl;
}
vehicle::vehicle()
{
	cout<<"vehicle constructor called. maxspeed:3; weight4"<<endl;
} 
vehicle::~vehicle()
{
	cout<<"vehicle destructor called. maxspeed:3; weight4"<<endl;
}
class bicycle:virtual public vehicle
{
	private:
		int height;
	public:
		bicycle();
		~bicycle();
};
bicycle::bicycle()
{
	cout<<"bicycle constructor called. height:1"<<endl;
}
bicycle::~bicycle()
{
	cout<<"bicycle destructor called. height:1"<<endl; 
}
class motorcar:virtual public vehicle
{
	private:
		int seatnum;
	public:
		motorcar();
		~motorcar();
};
motorcar::motorcar()
{
	cout<<"motorcar constructor called. seatnum:2"<<endl;
}
motorcar::~motorcar()
{
	cout<<"motorcar destructor called. seatnum:2"<<endl;
}
class motorcycle:public bicycle,public motorcar
{
	public:
		motorcycle(int a,int b,int c,int d);
		~motorcycle();
};
motorcycle::motorcycle(int a,int b,int c,int d)
{
	cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
	cout<<"motorcycle destructor called"<<endl;
}
int  main(int  argc,  char  *argv[]) 
{ 
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示seatnum，3表示maxspeed，4表示weight 
        m.run(); 
        m.stop(); 
        return  0; 
}
