#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
	public:
	    vector<int> divisors(int n) 
	    {
	        int count=0,i;
	        vector<int> arr;
	        for(i=1;i<=n;i++)
	        {
	            if(n%i==0)
	            {
	                arr.push_back(i);
	                count++;
	            }
	        }
	        return arr;
	    }
};
int main()
{
	int n,i;
	cout<<"\nInput: ";
	cin>>n;
	Solution sol;
	vector<int> ans;
	ans = sol.divisors(n);
	cout<<"\nThe divisors are : ";
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ,";
	}
}
