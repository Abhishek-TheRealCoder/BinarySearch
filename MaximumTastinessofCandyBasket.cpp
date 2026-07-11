#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid,vector<int>&pr,int k)
{
    int cnt = 1;
    int prev = 0;
    for(int i = 1;i < pr.size();i++)
    {
        if(pr[i] - pr[prev] >= mid)
        {
            cnt++;
            prev = i;
        }
    }
    return cnt >= k;
}

int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(),price.end());
    int n = price.size();
    int s = 1;
    int e = *max_element(price.begin(),price.end());

    int ans = 0;

    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,price,k))
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
    vector<int>pr = {13,5,1,8,21,2};
    int k = 3;
    cout << maximumTastiness(pr,k);
    return 0;  
}