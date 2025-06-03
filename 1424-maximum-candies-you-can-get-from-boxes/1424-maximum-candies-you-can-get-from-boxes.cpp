class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, 
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        unordered_set<int> available;  
        unordered_set<int> visited;
        queue<int> q;
        int totalCandies = 0;
        
        for (int box : initialBoxes) {
            if (status[box] == 1) {
                q.push(box);
            } else {
                available.insert(box);
            }
        }
        
        while (!q.empty()) {
            int box = q.front(); q.pop();
            if (visited.count(box)) continue;
            visited.insert(box);
            
            totalCandies += candies[box];
            
            for (int key : keys[box]) {
                status[key] = 1;
                if (available.count(key)) {
                    q.push(key);
                    available.erase(key);
                }
            }

            for (int innerBox : containedBoxes[box]) {
                if (status[innerBox] == 1) {
                    q.push(innerBox);
                } else {
                    available.insert(innerBox);
                }
            }
        }
        
        return totalCandies;
    }
};