#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int n = nums1.size();
    int m = nums2.size();
    if(n > m)
    {
        return findMedianSortedArrays(nums2,nums1); // we do BS on Shorter array
    }

    int low = 0;
    int high = n;
    int N = (n + m + 1) / 2 ; // (TotalSize + 1 ) / 2 gives total elements that will be placed in left half and rest on right half

    while(low <= high)
    {
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        int mid = low + (high - low) / 2; // we will do BS on nums1 array and find mid index of nums1 array
        int mid2 = N - mid;

        if(mid > 0) l1 = nums1[mid - 1];
        if(mid2 > 0) l2 = nums2[mid2 - 1];
        if(mid < n) r1 = nums1[mid];
        if(mid2 < m) r2 = nums2[mid2];

        if(l1 <= r2 && l2 <= r1)
        {
            if((n + m) % 2 == 0) // even num of elements total
            {
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            }
            else
            {
                return max(l1,l2);
            }
        }

        if(l1 > r2) high = mid - 1;
        else low = mid + 1;
    }
    return 0.0;
}
int main()
{
    vector<int> nums1 = {1,3,9};
    vector<int> nums2 = {2,4,5,6,7,8};
    cout<<findMedianSortedArrays(nums1,nums2);
    return 0;
}