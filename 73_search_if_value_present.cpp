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
	bool searchKey(int key)
  {
    Node *q=head;
    while(q!=NULL)
    {
      if(q->data==key)
      {
        return true;
      }
      q=q->next;
    }
    return false;
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
	cout<<"\nEnter the value to check if it's present in list or not(T/F): ";
  cin>>x;
  bool ans=sl.searchKey(x);
	cout<<" "<<ans;
}
