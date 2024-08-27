import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) {
            return "";
        }

        // Map to store the frequency of characters in t
        Map<Character, Integer> mapT = new HashMap<>();
        for (char c : t.toCharArray()) {
            mapT.put(c, mapT.getOrDefault(c, 0) + 1);
        }

        // Map to store the frequency of characters in the current window
        Map<Character, Integer> mapWindow = new HashMap<>();
        int left = 0;
        int right = 0;
        int minLength = Integer.MAX_VALUE;
        int minLeft = 0;
        int matchCount = 0;

        while (right < s.length()) {
            char cRight = s.charAt(right);
            if (mapT.containsKey(cRight)) {
                mapWindow.put(cRight, mapWindow.getOrDefault(cRight, 0) + 1);
                if (mapWindow.get(cRight).intValue() == mapT.get(cRight).intValue()) {
                    matchCount++;
                }
            }

            while (matchCount == mapT.size()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                char cLeft = s.charAt(left);
                if (mapT.containsKey(cLeft)) {
                    mapWindow.put(cLeft, mapWindow.get(cLeft) - 1);
                    if (mapWindow.get(cLeft).intValue() < mapT.get(cLeft).intValue()) {
                        matchCount--;
                    }
                }
                left++;
            }

            right++;
        }

        return minLength == Integer.MAX_VALUE ? "" : s.substring(minLeft, minLeft + minLength);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "ADOBECODEBANC";
        String t = "ABC";
        String result = solution.minWindow(s, t);
        System.out.println("Minimum Window Substring: " + result);
    }
}
