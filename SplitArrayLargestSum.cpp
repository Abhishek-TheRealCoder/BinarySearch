// Problem is also knon as Painter's Partition Problem or Book Allocation Problem

#include <bits/stdc++.h>
using namespace std;

bool isPoss(int mid,vector<int>& arr, int k)
{
    int sum = 0;
    int cnt =  1;
    for(int i = 0;i < arr.size();i++)
    {
        if(sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            cnt++;
            sum = arr[i];
        }
    }
    if(cnt <= k) return true;
    return false;
}
int splitArray(vector<int>& arr, int k) {
    int n = arr.size();
    int s = *max_element(arr.begin(),arr.end());
    int e = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,arr,k))
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
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout<<splitArray(nums,k);
    return 0;
}