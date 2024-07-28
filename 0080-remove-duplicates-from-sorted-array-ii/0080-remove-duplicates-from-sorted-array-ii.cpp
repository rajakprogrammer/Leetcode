#include <vector>

class Solution {
public:
    // Function to remove duplicates from the sorted array 'nums'
    // such that each element appears at most twice.
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0; // Initialize the index for the place to insert the next unique element
        
        // Iterate through each element in the input vector 'nums'
        for (auto e : nums) {
            // Check if the current element can be inserted:
            // - If 'i' is less than 2, we can safely insert the current element
            // - Otherwise, only insert if the current element is different from the element two places back
            if (i == 0 || i == 1 || nums[i - 2] != e) {
                nums[i] = e; // Place the current element at the index 'i'
                i += 1;      // Increment 'i' to point to the next position for insertion
            }
        }
        
        return i; // Return the length of the modified array
    }
};
