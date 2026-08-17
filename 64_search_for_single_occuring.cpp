#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int singleNonDuplicate(vector<int>& nums) 
      {
          int up=nums.size()-1,mid,low=0;
          while(low<up)
          {
            mid = (low+up)/2;
            if(mid % 2 == 1)
            {
              mid--;
            }
            if(nums[mid] == nums[mid + 1])
            {
              low=mid+2;
            }
            else
            {
              up=mid;
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
	ans=sol.singleNonDuplicate(arr);
	cout<<"\nThe digit occuring for once is: "<<ans;
}
