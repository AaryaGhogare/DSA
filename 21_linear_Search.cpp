#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
	public:
	    int linearSearch(vector<int>& nums, int target) 
	    {
	    	int i,n;
	    	n=nums.size();
	        for(i=0;i<n;i++)
	        {
	        	if(nums[i]==target)
	        	{
	        		return i;
				}
			}
			return -1;
	    }
};
int main()
{
	vector<int> array;
	int n,x,i;
	cout<<"\nEnter the number of elements to be included in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number to add: \n";
		cin>>x;
		array.push_back(x);
	}
	cout<<"\nEnter a number to search: ";
	cin>>x;
	Solution sol;
	int ans;
	ans=sol.linearSearch(array,x);
	
	cout<<"\nThe index is: "<<ans;

}
