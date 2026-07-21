#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  public:
      vector<vector<int> > merge(vector<vector<int> >& intervals) 
      {
        /*int start,end,i,j,n=intervals.size();
        vector<vector<int> > ans;
        sort(intervals.begin(),intervals.end());
        for(i=0;i<n;i++)
        {
          start = intervals[i][0];
          end = intervals[i][1];
          if(!ans.empty() && end<=ans.back()[1])
          {
            continue;
          }
          for(j=i+1;j<n;j++)
          {
            if(intervals[j][0]<=end)
            {
              end=max(end,intervals[j][1]);
            }
            else
            {
              break;
            }
          }
          vector<int> temp;
		  temp.push_back(start);
		  temp.push_back(end);
		  ans.push_back(temp);
        }
         return ans; */

        //OPTIMAL
        int i;
        sort(intervals.begin(),intervals.end());
        vector<vector<int> > ans;
        for(i=0;i<intervals.size();i++)
        {
          if(ans.empty() || ans.back()[1]<intervals[i][0])
          {
            vector <int> temp;
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            ans.push_back(temp);
          }
          else
          {
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
          }
        }
        return ans;
      }
};
int main()
{
   int n,i,j;
    cout << "Enter number of intervals: ";
    cin >> n;
    vector<vector<int> > intervals;
    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        int start;
        cout << "\nEnter start of interval: ";
        cin >> start;
        int end;
        cout << "Enter end of interval: ";
        cin >> end;

        temp.push_back(start);
        temp.push_back(end);

        intervals.push_back(temp);
    }
    Solution sol;
    vector<vector<int> > ans;
    cout << "\nIntervals are:\n";
    ans=sol.merge(intervals);
    for(i=0;i<ans.size();i++)
    {
      cout<<"[";
      for(j=0;j<ans[i].size();j++)
      {
        cout<<" "<<ans[i][j];
        if(j != intervals[i].size()-1)
        {
           cout << ",";
        }
      }
      cout<<"]";
    }
    return 0;
}
