#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
       /* BRUTE FORCE APPROACH
	    vector <int> temp;
		int i,d=k;
        int n = nums.size();
        k=k%n;
        
		for(i=n-k;i<n;i++)
		{
			temp.push_back(nums[i]);
		}
		
		
		for(i = k; i>=0;i--)
		{
			nums[i+k]=nums[i];
		}
		for(i=0;i<k;i++)
		{
			nums[i]=temp[i];
			}*/
			
		//OPTIMAL APPROACH
		int n = nums.size();
		k=k%n;
		reverse(nums.end()-k,nums.end());
		reverse(nums.begin(),nums.end()-k);
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
