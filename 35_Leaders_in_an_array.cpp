#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution 
{
    public:
        vector<int> leaders(vector<int>& nums) 
        {
          /*BRUTE FORCE APPROACH
          int i,j,n=nums.size(),maxnum=0;
          vector <int> ans;
          for(i=0;i<n;i++)
          {
          	maxnum=0;
            for(j=i+1;j<n;j++)
            {
            	maxnum = max(nums[j],maxnum);
            	if(nums[i] < maxnum)
            	{
            		break;
				      }
            }
            if(nums[i] > maxnum)
	          {
	        	  ans.push_back(nums[i]);     
	          }
          }
          return ans;
        */

       //OPTIMAL
       int i,maxnum=INT_MIN,n=nums.size();
       vector <int> ans;
       for(i=n-1;i>=0;i--)
       {
         maxnum=max(nums[i],maxnum);
         if(nums[i] >= maxnum)
         {
          ans.push_back(nums[i]);
         }
       }
       reverse(ans.begin(),ans.end());
       return ans;
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
	ans=sol.leaders(arr);
	cout<<"\nThe leaders array is: \n";
	for(i=0;i<ans.size();i++)
	{
		cout<<" "<<ans[i];
	}
}
