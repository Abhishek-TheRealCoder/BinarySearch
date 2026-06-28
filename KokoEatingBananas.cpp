#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid,vector<int>& piles, int h)
{
    long time = 0;
    for(int i = 0;i < piles.size();i++)
    {
        if(piles[i] < mid)
        {
            time++;
        }
        else
        {
            time += ceil(1.0 * piles[i] / mid );
        }
    }

    return time <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int s = 1;
    int e = *max_element(piles.begin(),piles.end());

    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,piles,h))
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
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<minEatingSpeed(piles,h);
    return 0;
}