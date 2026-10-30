#include<iostream>
using namespace std;
class Node
{
	public:
		Node *next;
		int data;
		Node()
		{
			data=0;
			next=NULL;
		}
		Node(int x)
		{
			data=x;
			next=NULL;
		}
};
class SLL
{
	private:
		Node* head;
	public:
		SLL()
		{
			head=NULL;
		}
	  Node*  remove_from_end( int n) {
    Node *q, *p;
    q = head;
    int c = 0, i;
    if(head->next==NULL)
    {
        p=head;
       delete p;
       return head;
    }
    while (q != NULL)
    {
        c++;
        q = q->next;
    }
    if (c == n) 
    {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    
    q = head;
    for (i = 0; i < c - n; i++)
    {
        q = q->next;
    }
    
    p = head;
    while (p->next != q)
    {
        p = p->next;
    }
    p->next = q->next;
    delete q;
    
    return head;
}

	void create(int n)
	{
		int x,i;
		cout<<"\nEnter the data of head: ";
		cin>>x;
		head = new Node(x);
		Node *p;
		p=head;
		for(i=1;i<=n-1;i++)
		{
			cout<<"\nEnter the next data entry: ";
			cin>>x;
			p->next=new Node(x);
			p=p->next;
		}
	}
	void show()
	{
		cout<<"The elements of list are: \n";
		Node *p;
		p=head;
		while(p!=NULL)
		{
			cout<<p->data<<"\n ";
			p=p->next;
		}
	}
};
int main()
{
	Node *head;
	int x,n,i;
	cout<<"\nEnter the number of elements needed: ";
	cin>>n;
	SLL sl;
	sl.create(n);
	sl.show();
	cout<<"\nEnter kth position from last: ";
  cin>>x;
  sl.remove_from_end(x);
	sl.show();
}
