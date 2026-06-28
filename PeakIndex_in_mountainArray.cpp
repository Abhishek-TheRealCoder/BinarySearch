#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;

    while(s <= e)
    {
        int mid = s + (e - s)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] >= arr[mid - 1])
        {
            return mid;
        }
        else if(arr[mid] > arr[mid + 1])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0,1,0};
    cout<<peakIndexInMountainArray(arr);
    return 0;
}