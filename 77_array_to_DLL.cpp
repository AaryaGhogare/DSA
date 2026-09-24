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
	void arraytodll(vector<int> &arr)
  {
  	if(arr.empty())
  	{
  		return;
	  }
    int i;
    Node *p,*q;
    head=new Node(arr[0]);
    q=head;
    for(i=1;i<arr.size();i++)
    {
      p=new Node(arr[i]);
      q->next=p;
      p->prev=q;
      q=p;
    }
    return;
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
  vector <int> arr;
  for(i=0;i<n;i++)
  {
    cout<<"\nEnter the elements of array: ";
    cin>>x;
    arr.push_back(x);
  }
	DLL dl;
	dl.arraytodll(arr);
  cout<<"\nDLL- ";
	dl.show();
}
