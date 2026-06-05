#include<bits/stdc++.h>
using namespace std;

int bs(int s, int e, vector<int>& arr , int target)
{
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
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


int search(vector<int>&arr, int k)
{
    int n = arr.size();
    return bs(0,n-1,arr,k);
}
int main()
{
    vector<int>arr = {1,2,3,5,6,7,8,9,10,11,12,13,14,15};
    int target = 10;
    cout<<search(arr,target);
    return 0;
}