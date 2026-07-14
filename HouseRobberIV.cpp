#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid, vector<int>& nums, int k)
{
    int cnt = 0;
    for(int i = 0;i < nums.size();i++)
    {
        if(nums[i] <= mid)
        {
            cnt++;
            i++;
        }
    }
    return cnt >= k;
}
int minCapability(vector<int>& nums, int k) {
    int n = nums.size();
    int s = *min_element(nums.begin(),nums.end());
    int e = *max_element(nums.begin(),nums.end());

    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,nums,k))
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
    vector<int>arr = {2,3,5,9};
    int k = 2;
    cout << minCapability(nums,k);
    return 0;
}