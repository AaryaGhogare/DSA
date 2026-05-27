#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
	public:
	    int longestSubarray(vector<int> &nums, int k)
	    {
	       /*
		   BRUTE APPROACH
		    int len=0,sum,i,j;
	        for(i=0;i<nums.size();i++)
	        {
	        	sum=0;
	        	for(j=i;j<nums.size();j++)
	        	{
	        		sum=sum + nums[j];
	        		if(sum == k)
	        		{
	        			len = max(len,j-i+1);
					}
				}
			}
			return len;*/
			
		/*	BETTER APPROACH
			
			map<long long , int > preSumMap;
			long long sum = 0;
			int maxLen = 0;
			int i;
			for(i=0;i<nums.size();i++)
			{
				sum = sum + nums[i];
				if(sum == k)
				{
					maxLen = max(maxLen,i+1);
				}
				long long rem = sum - k;
				if(preSumMap.find(rem) != preSumMap.end())
				{
					int len = i - preSumMap[rem];
					maxLen = max(maxLen , len);
				}
				if(preSumMap.find(sum) == preSumMap.end())
				{
					preSumMap[sum] = i;
				}
			}
			return maxLen;
	    }*/
	    
	    //OPTIMAL
	    int left = 0,right = 0;
	    long long sum = nums[0];
	    int maxLen = 0;
	    int n = nums.size();
		    while(right <n)
		    {
		    	while(left <= right && sum > k)
		    	{
		    		sum = sum - nums[left];
		    		left++;
				}
				if(sum == k)
				{
					maxLen = max(maxLen, right-left+1);
				}
				right++;
				if(right < n)
				{
					sum = sum + nums[right];
				}
			}
		return maxLen;

		}
};

int main()
{
	int n,x,k,ans,i;
	vector <int> arr;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	cout<<"\nEnter the value of k (for longest subarray): ";
	cin>>k;
	Solution sol;
	ans=sol.longestSubarray(arr,k);
	cout<<"\nThe longest subarray has "<<ans<<" elements.";
}
