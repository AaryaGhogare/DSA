#include<iostream>
#include<vector>
using namespace std;
int mergesort(vector <int>& num,int low,int up);
class Solution 
{
  public:
    long long int numberOfInversions(vector<int>& nums) 
    {
    	/*BRUTE APPROACH
    	int i,j,cnt=0;
    	for(i=0;i<nums.size();i++)
    	{
    		for(j=i+1;j<nums.size();j++)
    		{
    			if(nums[i]>nums[j])
    			{
    				cnt++;
				}
			}
		}
		return cnt;*/
    	int n=nums.size();
		return mergesort(nums,0,n-1);
    }
};
int merge(vector <int>& num,int low,int mid,int up)
{
	int *result,cnt=0;
	result=new int[up-low+1];
	int i,j,k;
	i=low;
	j=mid+1;
	k=0;
	
	while(i<=mid && j<=up)
	{
		if(num[i]<=num[j])
		{
			result[k]=num[i];
			k++;
			i++;
		}
		else
		{
			result[k]=num[j];
      cnt = cnt + (mid-i+1);
			k++;
			j++;
		}
		
	}
	while(i<=mid)
	{
		result[k]=num[i];
		k++;
		i++;
	}
	while(j<=up)
	{
		result[k]=num[j];
		k++;
		j++;
	}
	k=0;
	for(i=low;i<=up;i++)
	{
		num[i]=result[k];
		k++;
	}
  return cnt;
}
int mergesort(vector <int>& num,int low,int up)
{
  int cnt=0;
	if(low>=up)
	{
		return cnt;
	}
	else
	{
		int mid;
		mid=(low+up)/2;
		cnt=cnt + mergesort(num,low,mid);
		cnt=cnt + mergesort(num,mid+1,up);
		cnt=cnt + merge(num,low,mid,up);
	}
	return cnt;
}
int main()
{
	vector <int> num;
  int n,x,i;
	vector <int> arr;
  int ans;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	Solution sol;
	ans=sol.numberOfInversions(arr);
	cout<<"\nThe count of inversions is: "<<ans;
}
