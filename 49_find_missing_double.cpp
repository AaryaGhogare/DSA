#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
      vector<int> findMissingRepeatingNumbers(vector<int> nums) 
      {
        /*BRUTE APPROACH
		int n= nums.size();
        int i,j;
        vector <int> ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
        {
          for(j=0;j<n;j++)
          {
            if(nums[i]==nums[j])
            {
              ans.push_back(nums[i]);
            }
          }
        }
        for(i=0;i<n;i++)
        {
          if(nums[i]-nums[i-1]==2)
          {
            ans.push_back(nums[i]-1);
          }
        }
        return ans;*/
        
        /*BETTER
        int n= nums.size();
        int i,j;
        vector <int> ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
        {
          if(nums[i]==nums[i-1])
          {
            ans.push_back(nums[i]);
          }
        }
        for(i=0;i<n;i++)
        {
          if(nums[i]-nums[i-1]==2)
          {
            ans.push_back(nums[i]-1);
          }
        }
        return ans;*/
        //OPTIMAL
        int n= nums.size();
        int i;
        vector <int> ans(2);
        sort(nums.begin(),nums.end());
        for(i=1;i<n;i++)
        {
          if(nums[i]==nums[i-1])
          {
            ans[0]=(nums[i]);
          }
          if(nums[i]-nums[i-1]==2)
          {
            ans[1]=(nums[i]-1);
          }
        }
        if(nums[0]!=1)
        {
        	ans[1]=1;
		}
		if(nums[n-1]!=n)
        {
        	ans[n-1]=n;
		}
        return ans;
      }
};
int main()
{
  int n,x,i;
	vector <int> arr,ans;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	Solution sol;
	ans=sol.findMissingRepeatingNumbers(arr);
	cout<<"\nThe repeating number is "<<ans[0]<<" and missing is "<<ans[1];
}
