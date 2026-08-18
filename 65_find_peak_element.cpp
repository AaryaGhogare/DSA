#include<iostream>
#include<vector>
using namespace std;
class Solution
{
  public:
     int findPeakElement(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
        {
          return 0;
        }
        if(nums[n-2]<nums[n-1])
        {
          return n-1;
        }
        int low=1,mid,up=n-2;
        while(low<=up)
        {
          mid=(low+up)/2;
          if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
          {
            return mid;
          }
          else if(nums[mid]>nums[mid-1])
          {
            low=mid+1;
          }
          else
          {
            up=mid-1;
          }
        }
        return -1;
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
	Solution sol;
	ans=sol.findPeakElement(arr);
	cout<<"\nThe peak element is at index: "<<ans;
}
