#include<iostream>
#include<vector>
#include <climits>
using namespace std;
class Solution 
{
  public:
      int maxSubArray(vector<int>& nums)
      {
        /*BRUTE FORCE APPROACH
		  int maxSum,i,j,k,sum;
          maxSum = INT_MIN;
          for(i=0;i<nums.size();i++)
          {
            for(j=i;j<nums.size();j++)
            {
              sum = 0;
              for(k=i;k<=j;k++)
              {
                sum = sum + nums[k];
                maxSum = max(sum,maxSum);
              }
            }
          }
          return maxSum;    */
		  
		  /*BETTER
		    int maxL,j,i,sum=0;
	        maxL=INT_MIN;
	        int n=nums.size();
	        for(i=0;i<n;i++)
	        {
	            sum=0;
	            for(j=i;j<n;j++)
	            {
	                sum+=nums[j];
	                maxL=max(sum,maxL);
	            }
	
	        }
	        return maxL;*/
	        
	    	//OPTIMAL- Kadane's Algorithm
	    	int maxSum = INT_MIN,sum=0,i;
	    	for(i=0;i<nums.size();i++)
	    	{
	    		sum = sum + nums[i];
	    		if(sum > maxSum)
	    		{
	    			maxSum = sum;
				}
	    		
	    		if(sum < 0)
	    		{
	    			sum = 0;
				}
			}
			if(maxSum < 0)
			{
				return 0;
			}	
		  	return maxSum;
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
    cout<<"\nEnter the number(positive or negative): ";
    cin>>x;
    arr.push_back(x);
  }
  Solution sol;
  int ans;
  ans = sol.maxSubArray(arr);
  cout<<"\nThe max sum (subarray) is:"<<ans;
  return 0;
}
