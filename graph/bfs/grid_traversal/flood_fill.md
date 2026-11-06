# Flood Fill Algorithm (LeetCode 733)

## Problem Overview
An image is represented by an $M \times N$ integer grid `image` where `image[i][j]` represents the pixel value.
You are given three integers `sr`, `sc`, and `color`. You should perform a **flood fill** on the image starting from pixel `image[sr][sc]`.
To perform a flood fill:
1. Consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the **same initial color**.
2. Replace the color of all of the aforementioned pixels with `color`.
3. Return the modified image.

---

## Recursive / BFS Invariant
- **Critical Guard Condition:** If `image[sr][sc] == color`, the starting pixel is already the target color! Returning immediately avoids infinite recursion loops without needing a separate `visited` array.
- For all valid 4-neighbors $(nr, nc)$ where `image[nr][nc] == initialColor`:
  Set `image[nr][nc] = color` and recurse / push to queue.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ since each pixel is processed at most once.
- **Space Complexity:** $O(M \times N)$ for the call stack or BFS queue in worst case.

