#include<iostream>
#include<vector>
using namespace std;
class Solution 
{
  public:
      vector<vector<int> > generate(int numRows) 
      {
        int i,j,res=1;
        vector<vector<int> > arr;
        for(int row = 0; row < numRows; row++)
        {
            vector<int> temp;
            int res = 1;

            for(int col = 0; col <= row; col++)
            {
                temp.push_back(res);

                res = res * (row - col);
                res = res / (col + 1);
            }

            arr.push_back(temp);
        }

        return arr;
      }
};
int main()
{
  int m,n,i,j;
	cout<<"\nEnter the number of rows to be included in pascal's triangle: ";
	cin>>m;
  cout<<endl<<endl;
  Solution sol;
  vector<vector<int> > arr;
	arr = sol.generate(m);
	cout<<endl;
	for(int i = 0; i < arr.size(); i++)
	{
	    cout << endl;
	
	    for(int j = 0; j < arr[i].size(); j++)
	    {
	        cout << arr[i][j] << " ";
	    }
	}
}
