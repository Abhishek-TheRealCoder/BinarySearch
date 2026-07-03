#include<bits/stdc++.h>
using namespace std;


// 1st Approach 
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(),items.end());     // n log n
    vector<int>res;
    for(int i = 0;i < queries.size();i++)   // m
    {
        int s = 0;
        int e = items.size() - 1;
        int ans = -1;
        while(s <= e)                        // log m
        {
            int mid = s + (e - s) / 2;
            if(items[mid][0] <= queries[i])
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        int maxi = 0;
        for(int j = ans ; j >= 0; j--)           // n
        {
            maxi = max(maxi,items[j][1]);
        }

        res.push_back(maxi);
    }

    return res;
    }
// TC-> m * n

// b) Second Approach 
// we have reduced the extra time we were using to find maximum till that ith index by using dp array to store the maximum till that 
// index and then we can just return the value from dp array instead of iterating again to find the maximum.
vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    int n = items.size();
    int m = queries.size();
    sort(items.begin(),items.end());
    vector<int>res;
    vector<int>dp(n,0);

    dp[0] = items[0][1];
    for(int i = 1;i < n;i++)
    {
        dp[i] = max(dp[i-1],items[i][1]);
    }

    for(int i = 0;i < m ;i++)
    {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e - s) / 2;
            if(items[mid][0] <= queries[i])
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        if(ans == -1) res.push_back(0);
        else res.push_back(dp[ans]);
        
    }

    return res;
}
// Tc-> n log n + m log n                              or we can say                           Tc-> (n + m) log n

int main()
{
    int items[][2] = {
        {1, 2},
        {3, 2},
        {2, 4},
        {5, 6},
        {3, 5}
    };

    int queries[] = {1, 2, 3, 4, 5, 6};
    return  0;
}