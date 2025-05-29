class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> userPosts; 
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;

    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for (auto& post : userPosts[userId])
            pq.push(post);

        for (int followeeId : follows[userId]) {
            for (auto& post : userPosts[followeeId])
                pq.push(post);
        }

        vector<int> res;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};