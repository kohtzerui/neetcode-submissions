class Twitter {
private:
    int count;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count, tweetId});
        if(tweetMap[userId].size() > 10){
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        count--;
    }
    
vector<int> getNewsFeed(int userId) {
    vector<int> res;

    // User should see their own tweets too
    followMap[userId].insert(userId);

    // {time, tweetId, userId, nextIndex}
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > minHeap;

    // Push the latest tweet from each followed user
    for (int followeeId : followMap[userId]) {
        if (!tweetMap.count(followeeId)) {
            continue;
        }

        int idx = tweetMap[followeeId].size() - 1;
        auto& tweet = tweetMap[followeeId][idx];

        int time = tweet.first;
        int tweetId = tweet.second;

        minHeap.push({time, tweetId, followeeId, idx - 1});
    }

    // Pop the 10 most recent tweets
    while (!minHeap.empty() && res.size() < 10) {
        auto cur = minHeap.top();
        minHeap.pop();

        int time = cur[0];
        int tweetId = cur[1];
        int followeeId = cur[2];
        int nextIdx = cur[3];

        res.push_back(tweetId);

        // Push the next newest tweet from the same user
        if (nextIdx >= 0) {
            auto& nextTweet = tweetMap[followeeId][nextIdx];

            int nextTime = nextTweet.first;
            int nextTweetId = nextTweet.second;

            minHeap.push({nextTime, nextTweetId, followeeId, nextIdx - 1});
        }
    }

    return res;
}
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)){
            followMap[followerId].erase(followeeId);
        }
    }
};
