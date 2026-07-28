#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      int maxProduct(vector<int>& nums) 
      {
         /* BRUTE APPROACH
		 int i,j,k,prod=1,maxim=INT_MIN;
          for(i=0;i<nums.size();i++)
          {
            for(j=i;j<nums.size();j++)
            {
              prod=1;
              for(k=i;k<=j;k++)
              {
                prod=prod * nums[k];
              }
              maxim=max(prod,maxim);
            }
          }
          return maxim;*/
          /*BETTER
          int i,j,k,prod=1,maxim=INT_MIN;
          for(i=0;i<nums.size();i++)
          {
          	prod=1;
            for(j=i;j<nums.size();j++)
            {
              prod=prod * nums[j];
              maxim=max(prod,maxim);
            }
          }
          return maxim;*/

          //OPTIMAL
          int prefix=1,suffix=1,i;
          int ans = INT_MIN;
          for(i=0;i<nums.size();i++)
          {
            if(prefix == 0)
            {
              prefix=1;
            }
            if(suffix == 0)
            {
              suffix=1;
            }

            prefix = prefix * nums[i];
            suffix = suffix * nums[nums.size()-i-1];
            ans = max(ans, max(prefix,suffix));
          }
          return ans;
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
	ans=sol.maxProduct(arr);
	cout<<"\nThe maximum prod elements are: "<<ans;
}
