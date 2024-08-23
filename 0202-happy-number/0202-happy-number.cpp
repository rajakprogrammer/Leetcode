class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen; // To keep track of numbers we've seen

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumOfSquares(n); // Replace n with the sum of the squares of its digits
        }

        return n == 1; // If we exit the loop because n is 1, then n is happy
    }

private:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};
