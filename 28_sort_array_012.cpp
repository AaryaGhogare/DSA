#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
	public:
	    void sortColors(vector<int>& nums) 
	    {
	        /*BRUTE FORCE APPROACH
			int i,j,n;
	        n=nums.size();
	        for(i=0;i<n;i++)
	        {
	        	for(j=i+1;j<n;j++)
	        	{
	        		if(nums[i]>nums[j])
	        		{
	        			swap(nums[i],nums[j]);
					}
				}
			}*/
			
			/*BETTER
			
			int cnt0=0,cnt1=0,cnt2=0;
			int i,n;
	        n=nums.size();
	        for(i=0;i<n;i++)
	        {
	        	if(nums[i]==0)
	        	{
	        		cnt0++;
				}
				if(nums[i]==1)
	        	{
	        		cnt1++;
				}
				if(nums[i]==2)
	        	{
	        		cnt2++;
				}
			}
			
			for(i=0;i<cnt0;i++)
			{
				nums[i]=0;
			}
			for(i=cnt0;i<cnt0+cnt1;i++)
			{
				nums[i]=1;
			}
			for(i=cnt0+cnt1;i<n;i++)
			{
				nums[i]=2;
			}*/
			
			//OPTIMAL-Dutuch National Flag Algorithm
			int n = nums.size();
			int low=0,mid=0,high=n-1;
			while(mid <= high)
			{
				if(nums[mid]==0)
				{
					swap(nums[low],nums[mid]);
					mid++;
					low++;
				}
				else if(nums[mid]==1)
				{
					mid++;
				}
				else if(nums[mid]==2)
				{
					swap(nums[mid],nums[high]);
					high--;
				}
			}
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
	sol.sortColors(arr);
	for(i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<" ";
	}
}
