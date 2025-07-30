class Solution {
public:
    bool isPalindrome(int x) {
        long long y = 0;
        int xx = x;

        while(xx>0){
            y = y*10 + (xx%10);
            xx = xx/10;
        }

        return x == y;
    }
};