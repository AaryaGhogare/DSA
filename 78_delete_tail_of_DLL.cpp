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
	void delTail()
  {
  	if(head==NULL)
  	{
  		return ;	
    }
    if(head->next==NULL)
    {
    	delete head;
    	head = NULL;
    	return;
	}
    Node *p;
    p=head;
    while(p->next!=NULL)
    {
      p=p->next;
    }
    p->prev->next=NULL;
    delete p;
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
	dl.delTail();
  cout<<"\nDLL- ";
	dl.show();
}
