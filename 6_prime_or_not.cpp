#include <iostream>
using namespace std;
class Solution
{
	public:
	    bool isPrime(int n)
	    {
	        // 0 and 1 are not prime
	        if(n <= 1)
	        {
	            return false;
	        }
	
	        for(int i = 2; i < n; i++)
	        {
	            if(n % i == 0)
	            {
	                return false;
	            }
	        }
	
	        return true;
	    }
};

int main()
{
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if(sol.isPrime(n))
    {
        cout << "Prime Number";
    }
    else
    {
        cout << "Not a Prime Number";
    }

    return 0;
}
