#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      void setZeroes(vector<vector<int> > &matrix) 
      {
      	/*Brute approach
          int m,n,i,j;
          m=matrix.size();
          n=matrix[0].size();
          for(i=0;i<m;i++)
          {
            for(j=0;j<n;j++)
            {
              if(matrix[i][j] == 0)
              {
                markrow(matrix,i);
                markcol(matrix,j);
              }
            }
          }

          for(i=0;i<m;i++)
          {
            for(j=0;j<n;j++)
            {
              if(matrix[i][j] == -1)
              {
                matrix[i][j] =0;
              }
            }
          }

      }

      void markrow(vector<vector<int> >& matrix,int k)
      {
        int i;
        for(i=0;i<matrix[k].size();i++)
        {
          if(matrix[k][i]!=0)
          {
            matrix[k][i]=-1;
          }
        }
      }
      void markcol(vector<vector<int> >& matrix,int k)
      {
        int i;
        for(i=0;i<matrix.size();i++)
        {
          if(matrix[i][k]!=0)
          {
            matrix[i][k]=-1;
          }
        }
      }*/
      
      /*BETTER APPROACH
      int n,m;
      m=matrix.size();
      n=matrix[0].size();
      
      int row[m]={0};
      int col[n]={0};
      
      int i,j;
      
      for(i=0;i<m;i++)
      {
      	for(j=0;j<n;j++)
      	{
      		if(matrix[i][j]==0)
			{
				row[i]=1;
				col[j]=1;	
			}	
		}
	  }
	  
	  for(i=0;i<m;i++)
	  {
	  	for(j=0;j<n;j++)
	  	{
	  		if(row[i] || col[j])
			{
				matrix[i][j]=0;	
			}	
		}
	  }*/
	 //OPTIMAL 
    int col0=1,i,j,n=matrix.size(),m=matrix[0].size();
    for(i=0;i<n;i++)
    {
  	 for(j=0;j<m;j++)
  	 {
  		if(matrix[i][j]==0)
  		{
  			matrix[i][0]=0;
		
			if(j!=0)
			{
				matrix[0][j]=0;
			}
			else
			{
				col0=0;
			}
		}
	}
  }
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(matrix[i][j]!=0)
			{
				if(matrix[i][0] == 0|| matrix[0][j] == 0)
				{
					matrix[i][j]=0;
				}
			}
		}
	}
	if(matrix[0][0] == 0)
	{
		for(j=0;j<m;j++)
		{
			matrix[0][j]=0;
		}
	}
	if(col0==0)
	{
		for(int i =0;i<n;i++)
		{
			matrix[i][0] = 0;
		}
	}
	
	  
      
  }
};

void printArray(vector<vector<int> > arr,int m,int n)
{
  int i,j;

  for(i=0;i<m;i++)
  {
    cout<<endl;
    for(j=0;j<n;j++)
    {
      cout<<arr[i][j];
    }
  }
}
int main()
{
	int m,n,i,j;
	cout<<"\nEnter the number of rows to be included in array: ";
	cin>>m;
  cout<<"\nEnter the number of columns to be included in array: ";
	cin>>n;
	vector<vector<int> > arr(m, vector<int>(n));
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      cout<<"\nEnter a number to add: \n";
      cin>>arr[i][j];
    }
  }

  cout<<endl<<endl;

  printArray(arr,m,n);
  Solution sol;
	sol.setZeroes(arr);
	cout<<endl;
	printArray(arr,m,n);
}
