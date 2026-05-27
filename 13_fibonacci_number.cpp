#include<iostream>
using namespace std;
class Solution 
{
	public:
	    int fib(int n) 
	    {
	    	int last,slast,ans;
	        while(n>=0)
	        {
	            if(n==1)
	            {
	                return 1;
	            }
	            else if(n==0)
	            {
	                return 0;
	            }
	            else
	            {
	                last= fib(n-1);
	                slast=fib(n-2);
	                return last+slast;
	            }
	        }
	    }
};
int main()
{
	int n;
	cout<<"\nEnter n: ";
	cin>>n;
	int ans;
	Solution sol;
	ans=sol.fib(n);
	cout<<"\n "<<ans;
}
