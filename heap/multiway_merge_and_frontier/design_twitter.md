# Design Twitter (LeetCode 355)

## Problem Overview
Design a simplified version of Twitter with the following operations:
- `postTweet(userId, tweetId)`: Composes a new tweet with ID `tweetId` by the user `userId`.
- `getNewsFeed(userId)`: Retrieves the **10 most recent tweet IDs** in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from **most recent to least recent**.
- `follow(followerId, followeeId)`: The user with ID `followerId` started following the user with ID `followeeId`.
- `unfollow(followerId, followeeId)`: The user with ID `followerId` stopped following the user with ID `followeeId`.

---

## Architecture: Merge K Sorted Tweet Streams via Max-Heap
1. **Timestamping:** Maintain a global incrementing integer `timestamp`.
2. **Tweet Storage:**
   $$\text{tweets}[userId] \to \text{vector of pairs } \{\text{timestamp}, \; \text{tweetId}\}$$
   Since tweets are appended sequentially, each user's tweet history is naturally sorted by timestamp.
3. **Follower Graph:**
   $$\text{following}[userId] \to \text{unordered\_set of } followeeIds$$
4. **`getNewsFeed(userId)` Optimization (Merge K Sorted Streams):**
   - The news feed merges the latest tweets from `userId` and all users in `following[userId]`.
   - Instead of copying and sorting all tweets from all followed users:
     - Push the **most recent tweet** of each relevant user into a **Max-Heap** prioritized by `timestamp`.
     - Pop the most recent tweet, record its `tweetId`.
     - Push the next older tweet from the same user into the max-heap.
     - Repeat until 10 tweets are collected or the heap empties!

---

## Complexity Analysis
- `postTweet()`: $O(1)$ Time.
- `follow()`, `unfollow()`: $O(1)$ Time.
- `getNewsFeed()`: $O(K \log K + 10 \log K)$ Time where $K$ is the number of followed users (bounded by at most 10 heap operations).
- **Space Complexity:** $O(U + T)$ where $U$ is total users and $T$ is total tweets.

