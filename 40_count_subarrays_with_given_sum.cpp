#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution 
{
  public:
      int subarraySum(vector<int>& nums, int k) 
      {
      	//BETTTER
          /*int i,j,count = 0,sum = 0;
          for(i = 0;i < nums.size();i++)
          {
            sum = 0;
            for(j = i;j < nums.size();j++)
            {
                sum = sum + nums[j];
                if(sum == k)
                {
                	count++;
				}  
            }
          }
          return count;*/
          
          //OPTIMAL
          unordered_map<int,int> mpp;
          mpp[0] = 1;
          int presum = 0, cnt = 0,i;
          for(i = 0;i < nums.size();i++)
          {
          	preSum = presum + nums[i];
          	int remove = preSum - k;
          	cnt = cnt + mpp[remove];
          	mpp[preSum] = mpp[preSum] + 1;
		  }
      }
};
int main()
{
  vector<int> arr;
	int n,x,i,k;
	cout<<"\nEnter the number of elements to be included in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number to add: \n";
		cin>>x;
		arr.push_back(x);
	}
	cout<<"\nEnter the value of k: ";
	cin>>k;
	int ans;
	Solution sol;
	ans=sol.subarraySum(arr , k);
	cout<<"\nThe count of subarrays giving sum = k: "<<ans;
}
