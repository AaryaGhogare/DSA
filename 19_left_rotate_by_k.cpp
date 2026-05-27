#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
	public:
    	void rotate(vector<int>& nums, int k) 
		{
			/*BRUTE
			vector <int> temp;
			int i;
			int n = nums.size();
			k=k%n;
			for(i=0;i<k;i++)
			{
				temp.push_back(nums[i]);
			}
			for(i = k; i<n;i++)
			{
				nums[i-k]=nums[i];
			}
			for(i=n-k;i<n;i++)
			{
				nums[i]=temp[i-(n-k)];
			}*/
			
			//OPTIMAL
			int n = nums.size();
			reverse(nums.begin(),nums.begin()+k);
			reverse(nums.begin()+k,nums.end());
			reverse(nums.begin(),nums.end());
			
    	}
};
void printarray(vector<int> nums,int n)
{
	int i;
	cout<<"\nAfter rotation: \n";
	for(i=0;i<n;i++)
	{
		cout<<nums[i]<<" ";
	}
}
int main()
{
	int k,n,i,x;
	
	cout<<"\nEnter the number of elements- ";
	cin>>n;
	vector<int> arr;
	cout<<"\nEnter the elements of array: ";
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter number: ";
		cin>>x;
		arr.push_back(x);
	}
	
	cout<<"\nEnter the number to rotate array through: ";
	cin>>k;
	
	Solution sol;
	sol.rotate(arr,k);
	
	printarray(arr,n);
}
