#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void printArray(vector<vector<int> > arr,int m,int n)
{
  int i,j;
  
  cout<<endl<<endl;
  

  for(i=0;i<m;i++)
  {
    cout<<endl;
    for(j=0;j<n;j++)
    {
      cout<<arr[i][j]<<"  ";
    }
  }
}
class Solution 
{
	public:
	    void rotate(vector<vector<int> >& matrix) 
		{
	        //BRUTE FORCE APPROACH
	        /*int m=matrix.size();
	        int n=matrix[0].size();
	        
	        vector<vector<int> > arr(m, vector<int>(n));
	        
	        int i,j;
	        for(i=0;i<m;i++)
	        {
	        	for(j=0;j<n;j++)
	        	{
	        		arr[j][(m-1)-i]=matrix[i][j];
				}
			}
			
			printArray(arr,m,n);
	        */
	        
	        //Optima; approach
	        int m=matrix.size();
	        int i,j;
	        
	        for(i=0;i<m-1;i++)
	        {
	        	for(j=i+1;j<m;j++)
	        	{
	        		swap(matrix[i][j],matrix[j][i]);
				}
			}
			
			//reversing
			for(i=0;i<m;i++)
			{
				reverse(matrix[i].begin(),matrix[i].end());
			}
			
	
	    }
};


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

  
	printArray(arr,m,n);
	Solution sol;
	sol.rotate(arr);
	printArray(arr,m,n);
	
}