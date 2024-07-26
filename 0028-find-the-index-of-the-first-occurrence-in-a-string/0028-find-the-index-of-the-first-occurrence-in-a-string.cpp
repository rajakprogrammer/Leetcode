class Solution {
public:
    int strStr(string haystack, string needle) {
        
        // Get the length of haystack and needle
        int n = haystack.size();
        int m = needle.size();

        // If the length of needle is greater than the length of haystack, needle can't be a substring of haystack
        if (n < m) {
            return -1;
        }

        // Loop through haystack up to the point where the remaining characters are fewer than needle's length
        for (int i = 0; i <= n - m; i++) {
            // Check if the current character in haystack matches the first character of needle
            if (haystack[i] == needle[0]) {
                // Extract substring from haystack starting at i with length m and compare it with needle
                if (haystack.substr(i, m) == needle) {
                    return i;  // Return the starting index if they match
                }
            }
        }

        // If needle is not found in haystack, return -1
        return -1;
    }
};
