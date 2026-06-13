#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid, vector<int>& bloomDay, int m, int k )
{
    int cnt = 0;
    for(int i = 0;i < bloomDay.size();i++)
    {
        if(bloomDay[i] <= mid)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        if(cnt == k)
        {
            m--;
            cnt = 0;
        }
    }

    return m <= 0;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();

    int s = *min_element(bloomDay.begin(),bloomDay.end());
    int e = *max_element(bloomDay.begin(),bloomDay.end());
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,bloomDay,m,k))
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
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout<<minDays(bloomDay,m,k);
    return 0;
}