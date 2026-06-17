#include<bits/stdc++.h>
using namespace std;

bool isPoss(long long mid,vector<int>& ranks, int cars)
{   
    long long count = 0;
    for(int i = 0;i < ranks.size();i++)
    {   
        count += sqrt(mid / ranks[i]);
    }

    if(count >= cars) return true;
    return false;
}
long long repairCars(vector<int>& ranks, int cars) {
    int n = ranks.size();
    long  s = 1;
    long  e = 1e9 * cars;
    long long ans = -1;
    while(s <= e)
    {
        long long mid = s + (e - s) / 2;
        if(isPoss(mid,ranks,cars))
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
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    cout<<repairCars(ranks,cars);
    return 0;
}