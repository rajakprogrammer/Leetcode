class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left side
            if (!isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right side
            else if (!isalnum(s[right])) {
                right--;
            }
            // Check if characters are the same ignoring case
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // If characters match, move both pointers
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};
