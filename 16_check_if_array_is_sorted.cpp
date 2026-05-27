#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	public:
		bool isSorted(vector<int>& nums)
		{
			int i,j;
			for(i=0;i<nums.size();i++)
			{
				for(j=i;j<nums.size();j++)
				{
					if(nums[i]>nums[j])
					{
						return false;
					}
				}
			}
			return true;
		}
	
};
int main()
{
	Solution sol;
	vector<int> arr;
	int x,i;
	for(i=0;i<5;i++)
	{
		cout<<"\nEnter number to add in array: ";
		cin>>x;
		arr.push_back(x);
	}
	
	bool ans;
	ans=sol.isSorted(arr);
	
	cout<<"\nArary Sorted: "<<ans;
}
