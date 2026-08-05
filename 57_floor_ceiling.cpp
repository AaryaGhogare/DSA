#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      vector<int> getFloorAndCeil(vector<int> nums, int x) 
      {
        vector <int> ans(2,-1);
        int low,up,mid;
        low=0;
        up=nums.size()-1;
        mid=(low+up)/2;
        while(low<=up)
        {
          mid=(low+up)/2;
          if(x==nums[mid])
          {
            ans[0]=x;
            ans[1]=x;
            break;
          }
          else if(nums[mid]<x)
          {
          	low=mid+1;
            ans[0]=nums[mid];   
          }
          else if(nums[mid]>x)
          {
          	up=mid-1;
          	ans[1]=nums[mid];
          	if(ans[1]>nums[mid])
          	{
          		ans[1]=nums[mid];
			}
          }
        }
        return ans;
      }
};
int main()
{
  vector <int> num;
  int n,x,i;
	vector <int> arr,ans(2,-1);
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
  cout<<"\nEnter x: ";
  cin>>x;
	Solution sol;
	ans=sol.getFloorAndCeil(arr,x);
	cout<<"\nThe floor for  "<<x<<" is: "<<ans[0];
  cout<<"\nThe ceil for  "<<x<<" is: "<<ans[1];
}
