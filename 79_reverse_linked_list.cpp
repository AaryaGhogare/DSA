#include<iostream>
#include<vector>
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

    if(n<=0)
    {
        head=NULL;
        return;
    }

    cout<<"\nEnter the data of head: ";
    cin>>x;

    head=new Node(x);
    Node *p=head;

		for(i=1;i<n;i++)
		{
			cout<<"\nEnter the next element: ";
			cin>>x;

			Node *q=new Node(x);
			p->next=q;
			q->prev=p;
			p=q;
		}

	}
	void reverseList()
  {
  	if(head==NULL)
  	{
  		return ;	
    }
    if(head->next==NULL)
    {
    	return;
	  }
    Node *p,*q;
    int temp;
    p=head;
    q=head;
    while(q->next!=NULL)
    {
      q=q->next;
    }
    while(p!=q && p->prev!=q)
    {
      temp = q->data;
      q->data= p->data;
      p->data = temp;
      p=p->next;
      q=q->prev;
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
	dl.reverseList();
  cout<<"\nDLL- ";
	dl.show();
}
