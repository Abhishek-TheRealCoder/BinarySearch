#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int s,int e, int k , vector<int>& arr)
{
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > k)
        {
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int lastOccurence(int s,int e, int k , vector<int>& arr)
{
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;
        if(arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > k)
        {
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;


}
vector<int> searchRange(vector<int>& nums, int target) {
    
    int n = nums.size();
    int firstIdx = firstOccurence(0,n-1,target,nums);
    int lastIdx = lastOccurence(0,n-1,target,nums);
    return {firstIdx,lastIdx};
}


int main()
{
    vector<int> arr = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(arr,target);
    cout << "First and Last Occurence of " << target << " is at index: " << ans[0] << " and " << ans[1] << endl;
    return 0;
}