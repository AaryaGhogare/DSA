#include<iostream>
using namespace std;
#include<string>
#include <ctype.h>
class Solution 
{
public:
   bool isPalindrome(string s) 
    {
        int count=0,countofalpha=0;
        int j=s.length()-1,i=0;
        while(i<=j)
        {
            if(isalnum(s[i]) && isalnum(s[j]))
            {
                countofalpha=countofalpha + 2;
                if(isalpha(s[i]) && isalpha(s[j]))
                {
                    s[i]=(char)std::tolower(s[i]);
                    s[j]=(char)std::tolower(s[j]);
                }
                if(s[i]==s[j])
                {
                    count++;
                }  
                j--;
                i++;
            }
            else if(!isalnum(s[i]))
            {
                i++;
            }
            else if(!isalnum(s[j]))
            {
                j--;
            }
        }
        
        if(count==((countofalpha)/2))
        {
            return true;
        }
        return false;
    }
};
int main()
{
	string str;
	cout<<"\nEnter a String to check if plaindrome: ";
	getline(cin,str);
	
	Solution sol;
	bool ch;
	ch=sol.isPalindrome(str);
	
	cout<<" "<<ch;
}
