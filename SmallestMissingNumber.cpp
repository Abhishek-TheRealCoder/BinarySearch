#include<bits/stdc++.h>
using namespace std;

int findFirstMissing(vector<int> &arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] != mid)
        {
            if(arr[mid] > mid)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}
int main()
{
    vector<int>arr = {0,1,3,4,5};
    cout<<findFirstMissing(arr);
    return 0;
}