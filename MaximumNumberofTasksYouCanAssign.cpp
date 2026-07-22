#include<bits/stdc++.h>
using namespace std;

bool isPoss(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength)
{
    multiset<int>s(workers.begin(), workers.begin() + mid);

    for(int i = mid - 1; i >= 0; i--)
    {
        int req = tasks[i];
        auto it = prev(s.end());

        if(*it >= req)
        {
            s.erase(it);
        }
        else if(pills <= 0) 
        {
            return false;
        }
        else
        {
            int need = req - strength;
            auto weakest = s.lower_bound(need);
            if(weakest == s.end()) return false;
            s.erase(weakest);
            pills--;
        }
    }
    return true;
}

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
{
    sort(tasks.begin(),tasks.end());
    sort(workers.rbegin(),workers.rend());
    int n = workers.size();
    int m = tasks.size();
    int s = 0;
    int e = min(n,m);

    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(isPoss( mid , tasks , workers , pills , strength ))
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
    vector<int>tasks = {5,8,9,5,9};
    vector<int>workers = {2,1,6,4,6};
    int pill = 1;
    int strength = 5;
    cout << maxTaskAssign( tasks , workers , pill , strength );
    return 0;
}