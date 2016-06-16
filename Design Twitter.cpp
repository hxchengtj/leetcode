class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<tuple<int, int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    int time_;
    Twitter() {
        time_ = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_tuple(time_, tweetId, userId));
        time_ += 1;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        followees[userId].insert(userId);
        vector<tuple<int, int, int>> h;
        unordered_map<int, int> MAP;
        for (const auto &k : followees[userId]) {
            if (tweets[k].size() > 0) {
                h.push_back(tweets[k].back());
                MAP[k] = tweets[k].size() - 1;
            }
        }
        make_heap(h.begin(), h.end());
        vector<int> newsfeed;
        while(h.size() > 0 && newsfeed.size() < 10) {
            auto t = h[0];
            int uId = get<2>(t), tId = get<1>(t);
            newsfeed.push_back(tId);
            pop_heap(h.begin(), h.end());
            h.pop_back();
            if (MAP[uId] > 0) {
                MAP[uId] -= 1;
                h.push_back(tweets[uId][MAP[uId]]);
                push_heap(h.begin(), h.end());
            }
        }
        return newsfeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
       followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
