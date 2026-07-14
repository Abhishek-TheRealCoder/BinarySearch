#include<bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
{
    int n = profit.size();
    priority_queue<pair<int,int>>pq;
    for(int i = 0;i < n;i++)
    {
        pq.push(make_pair(profit[i],difficulty[i]));
    }
        
    int sum = 0;
    sort(worker.rbegin(),worker.rend());
    for(int i = 0;i < worker.size();i++)
    {
        while(worker[i] < pq.top().second && !pq.empty())
        {    
            pq.pop(); 
        }
        if(worker[i] >= pq.top().second) sum += pq.top().first;
    }

    return sum;
}

int main()
{
    vector<int> diff = {2,4,6,8,10};
    vector<int> prof = {10,20,30,40,50};
    vector<int> work = {4,5,6,7};

    cout<<maxProfitAssignment(diff,prof,work);
    return 0;
}