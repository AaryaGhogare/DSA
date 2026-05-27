#include<iostream>
using namespace std;
class Solution{
public:
	static int i;
    void reverse(int arr[], int n)
    {
    	int temp=0;
        if(i<=n)
        {
        	temp=arr[n-1];
        	arr[n-1]=arr[i];
        	arr[i]=temp;
        	n--;
        	i++;
        	reverse(arr,n);
		}
    }
};
int Solution::i=0;

int main()
{
	Solution sol;
	int arr[6]={1,2,1,1,5,1};
	sol.reverse(arr,6);
	for(int j=0;j<6;j++)
	{
		cout<<" "<<arr[j];
	}
}
