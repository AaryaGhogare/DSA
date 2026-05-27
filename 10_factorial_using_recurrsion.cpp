#include<iostream>
using namespace std;
class Solution {
public:
    static int result;
    int factorial(int N) 
    {
        if(N==0)
        {
            return 1;
        }
        if(N!=0)
        {
            result=result*N;
            N--;
            factorial(N);
        }
        return result;
    }
};
int Solution::result=1;
int main()
{
	Solution sol;
	int N;
	cout<<"\nEnter the number: ";
	cin>>N;
	int ans;
	ans=sol.factorial(N);
	cout<<"\nFactorial is: "<<ans;
}
