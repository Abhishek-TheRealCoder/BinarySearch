#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        int missingElem = arr[mid] - (mid + 1);
        if(missingElem < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s + k;
}
int main()
{
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout<<findKthPositive(arr,k);
    return 0;
}