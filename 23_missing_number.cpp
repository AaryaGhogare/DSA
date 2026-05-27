#include <iostream>
#include <vector>
using namespace std;
class Solution
{
	public:
	int missing_num(vector<int> & nums)
	{
		/*BRUTE APPROACH
	    int found;
	
	    for(int i=0;i<nums.size();i++)
	    {
	        found=0;
	        for(int j=0;j<nums.size();j++)
	        {
	            if(nums[j]==i)
	            {
	                found=1;
	                break;
	            }
	        }
	        if(found==0)
            {
                return i;
            }
    	}*/
    	
    	/*BETTER
		int *hasharr = new int[nums.size()+1];

	    for(int i = 0; i <= nums.size(); i++)
	    {
	        hasharr[i] = 0;
	    }
	
	    for(int i = 0; i < nums.size(); i++)
	    {
	        hasharr[nums[i]] = 1;
	    }
	
	    for(int j = 0; j <= nums.size(); j++)
	    {
	        if(hasharr[j] == 0)
	        {
	            return j;
	        }
	    }
	    return -1;*/
	    
	    //OPTIMAL
	    int n = nums.size();
	    int expected_sum = n * (n + 1) / 2;
	
	    int addition = 0;
	
	    for(int i = 0; i < nums.size(); i++)
	    {
	        addition = addition + nums[i];
	    }
	    return expected_sum - addition;
    }
};

int main()
{
    vector <int> nums;
	int i,n,x;
	cout<<"\nEnter the number of elements required: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the number: ";
		cin>>x;
		nums.push_back(x);
	}
	Solution sol;
    int ans=sol.missing_num(nums);
    cout<<"\nMissing num="<<ans;

    return 0;
}
