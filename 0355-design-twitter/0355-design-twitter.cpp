/*
Feed : heap storing all tweets.
To get feed for a particular user ->
check the top tweet, does it belong to the requested user follower ? If it
does-> add in the ans array. Do this till the feed PQ is empty or the ans array
size is 10
*/
class Twitter {
public:
    int tweetCount = 0;
    //<userID, set of followeeID>
    map<int, set<int>> followers;
    // Tweet count, {userId, TweetId}
    priority_queue<pair<int, pair<int, int>>> feed;
    // userId, Tweets (for keeping tweets by users)
    map<int, vector<pair<int, int>>> allUserTweets; // pair<tweetCount, tweetId>

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweetCount++;
        allUserTweets[userId].push_back({tweetCount, tweetId});
        feed.push({tweetCount, {userId, tweetId}});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>> pq = feed;
        set<int> following = followers[userId];
        following.insert(userId); // Also include the user's own tweets

        while (!pq.empty() && ans.size() < 10) {
            auto it = pq.top();
            pq.pop();
            int tweetUserId = it.second.first;
            int tweetId = it.second.second;
            // Check if the tweet is from the user or someone they follow
            if (following.count(tweetUserId)) {
                ans.push_back(tweetId);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].count(followeeId)) {
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */