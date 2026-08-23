#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  int lowerBound(vector <int> arr,int x)
  {
    int low=0,up=arr.size()-1,mid,ans=arr.size();
    while(low<=up)
    {
      mid=(low+up)/2;
      if(arr[mid]>=x)
      {
        ans=mid;
        up=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    return ans;
  }
  public:   
  int rowWithMax1s(vector < vector < int > > & mat) 
  {
    int i,cnt=0,cntmax=0,index=-1;
    for(i=0;i<mat.size();i++)
    {
      cnt=mat[0].size()-lowerBound(mat[i],1);
      if(cnt>cntmax)
      {
        cntmax=cnt;
        index=i;
      }
    }
    return index;
  }
};
int main()
{
  int m,n,x,i,j;
  cout<<"\nEnter the number of rows and columns for the 2D matrix: ";
  cin>>n>>m;
  vector<vector<int> > matrix(n, vector<int>(m));
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cout<<"\nEnter element to add in the matrix: ";
      cin>>x;
      matrix[i][j]=x;
    }
  }
  int ans;
  Solution sol;
  ans=sol.rowWithMax1s(matrix);
  cout<<"\nMaximum numbers of 1's is in row: "<<ans;
}
