#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;
class Solution 
{
  public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        /*BRUTE
        int i,count,j;
        vector <int> list;
        for(i=0;i<nums.size();i++)
        {
          if(list.size()==0 || list[0]!=nums[i])
          {
            count =0;
            for(j=0;j<nums.size();j++)
            {
              if(nums[i]==nums[j])
              {
                count++;
              }
            }
            if(count > nums.size()/3)
            {
            	if(list.size()==nums.size()/3)
            	{
            		break;
				}
               list.push_back(nums[i]);  
            }
          }
        }
        
        return list;
		*/
      /*BETTER
      int i,count;
      vector <int> list;
      map <int,int> mpp;

      int n= nums.size();
      int minicount= (n/3)+1;

      for(i=0;i<n;i++)
      {
        mpp[nums[i]]++;
        if(mpp[nums[i]] == minicount)
        {
          if(list.size()==nums.size()/3)
          {
            break;
          }
          list.push_back(nums[i]);
        }
      }
      return list;*/

      int cnt1=0,cnt2=0,el1,el2,i;
      el1 = INT_MIN;
      el2 = INT_MIN;
      vector <int> list;

      for(i=0; i<nums.size();i++)
      {
        if(cnt1 ==0 && el2!=nums[i])
        {
          cnt1 = 1;
          el1=nums[i];
        }
        else if(cnt2 ==0 && el1!=nums[i])
        {
          cnt2 = 1;
          el2=nums[i];
        }
        else if(nums[i]==el1)
        {
          cnt1++;
        }
        else if(nums[i]==el2)
        {
          cnt2++;
        }
        else
        {
          cnt1--;
          cnt2--;
        }
      }
      cnt1=0;
      cnt2=0;
      for(i=0;i<nums.size();i++)
      {
        if(el1==nums[i])cnt1++;
        if(el2==nums[i])cnt2++;
      }
      int minicount = (int)(nums.size()/3+1);
      if(cnt1>=minicount)list.push_back(el1);
      if(cnt2>=minicount)list.push_back(el2);
      return list;
    }
};
int main()
{
 int n,i,x;
	cout<<"\nEnter the number of elements required in array: ";
	cin>>n;
	vector <int> arr;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	Solution sol;
	vector <int> ans;
	ans=sol.majorityElement(arr);
	cout<<"\nThe Majority occuring numbers are: ";
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
