#include<bits/stdc++.h>
using namespace std;


vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
    int n = people.size();
    int m = flowers.size();
    vector<int>start(m,0);
    vector<int>end(m,0);
    for(int i = 0;i < m;i++)
    {
        start[i] = flowers[i][0];
        end[i] = flowers[i][1];
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    vector<int>ans;
    for(int i = 0;i < n;i++)
    {
        int arrived = people[i];
        int flower_bloom_by_arrival = upper_bound(start.begin(),start.end(),arrived) - start.begin(); 
        int flower_die_before_arrival = lower_bound(end.begin(),end.end(),arrived) - end.begin();
        int num_of_Flower_ith_sees = flower_bloom_by_arrival - flower_die_before_arrival;

        ans.emplace_back(num_of_Flower_ith_sees);
    }
    return ans;
}


int main()
{
    vector<vector<int>> flowers = {
        {1, 6},
        {3, 7},
        {9, 12},
        {4, 13}
    };

    vector<int> people = {2, 3, 7, 11};
    vector<int> result = fullBloomFlowers(flowers, people);
    for (int count : result) {
        cout << count << " ";
    }
    return 0;
}