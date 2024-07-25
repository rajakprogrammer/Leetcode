class Solution {
public:
    int lengthOfLastWord(string s) {
        // Initialize 'i' to the last index of the string 's'
        int i = s.size() - 1;
        
        // Variable to keep track of the length of the last word
        int length = 0;
        
        // Skip any trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Count the characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        // Return the length of the last word
        return length;
    }
};
