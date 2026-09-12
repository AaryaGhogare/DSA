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
	void searchndel(Node *p)
  {
    int i;
    Node *q=head,*r;
    if(head==NULL || p == NULL)
    {
    	return; 
	}
	if(head->data==p->data)
    {
        r=head;
        head=head->next;
        delete r;
        return;
    }
    while(q->next!=NULL)
    {
      if(q->next->data==p->data)
      {
        r=q->next;
        q->next=q->next->next;
        delete r;
        return;
      }
      q=q->next;
    }
    return;
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
	cout<<"\nEnter the data to delete: ";
  cin>>x;
  Node *p;
  p=new Node(x);
  sl.searchndel(p);
	sl.show();
}
