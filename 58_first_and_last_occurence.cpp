#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
      int upperBound(vector<int> &nums, int x)
      {
        int low,up,mid,n=nums.size(),ans=-1;
        low=0;
        up=n-1;
        while(low<=up)
        {
          mid=(low+up)/2;
          if(nums[mid] == x)
          {
            ans = mid;
            low = mid + 1;     // continue searching right
          }
          else if(nums[mid] < x)
         {
            low = mid + 1;
         }
          else
          {
            up=mid-1;
          }
        }
        return ans;
      }
      int lowerBound(vector<int> &nums, int x) 
      {
        int ans = -1;
        int low,up,mid,n=nums.size();
        low=0;
        up=n-1;
		while(low <= up)
		{
		    mid = (low + up)/2;
		    if(nums[mid] == x)
            {
                ans = mid;
                up = mid - 1;      // continue searching left
            }
            else if(nums[mid] < x)
            {
                low = mid + 1;
            }
		    else
		    {
                up = mid - 1;
		    }
		}
        
		return ans;
      }      
     
      public:
      vector<int> searchRange(vector<int>& nums, int target) 
      {
        if(nums.size()==0)
        {
            return {-1,-1};
        }
        int ub,lb;
        lb=lowerBound(nums,target);
        if(lb==-1||nums[lb]!=target)return{-1,-1};
        ub=upperBound(nums,target);
        return{lb,ub};
      }
};
int main()
{
  vector <int> num,ans;
  int n,x,i;
	vector <int> arr;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
  cout<<"\nEnter the target x: ";
  cin>>x;
	Solution sol;
	ans=sol.searchRange(arr,x);
  cout<<"[";
  for(i=0;i<ans.size();i++)
	{
    cout<<ans[i];
    if(i!=ans.size())
    {
      cout<<",";
    }
	}
  cout<<"]";
}
