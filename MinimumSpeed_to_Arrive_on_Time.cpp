#include <bits/stdc++.h>
using namespace std;

bool isPoss(int speed, vector<int>& dist, double hour)
{
    int n = dist.size();
    double sum = 0;
    for(int i = 0; i < n - 1;i++)
    {
        sum += ceil(1.0 * dist[i] / speed );
    }
    sum += (double)dist[n-1] / speed;

    if(sum <= hour) return true;
    return false;
}

int minSpeedOnTime(vector<int>& dist, double hour) {

    int n = dist.size();

    if(hour <= n - 1)
        return -1;

    int s = 1;
    int e = 1e7;

    int ans = -1;

    while(s <= e)
    {
        int mid = s + (e - s) / 2;

        if(isPoss(mid, dist, hour))
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
    vector<int> dist = {1, 3, 2};
    double hour = 6;
    return 0;
}