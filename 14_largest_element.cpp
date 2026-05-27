#include<iostream>
using namespace std;
#include <vector>
class Solution 
{
	public:
    int largestElement(vector<int>& nums) 
    {
        int max=nums[0];
            int i;
            for(i=0;i<nums.size();i++)
            {
                if(nums[i]>max)
                {
                    max=nums[i];
                }
            }
        return max;
    }
};
int main()
{
	Solution sol;
	vector<int> arr;
	int i,x;
	for(i=0;i<5;i++)
	{
		cout<<"\nEnter element: ";
		cin>>x;
		arr.push_back(x);
	}
	x=sol.largestElement(arr);
	cout<<x;
}
