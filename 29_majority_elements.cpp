#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        /*
        BRUTE FORCE APPROACH
		int n = nums.size();

        for(int i =0; i< n;i++)
        {
            int count =0;
            for(int j =0;j<n;j++)
            {
                if(nums[i] == nums[j])
                {
                    count++;
                }
            }

            if(count > n/2)
            {
                return nums[i];
            }
        }
        return -1;*/
        
        /*BETTER APPROACH
        map <int,int> mpp;
        int i,n=nums.size();
        for(i=0;i<n;i++)
        {
            mpp[nums[i]]++ ;
        }
        map <int,int> ::iterator it;
		for(it = mpp.begin(); it != mpp.end(); it++)
		{
			 if(it->second>(nums.size()/2))
	        {
	            return it->first;
	        }
    	
		}*/
		
		//OPTIMAL
		int cnt = 0;
		int el,i;
		for(i = 0;i<nums.size();i++)
		{
			if(cnt ==0)
			{
				cnt = 1;
				el = nums[i];
			}
			else if(nums[i]==el)
			{
				cnt++;
			}
			else
			{
				cnt--;
			}
		}
		int cnt1 = 0;
		for(int i = 0;i<nums.size();i++)
		{
			if(nums[i]==el)
			{
				cnt1++;
			}
			if(cnt1 > (nums.size()/2))
			{
				return el;
			}
		}
       	return -1;
    }
};
int main()
{
	int n,i,x;
	cout<<"\nEnter the number of elements required in array: ";
	cin>>n;
	vector <int> arr;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	Solution sol;
	int ans;
	ans=sol.majorityElement(arr);
	cout<<"\nThe Majority occuring number is: "<<ans;
	
}
