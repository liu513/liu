#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;
struct student
{
	short stu_id;
	short score;
};
int main()
{
	int n,i;
	cin>>n;
	student *a=new student[n];
	for(i = 0;i < n;i++)
	{
		cin>>a[i].stu_id;
		cin>>a[i].score;
	}
	ofstream out("out.txt",ios::binary);//ʹ��write�������Զ�������ʽ����a�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У���Ҫʹ��ѭ����
	out.write(reinterpret_cast<char*>(a),sizeof(a));
	out.close();
	
	student *b=new student[n];//ʹ��write�������Զ�������ʽ����a�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У���Ҫʹ��ѭ����
	ifstream in("out.txt",ios::binary);
	for(i=0;i<n;i++)
	{
		in.read(reinterpret_cast<char*>(&b[i]),sizeof(a[i]));
	}
	in.close();
	
	ofstream out2("out.txt");//ʹ��write���������ı���ʽ����b�����д�ŵ�n��ѧ��һ��д��out.txt�ļ��У�Ҫ����ӵ��ļ�ĩβ����Ҫʹ��ѭ����
	out.seekp(-1, ios::end);
	out2.write(reinterpret_cast<char*>(b), sizeof(b));
	out.close();

}
