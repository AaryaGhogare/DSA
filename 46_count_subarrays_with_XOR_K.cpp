#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
  public:
      int subarraysWithXorK(vector<int> &nums, int k) 
      {
          /*BRUTE APPROACH
          int i,j,m,XOR=0,count=0,n=nums.size();
          for(i=0;i<n;i++)
          {
            for(j=i;j<n;j++)
            {
              XOR=0;
              for(m=i;m<=j;m++)
              {
                XOR=XOR ^ nums[m];
              }
              if(XOR == k)
              {
                count++;
              }
            }
          }
        return count;*/

        /*BETTER
        int i,j,m,XOR=0,count=0,n=nums.size();
        for(i=0;i<n;i++)
        {
           XOR=0;
          for(j=i;j<n;j++)
          {
            XOR=XOR ^ nums[j];
            
            if(XOR == k)
            {
              count++;
            }
          }
        }
      return count;*/

      //OPTIMAL
      int i,x,xr,cnt=0;
      map <int,int> mpp;
      mpp[xr]++;
      for(i=0;i<nums.size();i++)
      {
        xr=xr^nums[i];
        int x = xr^k;
        cnt = cnt + mpp[x];
        mpp[x]++;
      }
      return cnt;
    }
};
int main()
{
  int n,x,ans,i,target;
	vector <int> arr;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
  cout<<"Enter the target: ";
  cin>>target;
	Solution sol;
	ans=sol.subarraysWithXorK(arr,target);
	cout<<"\nThe count of XOR subarrays that give K = "<<ans;
}
