class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char toReplaceMax = ' ';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }

        string maxStr = s;
        if (toReplaceMax != ' ') {
            for (char &c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }

        char toReplaceMin = s[0];
        string minStr = s;
        for (char &c : minStr) {
            if (c == toReplaceMin) c = '0';
        }

        int maxVal = stoi(maxStr);
        int minVal = stoi(minStr);

        return maxVal - minVal;
    }
};