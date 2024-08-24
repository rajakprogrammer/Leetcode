class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort(reverse=True)  # Sort the list in descending order
        return nums[k-1]  # Return the k-th largest element

# Test the function
arr = [1, 23, 12, 9, 2, 50]
k = 3
result = Solution().findKthLargest(arr, k)  # Create an instance and call the method
print("The {}-th largest element is: {}".format(k, result))
