#include<iostream>
using namespace std;
class Solution 
{
	public:
	    bool isArmstrong(int n)
	    {
	        int rem=0,arm=0;
	        int og=n;
	        while(n!=0)
	        {
	            rem=n%10;
	            arm=arm+(rem*rem*rem);
	            n=n/10;
	        }
	        if(arm==og)
	        {
	            return true;
	        }
	        return false;
	    }
};
int main()
{
	int n;
	cout<<"\nEnter the number: ";
	cin>>n;
	Solution sol;
	bool ans = sol.isArmstrong(n);
	cout<<"\nIs ArmStrong Number: "<<ans;
	
}
