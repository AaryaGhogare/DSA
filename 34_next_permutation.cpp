#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
      void nextPermutation(vector<int>& nums) 
      {
          /*BRUTE FORCE APPROACH
          next_permutation(nums.begin(),nums.end());
          */

          //OPTIMAL 
          int i,n= nums.size(),ind=-1;
          for(i=n-2;i>=0;i--)
          {
            if(nums[i] < nums[i+1])
            {
              ind = i;
              break;
            }
          }
          if(ind == -1)
          {
            reverse(nums.begin(),nums.end());
            return;
          }
          for(i=n-1;i>ind;i--)
          {
            if(nums[i] > nums[ind])
            {
              swap(nums[i],nums[ind]);
              break;
            }
          }
          reverse(nums.begin()+ind+1,nums.end());
          return;
      }
};
int main()
{
  vector<int> arr;
	int n,x,i;
	cout<<"\nEnter the number of elements to be included in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number to add: \n";
		cin>>x;
		arr.push_back(x);
	}
	vector <int> ans;
	Solution sol;
	sol.nextPermutation(arr);
	for(i=0;i<arr.size();i++)
	{
		cout<<" "<<arr[i];
	}
  
  return 0;
}
