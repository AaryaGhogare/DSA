#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
   public:
     bool searchMatrix(vector<vector<int> >& matrix, int target)
      {
        int low,up,mid,n=matrix[0].size(),m=matrix.size();
        low=0;
        up=(n*m)-1;
        while(low<=up)
        {
          mid=(low+up)/2;
          if(target == matrix[mid/n][mid%n])
          {
            return true;
          }
          else if(target < matrix[mid/n][mid%n])
          {
            up=mid-1;
          }
          else
          {
            low=mid+1;
          }
        }
        return false;
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
  cout<<"\nEnter the target element to search: ";
  cin>>x;
  bool ans;
  Solution sol;
  ans=sol.searchMatrix(matrix,x);
  cout<<"\nTarget present: "<<ans;
}
