#include<iostream>
using namespace std;
class Solution {
public:
    int GCD(int n1,int n2) 
    {
        int min,max;
        if(n1>n2)
        {
            max=n1;
            min=n2;
        }
        else if(n2>n1)
        {
            min=n1;
            max=n2;
        }
        else{
            max=n1;
            min=n2;
        }
        int gcd;
        for(int i=1;i<=min/2;i++)
        {
            if(n1%i==0 && n2%i==0)
            {
                gcd=i;
            }
        }
        return gcd;
    }
};
int main()
{
	int a,b;
	cout<<"\nEnter two number to find their GCD: ";
	cin>>a>>b;
	int gcdAns;
	Solution sol;
	gcdAns = sol.GCD(a,b);
	cout<<"\nGCD is: "<<gcdAns;
	return 0;
}
