#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int lowerBound(vector<int> &nums, int x) 
      {
        int ans = nums.size();
        int low,up,mid,n=nums.size();
        low=0;
        up=n-1;
		while(low <= up)
		{
		    int mid = (low + up)/2;
		    if(nums[mid] >= x)
		    {
		        ans = mid;
		        up = mid - 1;
		    }
		    else
		    {
		        low = mid + 1;
		    }
		}

		return nums.size();//question demands-->If no such index is found, return the size of the array.
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
	cout<<"\nThe index is: "<<ans;
}
