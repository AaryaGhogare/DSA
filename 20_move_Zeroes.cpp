#include<iostream>
using namespace std;
#include<vector>
class Solution 
{
	public:
	    void moveZeroes(vector<int>& nums) 
	    {
	    	int i=0,j,n;
	    	n=nums.size();
	        for(j=0;j<n;j++)
	        {
	        	if(nums[j]!=0)
	        	{
	        		swap(nums[i],nums[j]);
	        		i++;
				}
			}
	        
	    }
	    
};

int main()
{
	vector<int> array;
	int n,x,i;
	cout<<"\nEnter the number of elements to be included in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number to add: \n";
		cin>>x;
		array.push_back(x);
	}
	
	Solution sol;
	sol.moveZeroes(array);

}
