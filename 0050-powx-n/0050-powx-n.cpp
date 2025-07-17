class Solution {
public:
    double helper(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return 1.0 / helper(x, -n);
        
        double half = helper(x, n / 2);
        
        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;
        return helper(x, N);
    }
};