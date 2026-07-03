#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr) 
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while(s < e)
    {
        int mid = s + (e - s) / 2 ;
        bool isEven = (e - mid) % 2 == 0 ? true : false;

        if(arr[mid] == arr[mid + 1])
        {
            if(isEven)
            {
                s = mid + 2;
            }
            else
            {
                e = mid - 1;
            }
        }
        else // arr[mid] != arr[mid + 1]
        {
            if(isEven)
            {
                e = mid ;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    return arr[s];
}
int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(nums);
    return 0;
}