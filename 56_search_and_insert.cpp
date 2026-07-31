#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int lowerBound(vector<int> &nums, int target) 
      {
        int low,up,mid,n=nums.size();
        low=0;
        up=n-1;
        if(target<nums[0])
        {
            return 0;
        }
        while(low<=up)
        {
          mid=(low+up)/2;
          if(target == nums[mid])
          {
            return mid;
          }
          else if(nums[mid] < target)
          {
          	low=mid+1;
          }
          else
          {
            up=mid-1;
            if(nums[mid]>target && nums[mid-1]<target)
            {
            	return mid;
			}
          }
        }
        return nums.size();
      }
};
int main()
{
  vector <int> num;
  int n,x,i;
	vector <int> arr;
  int ans;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
  cout<<"\nEnter value x: ";
  cin>>x;
	Solution sol;
	ans=sol.lowerBound(arr,x);
	cout<<"\nThe index where "<<x<<" is to be inserted is: "<<ans;
}
