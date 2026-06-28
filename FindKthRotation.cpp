#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while(s < e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] > arr[e])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s - 0;
}

int main()
{
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    cout<<findKRotation(arr);
    return 0;
}