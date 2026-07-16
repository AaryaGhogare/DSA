#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int> > threeSum(vector<int>& nums) 
    {
        /*BRUTE FORCE APROACH
		int i,j,k;
        set <vector<int> > st1;
        for(i=0;i<nums.size();i++)
        {
          for(j=i+1;j<nums.size();j++)
          {
            for(k=j+1;k<nums.size();k++)
            {
              if(nums[i]+nums[j]+nums[k] == 0)
              {
              	vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[j]);
				temp.push_back(nums[k]);
                sort(temp.begin(),temp.end());
                st1.insert(temp);
              }
            }
          }
        }
        vector<vector<int> > ans(st1.begin(),st1.end());
        return ans;*/
        
        /*BETTER APPROACH
		int i,j,third;
        set <vector<int> > st1;
        for(i=0;i<nums.size();i++)
        {
        	set<int> hashset;
        	for(j=i+1;j<nums.size();j++)
        	{
        		third=-(nums[i]+nums[j]);
        		if(hashset.find(third)!=hashset.end())
        		{
        			vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(third);
        			sort(temp.begin(),temp.end());
        			st1.insert(temp);
				}
				hashset.insert(nums[j]);
			}
		}
        vector<vector<int> > ans(st1.begin(),st1.end());
        return ans;*/
        
        //OPTIMAL
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<nums.size();i++)
        {
        	if(i>0 && nums[i] == nums[i-1]) continue;
        	int j = i+1;
        	int k= nums.size()-1;
        	while(j<k)
        	{
        		int sum = nums[i] + nums[j] + nums[k];
        		if(sum < 0)
        		{
        			j++;
				}
				else if(sum > 0)
				{
					k--;
				}
				else 
				{
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					ans.push_back(temp);
					j++;
					k--;
					while(j<k && nums[j] == nums[j-1]) j++;
					while(j<k && nums[k] == nums[k+1]) k--;
					
				}
			}
		}
		return ans;
    }
};
int main()
{
	int n,x,target,i,j;
	vector <int> arr;
	vector<vector<int> > ans;
	cout<<"\nEnter the number of elements required in array: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter a number: ";
		cin>>x;
		arr.push_back(x);
	}
	
	Solution sol;
	ans=sol.threeSum(arr);
	cout<<"\nThe triplets are: ";
	for(i=0;i<ans.size();i++)
	{
		cout<<"[";
		for(j=0;j<3;j++)
		{
			cout<<ans[i][j]<<",";
		}
		cout<<"]";
	}
}
