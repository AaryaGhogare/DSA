#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
class Solution 
{
  public:
    
    int maxLen(vector<int>& nums) 
    {
      /*BRUTE APPROACH
      int i,j,k,sum,maximumcount=0;
      for(i=0;i<nums.size();i++)
      {
        sum=0;
        for(j=i;j<nums.size();j++)
        {
            sum=sum + nums[j];
	        
	        if(sum == 0)
	        {
	            maximumcount = max(maximumcount, j - i + 1);
	        }
        }
      }
      return maximumcount;*/

      //BETTER
      unordered_map <int,int> mpp;
      int maxm=0;
      int i,sum=0;
      for(i=0;i<nums.size();i++)
      {
        sum = sum + nums[i];
        if(sum == 0)
        {
          maxm = i+1;
        }
        else
        {
          if(mpp.find(sum)!=mpp.end())
          {
            maxm=max(maxm,i-mpp[sum]);
          }
          else{
            mpp[sum] = i;
          }
        }
      }
      return maxm;
    }
};
int main()
{
  int n,x,ans,i;
	vector <int> arr;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	Solution sol;
	ans=sol.maxLen(arr);
	cout<<"\nThe longest subarray has "<<ans<<" elements.";
}
