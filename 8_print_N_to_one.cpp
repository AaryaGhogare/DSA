#include<iostream>
using namespace std;
class Solution 
{
  public:
    void printNumbers(int n) 
    {
        if(n!=0)
        {
        	cout<<n<<"\n";
            n--;
            printNumbers(n);
        }
    }
};
int main()
{
	int x;
	cout<<"\nEnter a number: ";
	cin>>x;
	Solution sol;
	sol.printNumbers(x);
}
