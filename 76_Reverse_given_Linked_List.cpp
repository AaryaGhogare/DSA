#include<iostream>
using namespace std;
class Node
{
	public:
		Node *next,*prev;
		int data;
		Node()
		{
			data=0;
			next=NULL;
      		prev=NULL;
		}
		Node(int x)
		{
			data=x;
			next=NULL;
      prev=NULL;
		}
};
class DLL
{
	private:
		Node* head;
	public:
		DLL()
		{
			head=NULL;
		}
	
	void create(int n)
	{
		int x,i;
		cout<<"\nEnter the data of head: ";
		cin>>x;
		head = new Node(x);
		Node *p,*q;
		p=head;
    	q=head;
		for(i=1;i<=n-1;i++)
		{
			cout<<"\nEnter the next data entry: ";
			cin>>x;
			p->next=new Node(x);
	        p->prev=q;
	        q=q->next;
			p=p->next;
		}
	}
  void reverseList()
  {
    int temp=0;
    if(head==NULL)
    {
      return;
    }
    Node *p,*q;
    p=head;
    q=head;
    while(q->next!=NULL)
    {
      q=q->next;
    }
    while(p!=q)
    {
      temp=p->data;
      p->data=q->data;
      q->data=temp;
      p=p->next;
      q=q->prev;
      if(p==q || p->prev==q)
	  {
		 break;
	  }
    }
  }
	void show()
	{
		cout<<"\nThe elements of list are: \n";
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
	DLL dl;
	dl.create(n);
	dl.show();
  dl.reverseList();
  cout<<"\nAfter list is reversed-";
	dl.show();
}
