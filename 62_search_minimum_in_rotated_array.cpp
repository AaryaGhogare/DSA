#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
       int low=0,up=nums.size()-1,mid,mini=INT_MAX;
      while(low<up)
      {
        mid=(low+up)/2;
        if(nums[mid]>nums[up])
        {
            low=mid+1;
        }
        else
        {
            up=mid-1;
        }
      }
     return nums[low];
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
	ans=sol.findMin(arr);
	cout<<"\nThe minimum is: "<<ans;
}
