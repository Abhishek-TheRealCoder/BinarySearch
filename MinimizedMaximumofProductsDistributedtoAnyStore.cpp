
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid, int n, vector<int>& arr)
{
    int cnt = 0;
    for(auto x : arr)
    {
        cnt += ceil(1.0 * x / mid);
    }
    if(cnt <= n) return true;
    return false;
}
int minimizedMaximum(int n, vector<int>& quant) {
    int s = 1;
    int e = *max_element(quant.begin(),quant.end());
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss(mid,n,quant))
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
    int n = 6;
    vector<int> quant = {11,6};
    cout<<minimizedMaximum(n,quant);
    return 0;
}