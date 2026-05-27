#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // Negative numbers are not palindrome
        if(x < 0)
        {
            return false;
        }

        int original = x;
        int rev = 0;

        while(x != 0)
        {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        if(original == rev)
        {
            return true;
        }

        return false;
    }
};
int main()
{
	int n;
	bool palin;
	cout<<"\nEnter a Number to check if Plaindrome or not: ";
	cin>>n;
	Solution sol;
	palin=sol.isPalindrome(n);
	cout<<"\n "<<palin;
	return 0;
}
