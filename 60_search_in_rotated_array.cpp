#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int search(vector<int>& nums, int target) 
      {
          int low=0,up=nums.size()-1,mid;
          while(low<=up)
          {
            mid=(low+up)/2;
            if(nums[mid]==target)
            {
              return mid;
            }
            if(nums[low] <= nums[mid])
            {
              if(target<=nums[mid]&& target >=nums[low])
              {
              	up=mid-1;	
			  }
			  else
			  {
			  	low=mid+1;
			  }
            }
            else
            {
	        	if(target<=nums[up] && target >=nums[mid])
	        	{
	        		low=mid+1;
				}
				else
				{
					up=mid-1;
				}
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
  cout<<"\nEnter the element to search: ";
  cin>>x;
	Solution sol;
	ans=sol.search(arr,x);
	cout<<"\nThe index is: "<<ans;
}
