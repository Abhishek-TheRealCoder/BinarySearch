#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid, vector<int>&arr, int days, int n)
{
    int cnt = days - 1;
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        if(sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {   
            sum = 0;
            cnt--;
            sum += arr[i];
        }   
    }

    if(cnt >= 0) return true;
    return false;
}
int shipWithinDays(vector<int>& weights, int days) {
    
    int n = weights.size();
    int s = *max_element(weights.begin(), weights.end()); // minimum capacity of the ship should be atleast the maximum weight in the weights array
    int e = accumulate(weights.begin(), weights.end(),0); // maximum capacity of the ship can be the sum of all the weights in the weights array
    int ans = -1;
    while(s <= e)
    {
        int mid = s  + (e - s) / 2;
        if(isPoss(mid,weights,days,n))
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
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout<<shipWithinDays(weights,days);
    return 0;
}
