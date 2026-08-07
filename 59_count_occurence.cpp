#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  int lowerBound(vector<int>& arr, int target)
  {
    int low,mid,up,ans=-1;
    up=arr.size()-1;
    low=0;
    while(low<=up)
    {
      mid=(low+up)/2;
      if(arr[mid]==target)
      {
        ans=mid;
        up=mid-1;
      }
      else if(arr[mid]>target)
      {
        up=mid-1;
      }
      else
      {
        low=mid+1;
      }
    }
    return ans;
  }
  int upperBound(vector<int>& arr, int target)
  {
    int low,mid,up,ans=-1;
    up=arr.size()-1;
    low=0;
    while(low<=up)
    {
      mid=(low+up)/2;
      if(arr[mid]==target)
      {
        ans=mid;
        low=mid+1;
      }
      else if(arr[mid]>target)
      {
        up=mid-1;
      }
      else
      {
        low=mid+1;
      }
    }
    return ans;
  }
  public:
      int countOccurrences(vector<int>& arr, int target) 
      {
        int lb,ub;
        lb=lowerBound(arr,target);
        if(lb==-1 || arr[lb]!=target)
        {
          return -1;
        }
        ub=(upperBound(arr,target));
        return (ub-lb)+1;
      }
};
int main()
{
  int ans;
  int n,x,i;
	vector <int> arr;
	cout<<"\nEnter the number of elements to add: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
  cout<<"\nEnter the target x: ";
  cin>>x;
	Solution sol;
	ans=sol.countOccurrences(arr,x);
  cout<<"\nThe occurence of "<<x<<" is: "<<ans;
}
