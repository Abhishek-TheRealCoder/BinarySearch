// same question as Aggressive cows problem
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid,vector<int>&pos,int m)
{
    int prev = 0;
    int cnt = 1;
    for(int i = 1; i < pos.size();i++)
    {
        if(pos[i] - pos[prev] >= mid)
        {
            prev = i;
            cnt++;
        }
    }

    if(cnt >= m) return true;
    return false;
}

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(position.begin(),position.end());
    int s = 1;
    int e = *max_element(position.begin(),position.end());
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s)/2;
        if(isPoss(mid,position,m))
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
    vector<int>pos = {1,2,3,4,7};
    int m = 3;
    cout << maxDistance(pos,m);
    return 0;
}