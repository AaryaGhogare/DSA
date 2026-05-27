#include<iostream>
#include<vector>
using namespace std;
class Solution
{
	public:
		
		int seclarnum(vector<int>& nums)
		{
			int max=0,count=1;
        	int temp,i,j;
            for(i=0;i<nums.size();i++)
            {
                for(j=i;j<nums.size();j++)
                {
                    if(nums[i]>nums[j])
                    {
                        temp=nums[i];
                        nums[i]=nums[j];
                        nums[j]=temp;
                    }
                }
            }
			max=nums[nums.size()-1];
            for(j=nums.size()-1;j>=0;j--)
            {
            	if(j!=0)
            	{
            		if(max!=nums[j-1])
	                {
	                    return nums[j-1];
	                }
	                else if(nums[j]==max)
	                {
	                    count++;
	                }
				}
            }
	        if(count==nums.size())
	        {
	            return -1;
	        }
        return temp;
		}
};
int main()
{
	Solution sol;
	vector<int> arr;
	int i,x;
	for(i=0;i<5;i++)
	{
		cout<<"\nEnter number: ";
		cin>>x;
		arr.push_back(x);
	}
	x=sol.seclarnum(arr);
	cout<<x;
}
