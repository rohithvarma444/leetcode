#include <unordered_map>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        for(char c : t) {
            mp[c]--;
            if(mp[c] < 0) {  
                return c;
            }
        }

        return ' '; 
    }
};