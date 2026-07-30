#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    // firstly i need to get timestamps of user 
    int timeStamp;

    // list of follwe id 
    unordered_map<int, unordered_set<int>> following;

    //list of timestamp and tweet id 
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // problem is we need to get track of top 10 tweets so we may tuse minHeap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        // user must include its own tweets
        following[userId].insert(userId);

        for (int followeeId : following[userId]) {
            for (auto &t : tweets[followeeId]) {
                minHeap.push(t);
                if (minHeap.size() > 10) minHeap.pop();
            }
        }

        vector<int> feed;
        while (!minHeap.empty()) {
            feed.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(feed.begin(), feed.end());
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};