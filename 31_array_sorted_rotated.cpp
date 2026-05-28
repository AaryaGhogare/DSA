#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
  public:
   bool rotatedandsorted(vector <int> &nums)
   {
	int count = 0,i,n;
	n=nums.size();
	for(i=1;i<nums.size();i++)
	{
		if(nums[i-1]>nums[i])
		{
			count++;
		}
	}
    if(nums[n-1] > nums[0])
    {
    	count++;
	}
	return count <= 1;
   }
};
int main()
{
  int i,n,x;
  vector <int> arr;
  cout<<"\nEnter the number of elements required: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cout<<"\nEnter a number: ";
    cin>>x;
    arr.push_back(x);
  }
  Solution sol;
  bool ans;
  ans = sol.rotatedandsorted(arr);
  cout<<"\nThe array is sorted and rotated:"<<ans;
  return 0;
}
