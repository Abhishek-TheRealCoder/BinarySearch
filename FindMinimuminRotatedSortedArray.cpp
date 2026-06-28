
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    
    int s = 0;
    int e = n - 1;
    while(s < e)
    {
        int mid = s + (e - s) / 2;
        if(nums[mid] > nums[e])
        {
            s = mid + 1;
        }
        else 
        {
            e = mid;
        }
    }
    return nums[s];
}


int main()
{
    vector<int>arr = {3,4,5,1,2};
    cout<<findMin(arr);
    return 0;
}