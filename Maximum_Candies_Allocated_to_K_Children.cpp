#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid, vector<int>& cand, long long k)
{
    long long cnt = 0;
    long long store = 0;
    for(int i = 0;i < cand.size();i++)
    {
        store = cand[i] / mid;
        cnt = cnt + store;
    }

    if(cnt >= k) return true;
    return false;
}
int maximumCandies(vector<int>& cand, long long k) {
    
    int s = 1;
    int e = *max_element(cand.begin(),cand.end());
    int ans = 0;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,cand,k))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5,8,6};
    int k = 3;
    cout<<maximumCandies(arr,k);
    return 0;
}