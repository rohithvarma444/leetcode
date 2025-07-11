class Solution {
public:
    int value(char ch){
        if(ch == 'L') return 50;
        else if(ch == 'M') return 1000;
        else if(ch == 'I') return 1;
        else if(ch == 'V') return 5;
        else if(ch == 'X') return 10;
        else if(ch == 'C') return 100;
        return 500;
    }

    int romanToInt(string s) {
        int num = 0;
        int curr = 0;
        int n = s.size();

        while (curr < n) {
            if (curr == n - 1) {
                num += value(s[curr]);
                break;
            }

            if (value(s[curr]) < value(s[curr + 1])) {
                num += (value(s[curr + 1]) - value(s[curr]));
                curr += 2;
            } else {
                num += value(s[curr++]);
            }
        }

        return num;
    }
};