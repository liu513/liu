#include <iostream>
#include <iomanip>
using namespace std;
//测试一
typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    LList *head;
    int len;
};

linkedList::linkedList()
{
}

linkedList::~linkedList()
{
	PList p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void linkedList::insert(int value)
{
    PList p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    PList Node = (PList)malloc(sizeof(LList));
    Node->data = value;
    Node->next = p->next;
    p->next = Node;
}
bool linkedList:: initiate()
{
	
	head=new node;
	if(head!=NULL) return true;
	else return false;
}

bool linkedList::isEmpty()
{
    if (head->next == NULL) return true;
    else return false;
}

int linkedList::Length()
{
    if (isEmpty() == 1) return -1;
    PList p = head->next;
    len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

bool linkedList::remove(int pos, int& value)
{
    if (pos > len)
    {
        cout << "pos > len, failed" << endl;
        return false;
    }
    else if (pos == 0 || head->next == NULL)
    {
        cout << "pos <= 0, failed" << endl;
        return false;
    }
    PList p = head;
    PList q = head->next;
    int num = 1;
    while (num < pos)
    {
        p = p->next;
        q = q->next;
        num++;
    }
    value = q->data;
    p->next = q->next;
    free(q);
    return true;
}
void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    linkedList L1;
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

