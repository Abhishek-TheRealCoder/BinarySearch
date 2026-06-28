#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int target) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    if(ans == -1) return n;
    return ans;
}
int main()
{
    vector<int> arr = {1,3,5,6};
    int target = 7;
    cout<<searchInsert(arr,target);
    return 0;
}