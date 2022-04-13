#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if(nums2.size() < nums1.size())
        swap(nums1, nums2);
    
    // n < m
    int n = nums1.size(), m = nums2.size();

    /*
    Try to determine the left half of the merged sorted array
    the left half can be composed of the left half of nums1, and the left half of nums2
    */
    int total = n + m;
    int half = total / 2;

    // care for boundries, normal would be l = -1, r = n
    // but since we may take 0 elements from nums1 so (l = -1 is in our answer range) 
    int l = -2, r = n, mid;
    while(r-l>1)
    {
        // take 0..mid from nums1 as part of the left half
        mid = l + (r - l) / 2;

        // take the remaining from nums2 (half - mid) - 2 (since mid, j are 0-indexed)
        int i = half - mid - 2;

        int nums1left = (mid >= 0) ? nums1[mid] : INT_MIN;
        int nums1right = (mid + 1 < n) ? nums1[mid + 1] : INT_MAX;
        int nums2left = (i >= 0) ? nums2[i] : INT_MIN;
        int nums2right = (i + 1 < m) ? nums2[i + 1] : INT_MAX;

        if(nums1left <= nums2right && nums2left <= nums1right)
        {
            // odd
            if(total & 1)
            {
                return min(nums1right, nums2right);
            }
            // even
            else
            {
                return (max(nums1left, nums2left) + min(nums1right, nums2right)) / 2.0;
            }
        }
        else if(nums1left > nums2right)
            r = mid;
        else
            l = mid;
    }
    return 0;
}