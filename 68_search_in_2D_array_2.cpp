#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
   public:
     bool searchMatrix(vector<vector<int> >& matrix, int target)
      {
        int row=0,col,n;
        n=matrix.size();
        col=matrix[0].size()-1;
        while(row<n && col>=0)
        {
          if(target == matrix[row][col])
          {
            return true;
          }
          else if(target < matrix[row][col])
          {
            col--;
          }
          else
          {
            row++;
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
