#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int findKRotation(vector<int> &nums)  
      {
          int low=0,up=nums.size()-1,mid;
          while(low <= up)
          {
            mid = (low+up)/2;
            if(low!=0 && nums[low-1] > nums[low])
            {
              return low;
            }
            else if(nums[up] < nums[low])
            {
              low = mid+1;
            }
            else if(nums[up] > nums[low])
            {
              up = mid-1;
            }
          }
          return 0;
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
	ans=sol.findKRotation(arr);
	cout<<"\nThe array was rotated "<<ans<<" times";
}
