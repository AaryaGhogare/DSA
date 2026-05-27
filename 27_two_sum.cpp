#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
	public:
	    vector<int> twoSum(vector<int>& nums, int target) 
	    {
	        /* BRUTE FORCE APPROACH
			int i,j,sum;
	        vector <int> ans;
	        for(i=0;i<nums.size();i++)
			{
				for(j=i+1;j<nums.size();j++)
				{
					if(nums[i]+nums[j]==target)
					{
						ans.push_back(i);
						ans.push_back(j);
					}
				}
			}
			return ans;	   */
			//BETTER
			map <int,int> mpp;
			int n = nums.size();
			vector <int> ans;
			ans.push_back(-1);
			ans.push_back(-1);
			int i;
			for(i=0;i<n;i++)
			{
				int a = nums[i];
				int b = target - a;
				if(mpp.find(b) != mpp.end())
				{
					ans[0]=mpp[b];
					ans[1]=i;
					return ans;
				}
				mpp[a]=i;
			}
			return ans; 
		}
};
int main()
{
	int n,x,target,i;
	vector <int> arr;
	vector <int> ans;
	cout<<"\nEnter the number of elements required in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	cout<<"\nEnter the value of target (for sum): ";
	cin>>target;
	Solution sol;
	ans=sol.twoSum(arr,target);
	cout<<"\nThe indices are: "<<ans[0]<<", "<<ans[1];
}
