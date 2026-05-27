#include<iostream>
using namespace std;
class Solution
{	
	public:
	    int reverse(int x) 
	    {
	        int revNum = 0;
	
	        while(x != 0)
	        {
	            int last_digit = x % 10;
	
	            if(revNum > INT_MAX/10 || revNum < INT_MIN/10)
	            {
	                return 0;
	            }
	            revNum = (revNum * 10) + last_digit;
	            x = x / 10;
	        }
	        return revNum;
	    }
};
int main()
{
	int n,rev;
	cout<<"\nEnter a Number: ";
	cin>>n;
	Solution sol;
	rev=sol.reverse(n);
	cout<<"\nReverse: "<<rev;
	return 0;
}
