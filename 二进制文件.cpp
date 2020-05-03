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
	ofstream out("out.txt",ios::binary);//使用write函数，以二进制形式，将a数组中存放的n个学生一次写入out.txt文件中（不要使用循环）
	out.write(reinterpret_cast<char*>(a),sizeof(a));
	out.close();
	
	student *b=new student[n];//使用write函数，以二进制形式，将a数组中存放的n个学生一次写入out.txt文件中（不要使用循环）
	ifstream in("out.txt",ios::binary);
	for(i=0;i<n;i++)
	{
		in.read(reinterpret_cast<char*>(&b[i]),sizeof(a[i]));
	}
	in.close();
	
	ofstream out2("out.txt");//使用write函数，以文本形式，将b数组中存放的n个学生一次写入out.txt文件中，要求添加到文件末尾（不要使用循环）
	out.seekp(-1, ios::end);
	out2.write(reinterpret_cast<char*>(b), sizeof(b));
	out.close();

}
