class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string commonPrefix = strs[0];
        int n = strs.size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (j >= commonPrefix.size() || commonPrefix[j] != strs[i][j]) {
                    if (j == 0) return "";
                    commonPrefix = commonPrefix.substr(0, j);
                    break;
                }
            }
            if (strs[i].size() < commonPrefix.size()) {
                commonPrefix = commonPrefix.substr(0, strs[i].size());
            }
        }

        return commonPrefix;
    }
};