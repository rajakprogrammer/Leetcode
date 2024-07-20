#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1; // Calculate the last index of the merged array
        while (m > 0 && n > 0) { // Loop until one of the arrays is exhausted
            if (nums1[m - 1] > nums2[n - 1]) { // Compare the last elements of the current subarrays
                nums1[last] = nums1[m - 1]; // Place the larger element at the 'last' position
                m -= 1; // Move to the next element in nums1
            } else {
                nums1[last] = nums2[n - 1]; // Place the element from nums2 at the 'last' position
                n -= 1; // Move to the next element in nums2
            }
            last -= 1; // Move to the next position in the merged array
        }
        while (n > 0) { // If there are still elements left in nums2
            nums1[last] = nums2[n - 1]; // Place the remaining elements of nums2 in nums1
            n -= 1; // Move to the next element in nums2
            last -= 1; // Move to the next position in the merged array
        }
    }
};