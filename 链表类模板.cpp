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
    
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
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
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}

