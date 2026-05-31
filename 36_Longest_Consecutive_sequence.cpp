#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;
class Solution 
{
  public:
      int longestConsecutive(vector<int>& nums) 
      {
        /*BRUTE FORCE APPROACH 
		int i,j,n,count,x,maxlen=0;
        n = nums.size();
        for(i=0;i<n;i++)
        {
          count = 0;
          x = nums[i];
          while(ls(nums,x) == true)
          {
	        count++;
	        maxlen = max(maxlen,count);
	        x++;
          }
        }
        return maxlen;     
      }

      bool ls(vector <int> nums, int x)
      {
        int i,j,n=nums.size();
        for(i=0;i<n;i++)
        {
          if(nums[i] == x)
          {
            return true;
          }
        }
        return false;
      */
      
      /*BETTER
      int longestseq=1,n=nums.size(),lastsmaller=INT_MIN,count = 0;
      int i;
      sort(nums.begin(),nums.end());
      for(i=0;i<n;i++)
      {
      	if(nums[i] - 1 == lastsmaller)
      	{
      		count = count + 1;
      		lastsmaller = nums[i];
		}
		else if(nums[i]!=lastsmaller)
		{
			count=1;
			lastsmaller = nums[i];	
		}
		longestseq=max(count,longestseq);
	  }
	  return longestseq;
	*/
	
		//OPTIMAL
		int n = nums.size(),longest = 1,i,cnt;
		if(n == 0)
		{
			return 0;
		}
		unordered_set<int> st;
		for(i=0;i<n;i++)
		{
			st.insert(a[i]);
		}
		for(auto it : st)
		{
			if(st.find(it - 1) == st.end())
			{
				cnt = 1;
				int x = it;
				while(st.find(x+1) != st.end)
				{
					x = x + 1;
					cnt = cnt + 1;
				}
				longest = max(longest , cnt);
			}
		}
		return longest;
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
	int ans;
	Solution sol;
	ans=sol.longestConsecutive(arr);
	cout<<"\nThe longest consecutive sequence is: "<<ans;
}
