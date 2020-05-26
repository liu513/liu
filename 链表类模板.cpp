#include <iostream>
#include <iomanip>
using namespace std;
typedef struct listNode
{
    int data;
    listNode* next;
}LList, *PList;
template<typename T>
class linkedList
{
public:
    
    void insert( int value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( int pos, int& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    PList head;
    int len;
};

template<typename T>
void linkedList<T>::insert(int value)
{
	PList node = new LList;
    node->data = value;
    node->next = NULL;
    
    PList p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    
    node->next = p->next;
    p->next = node;
}
template<typename T>
bool linkedList<T>:: initiate()
{
	
	head = (PList)malloc(sizeof(LList));
	head->next = NULL;
	if(head->next!=NULL) return false;
	else return true;
}

template<typename T>
int linkedList<T>::Length()
{
    
    PList p = head;
    len = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
template<typename T>
bool linkedList<T>::remove(int pos, int& value)
{
    if (pos > this->Length())
    {
        cout << "pos > len, failed" << endl;
        return false;
    }
    else if (pos <=0)
    {
        cout << "pos <= 0, failed" << endl;
        return false;
    }
    {
	
	    PList p = head;
	    PList q = head->next;
	    int num = 1;
	    while (num < pos)
	    {
	        p = q;
	        q = q->next;
	        num++;
	    }
	    value = q->data;
	    p->next = q->next;
	
	    return true;
	}
}
template<typename T>
void linkedList<T>::print()
{
    if( head->next==NULL )
    {
        
        return;
    }
    PList p = head;
    while(p->next!=NULL)
    {
    	p = p->next;
        cout <<p->data << ' ';
        
    }
    cout << endl;
}

int main(int argc, char* argv[])
{

    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}

