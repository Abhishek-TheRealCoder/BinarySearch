
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid,vector<int> &stalls, int k)
{
    int last = stalls[0];
    int cnt = 1;
    
    for(int i = 1; i < stalls.size();i++)
    {
        if(mid <= stalls[i] - last)
        {
            cnt++;
            last = stalls[i];
        }
    }
    if(cnt >= k) return true;
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int s = 1;
    int e = stalls[n-1] - stalls[0];
    
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,stalls,k))
        {
            ans = mid;
            s = mid + 1;        // because we are calculating min distance
                                // if suppose mid = 1 then cnt will be more than k
                                // so we need to decrease the cnt
                                // therefore we will have to increase the search space
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
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout<<aggressiveCows(stalls,k);
    return 0;
}