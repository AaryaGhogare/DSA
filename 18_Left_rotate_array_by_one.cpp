#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) 
    {
        int temp,n,i;
        n = nums.size();
        temp = nums[0];
		
        for(i=1;i<n;i++)
        {
            nums[i-1] = nums[i];
        }
        nums[n-1] = temp;
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
	sol.rotateArrayByOne(array);
	
	printarray(array,n);
}
