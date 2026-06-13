#include <bits/stdc++.h>
using namespace std;

bool isPoss(int mid , vector<int>&arr, int k)
{
    int sum = 0;
    for(int i = 0;i < arr.size(); i++)
    {
        sum += ceil(1.0 * arr[i] / mid);
    }

    return (sum <= k ? true : false);
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int s = 1;
    int e = *max_element(nums.begin(),nums.end());

    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,nums,threshold))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout<<smallestDivisor(nums,threshold);
    return 0;
}