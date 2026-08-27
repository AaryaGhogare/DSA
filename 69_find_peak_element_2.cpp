#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  int findMaxInd(vector<vector<int> >& mat,int n,int m,int col)
  {
    int i,maxValue = -1;
    int index = -1;
    for(i=0;i<n;i++)
    {
      if(mat[i][col]>maxValue)
      {
        maxValue = mat[i][col];
        index = i;
      }
    }
    return index;
  }
   public:
     vector<int> findPeakGrid(vector<vector<int> >& mat)
      {
        int n,m,low,up;
        n=mat.size();
        m=mat[0].size();
        low=0,up=m-1;
        vector <int> ans;
        while(low<=up)
        {
          int mid = (low+up)/2;
          int maxRowInd=findMaxInd(mat,n,m,mid);
          int left = mid-1>=0 ? mat[maxRowInd][mid-1] : -1;
          int right = mid+1<m ? mat[maxRowInd][mid+1] : -1;
          if(mat[maxRowInd][mid] > left && mat[maxRowInd][mid]>right)
          {
	        ans.push_back(maxRowInd);
	        ans.push_back(mid);
			return ans;
          }
          else if(mat[maxRowInd][mid]<left)
          {
            up=mid-1;
          }
          else{
            low=mid+1;
          }
        }
        ans.push_back(-1);
        ans.push_back(-1);
		return ans;
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
  vector<int> ans;
  Solution sol;
  ans=sol.findPeakGrid(matrix);
  cout<<"Max Elements are: [";
  for(i=0;i<ans.size();i++)
  {
  	cout<<" "<<ans[i]<<",";
  }
  cout<<"]";
}
