#include<iostream>
using namespace std;
class Solution{	
	public:
		static int sum;
		int NnumbersSum(int N)
        {
            if(N!=0)
            {
                sum=sum+N;
                N--;
                NnumbersSum(N);
            }
            return sum;
		}
};
int Solution::sum=0;
int main()
{
	Solution sol;
	int N;
	cout<<"\nEnter the number: ";
	cin>>N;
	int ans;
	ans=sol.NnumbersSum(N);
	cout<<"\nSum is: "<<ans;
}

