#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cassert>

class Twitter {
private:
    int timestamp;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets; // userId -> list of {time, tweetId}
    std::unordered_map<int, std::unordered_set<int>> following;       // userId -> set of followees

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        // Collect all users whose tweets should be merged: userId + all followees
        std::unordered_set<int> users = following[userId];
        users.insert(userId); // Self tweets included

        // Max-heap storing tuple: {timestamp, tweetId, user, index_in_user_tweets}
        std::priority_queue<std::tuple<int, int, int, int>> maxHeap;

        for (int u : users) {
            if (tweets.count(u) && !tweets[u].empty()) {
                int lastIdx = tweets[u].size() - 1;
                maxHeap.push({tweets[u][lastIdx].first, tweets[u][lastIdx].second, u, lastIdx});
            }
        }

        std::vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            auto [time, tweetId, u, idx] = maxHeap.top();
            maxHeap.pop();

            feed.push_back(tweetId);

            if (idx > 0) {
                int nextIdx = idx - 1;
                maxHeap.push({tweets[u][nextIdx].first, tweets[u][nextIdx].second, u, nextIdx});
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5); // User 1 posts tweet 5

    // User 1's news feed should return [5]
    assert(twitter.getNewsFeed(1) == std::vector<int>({5}));

    twitter.follow(1, 2);    // User 1 follows User 2
    twitter.postTweet(2, 6); // User 2 posts tweet 6

    // News feed should return [6, 5]
    assert(twitter.getNewsFeed(1) == std::vector<int>({6, 5}));

    twitter.unfollow(1, 2);  // User 1 unfollows User 2

    // News feed should return [5]
    assert(twitter.getNewsFeed(1) == std::vector<int>({5}));

    std::cout << "All Design Twitter tests passed successfully!\n";
    return 0;
}

