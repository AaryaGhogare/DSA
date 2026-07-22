#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution 
{
  private:
  void swapGreater(vector<int>& nums1,vector<int>& nums2,int ind1, int ind2)
  {
    if(nums1[ind1] > nums2[ind2])
    {
      swap(nums1[ind1],nums2[ind2]);
    }
  }
  public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
      {
        //OPTIMAL 1 (two pointer approach)
        int i;
        int left = m-1;
        int right = 0;
        while(left>=0 && right < n)
        {
          if(nums1[left]>nums2[right])
          {
            swap(nums1[left],nums2[right]);
            left--;
            right++;
          }
          else{
            break;
          }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(i=0;i<n;i++)
        {
          nums1[m+i]=nums2[i];
          nums2[i]=0;
        }
        /*OPTIMAL 2 (Shell Sort/Gap Method)
        int i;
        int len = m+n;
        int gap = (len/2) + (len%2);
        while(gap>0)
        {
          int left = 0;
          int right = left + gap;
          while(right<len)
          {
            //left and right are in nums1 and nums2
            if(left < m && right >=m)
            {
              swapGreater(nums1,nums2,left,right-m);
            }
            //left and right are in nums2
            else if(left >= m)
            {
              swapGreater(nums2,nums2,left-m,right-m);
            }
            else
            {
              swapGreater(nums1,nums1,left,right);
            }
            left++;
            right++;
          }
          if(gap==1)break;
          gap = (gap + 1) / 2;
        }
        for(i = 0; i < n; i++)
        {
            nums1.push_back(nums2[i]);
        }*/
        for(i=0;i<m+n;i++)
        {
          cout<<" "<<nums1[i];
        }
      }
};
int main()
{
  int i,n,j,x;
  vector <int> arr1,arr2;
  for(i=0;i<2;i++)
  {
    cout<<"Enter the number of elements in array "<<i+1<<":";
    cin>>n;
    for(j=0;j<n;j++)
    {
      cout<<"\nEnter the array element: ";
      cin>>x;
      if(i==0)
      {
        arr1.push_back(x);
      }
      else{
        arr2.push_back(x);
      }
    }
  }
  Solution sol;
  sol.merge(arr1,arr1.size(),arr2,arr2.size());
  return 0;
}
