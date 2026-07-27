#include<iostream>
#include<vector> 
using namespace std;
void merge(vector <int>& num,int low,int mid,int up)
{
	int *result;
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
}
int countPairs(vector<int>&nums ,int low,int mid,int up)
{
  int right = mid+1;
  int cnt=0,i;
  for(i=low;i<=mid;i++)
  {
    while(right <=up && nums[i] > 2*nums[right])
    {
      right++;
    }
    cnt = cnt + (right - (mid+1));
  }
  return cnt;
}
int mergesort(vector <int>& nums,int low,int up)
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
		cnt=cnt + mergesort(nums,low,mid);
		cnt=cnt + mergesort(nums,mid+1,up);
    cnt=cnt+countPairs(nums,low,mid,up);
		merge(nums,low,mid,up);
		return cnt;
	}
}
class Solution 
{
  public:
      int reversePairs(vector<int>& nums) 
      {
        /*BRUTE APPROACH
        int i,j,n,cnt=0;
        n=nums.size();
        for(i=0;i<n;i++)
        {
          for(j=i+1;j<n;j++)
          {
            if(nums[i]>nums[j]*2)
            {
              cnt++;
            }
          }
        }
        return cnt;*/
        int n= nums.size()-1;
        return mergesort(nums,0,n);
      }
};
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
	ans=sol.reversePairs(arr);
	cout<<"\nThe count of pairs is: "<<ans;
}
