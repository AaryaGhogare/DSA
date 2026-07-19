#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
      vector<vector<int> > fourSum(vector<int>& nums, int target) 
      {
          /*BRUTE APPROACH
          int i,j,k,m,n;
          n=nums.size();
          set <vector<int> > st1;
          for(i=0;i<n;i++)
          {
            for(j=i+1;j<n;j++)
            {
              for(k=j+1;k<n;k++)
              {
                for(m=k+1;m<n;m++)
                {
                  if(nums[i]+nums[j]+nums[k]+nums[m] == target)
                  {
                    vector <int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[m]);

                    sort(temp.begin(),temp.end());
                    st1.insert(temp);

                  }
                }
              }
            }
          }
        vector <vector<int> > ans(st1.begin(),st1.end());
        return ans;*/

        /*BETTER
				int i,j,k,third;
        set <vector<int> > st1;
        for(i=0;i<nums.size();i++)
        {
        	for(j=i+1;j<nums.size();j++)
        	{
        		set<int> hashset;
	            for(k=j+1;k<nums.size();k++)
	            {
	              int sum = nums[i]+nums[j]+nums[k];
	              int fourth=target - sum;
	              if(hashset.find(fourth)!=hashset.end())
	              {
	                vector<int> temp;
	                temp.push_back(nums[i]);
	                temp.push_back(nums[j]);
	                temp.push_back(nums[k]);
	                temp.push_back(fourth);
	                
	                sort(temp.begin(),temp.end());
	                st1.insert(temp);
	              }
	               hashset.insert(nums[k]);
				}
		    }
	    }
	    vector<vector<int> > ans(st1.begin(),st1.end());
        return ans;*/

				//OPTIMAL APPROACH
				int i,j,k,l;
				vector <vector<int> > ans;
				sort(nums.begin(),nums.end());
				for(i=0;i<nums.size();i++)
				{
					if(i>0 && nums[i] == nums[i-1]) continue;
					for(j=i+1;j<nums.size();j++)
					{
						if(j!=i+1 && nums[j] == nums[j-1])continue;
						k=j+1;
						l=nums.size()-1;
						while(k<l)
						{
							int sum=nums[i]+nums[j]+nums[k]+nums[l];
							if(sum == target)
							{
								vector <int> temp;
								temp.push_back(nums[i]);
								temp.push_back(nums[j]);
								temp.push_back(nums[k]);
								temp.push_back(nums[l]);
								ans.push_back(temp);
								k++;
								l--;
								while(k<l && nums[k]==nums[k-1])k++;
								while(k<l && nums[l]==nums[l+1])l--;
							}
							else if(sum<target)k++;
							else(l--);
						}
					}
				}
				return ans;
      }
};
int main()
{
  int n,x,target,i,j;
	vector<vector<int> >ans;
	vector <int> arr;
	cout<<"\nEnter the number of elements required in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	cout<<"\nEnter the value of target (for sum): ";
	cin>>target;
	Solution sol;
	ans=sol.fourSum(arr,target);
	cout<<"\n4 sum answers: ";
	for(i=0;i<ans.size();i++)
	{
		cout<<"[";
		for(j=0;j<4;j++)
		{
			cout<<ans[i][j]<<",";
		}
		cout<<"]";
	}
}
