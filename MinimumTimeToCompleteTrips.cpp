#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll mid, vector<int>&time,int totalTrips)
{
    ll sum = 0;
    for(auto x : time)
    {
        sum += mid/x;
    }
    if(sum >= totalTrips) return true;
    return false;
}
long long minimumTime(vector<int>& time, int totalTrips) {
    int n = time.size();
    ll s = 1;
    ll e = (ll) * min_element(time.begin(),time.end()) * totalTrips;

    while(s < e)
    {
        ll mid = s + (e - s) / 2;
        if(isPossible(mid,time,totalTrips))
        {
            e = mid;
        }
        else
        {
            s = mid  + 1;
        }
    }
    return e;
}
int main()
{
    vector<int> time = {1,2,3};
    int totalTrips = 5;
    cout<<minimumTime(time,totalTrips);
    return 0;
}