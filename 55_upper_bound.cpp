#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int upperBound(vector<int> &nums, int x) 
      {
        int low,up,mid,n=nums.size();
        low=0;
        up=n-1;
        while(low<=up)
        {
          mid=(low+up)/2;
          if(nums[mid] <= x)
          {
          	low=mid+1;
          }
          else
          {
            up=mid-1;
            if(nums[mid]>x)
            {
            	return mid;
			}
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
	ans=sol.upperBound(arr,x);
	cout<<"\nThe index is: "<<ans;
}
