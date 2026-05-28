#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i,x,n;
        n = prices.size();
        int mini=prices[i],maxProf=0,cost=0;
        for(i=0;i<n;i++)
        {
          cost = prices[i] - mini;
          maxProf = max(maxProf,cost);
          mini = min(mini,prices[i]);
        }
        return maxProf;
    }
};
int main()
{
  int i,n,x;
  vector <int> arr;
  cout<<"\nEnter the number of elements required: ";
  cin>>n;
  for(i=0;i<n;i++)
  {
    cout<<"\nEnter a number: ";
    cin>>x;
    arr.push_back(x);
  }
  Solution sol;
  int ans;
  ans = sol.maxProfit(arr);
  cout<<"\nProfit is:"<<ans;
  return 0;
}
