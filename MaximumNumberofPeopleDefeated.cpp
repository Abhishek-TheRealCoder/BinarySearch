#include<bits/stdc++.h>
using namespace std;

bool isPoss(long long mid,int p )
{
    long long sum = (mid)*(mid + 1)*(mid*2 + 1) / 6;
    return sum <= p;
}
int maxPeopleDefeated(int p) {
    long long s = 0;
    long long e = sqrt(p) + 1;
    int ans = 0;
    while(s <= e)
    {
        long long mid = s  + (e - s) /2 ;
        if(isPoss(mid,p))
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
    int p = 14;
    cout<<maxPeopleDefeated(p);
    return 0;
}