#include<iostream>
using namespace std;
#include<vector>
class Solution 
{
  public:
      vector<int> rearrangeArray(vector<int>& nums) 
      {
          /*
		  BRUTE FORCE APPROACH
		  vector <int> pos;
          vector <int> neg;
          int i,n;
          n = nums.size();
          for(i=0;i<n;i++)
          {
            if(nums[i] > 0)
            {
              pos.push_back(nums[i]);
            }
            else
            {
              neg.push_back(nums[i]);
            }
          }
          for(i=0;i<n/2;i++)
          {
            nums[2*i] = pos[i];
            nums[(2*i)+1] = neg[i];
          }
          return nums;*/
          
          //OPTIMAL
          vector <int> temp;
          int i,n,pos=0,neg=1;
          n = nums.size();
          for(i=0;i<n;i++)
          {
          	temp.push_back(0);
		  }
          for(i=0;i<n;i++)
          {
          	if(nums[i] < 0)
          	{
          		temp[neg] = nums[i];
          		neg = neg + 2;
			}
			else
          	{
          		temp[pos] = nums[i];
          		pos = pos + 2;
			}
		  }
		  return temp;
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
	vector <int> ans;
	Solution sol;
	ans=sol.rearrangeArray(array);
	for(i=0;i<ans.size();i++)
	{
		cout<<" "<<ans[i];
	}
}
