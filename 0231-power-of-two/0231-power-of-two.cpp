class Solution {
public:
    bool isPowerOfTwo(int n) {
       if (n <= 0) return false;  // ensure n is positive
       return !(n & (n - 1));
    }
};