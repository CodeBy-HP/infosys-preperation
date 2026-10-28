## Stateful Sliding Window & Rolling Frequency Pattern questions

In such kind of question we keep track of freq or any information about the current window as we move through array or string, instead of recalculating everything from scratch.


## Find All Anagrams in a String (LeetCode 438):

### ## Problem Overview

The **Find All Anagrams in a String** problem requires you to scan a larger string (`s`) and locate every single position (starting index) where a substring matches an anagram of a smaller target string (`p`).

* **Input:** Two text strings, **`s`** (the search space) and **`p`** (the target pattern).
* **Output:** A collection (list or array) of integer indices representing the starting positions in `s` of all substrings that are anagrams of `p`. The result can be returned in any order. If no anagrams exist, the output should be an empty list.

---

### ## Core Concepts

To understand what you are looking for, it helps to break down the fundamental terms used in the problem:

* **Substring:** A contiguous sequence of characters within a string. For example, in the string `"abcde"`, `"bcd"` is a valid substring, but `"ace"` is not because the characters are not contiguous.
* **Anagram:** A word, phrase, or name formed by rearranging the letters of another. Crucially, an anagram must use **all the original letters exactly once**.
* *Example:* The string `"abc"` has anagrams like `"acb"`, `"bac"`, `"bca"`, `"cab"`, and `"cba"`. Non-anagrams of `"abc"` include `"aab"` (wrong frequency) or `"abcd"` (different length).


* **Start Index:** The numerical position (0-indexed) in the string `s` where a matching anagram substring begins.

---

### ## Concrete Examples

#### Example 1

* **Input:** `s = "cbaebabacd"`, `p = "abc"`
* **Output:** `[0, 6]`
* **Explanation:**
* Looking at the substring of `s` starting at index **0** with length 3 (`p.length()`): `"cba"`. This contains the exact same letters as `"abc"`, making it an anagram.
* Looking at the substring starting at index **6**: `"bac"`. This is also an anagram of `"abc"`.
* Other substrings of length 3 do not match the character composition of `"abc"`.



#### Example 2

* **Input:** `s = "abab"`, `p = "ab"`
* **Output:** `[0, 1, 2]`
* **Explanation:**
* Substring at index **0**: `"ab"` (Matches `p`)
* Substring at index **1**: `"ba"` (Anagram of `p`)
* Substring at index **2**: `"ab"` (Matches `p`)



---

### ## Problem Constraints

* Both strings consist solely of **lowercase English letters** (`a` through `z`).
* The length of string `s` and string `p` can range from small values up to tens of thousands of characters.
* The length of the target string `p` will never exceed the length of the main string `s`.


## Permutation in String (LeetCode 567)

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is a contiguous substring of `s2`.

**Example 1:**

* **Input:** `s1 = "ab"`, `s2 = "eidbaooo"`
* **Output:** `true`
* **Explanation:** `s2` contains one permutation of `s1` ("ba").

**Example 2:**

* **Input:** `s1 = "ab"`, `s2 = "eidboaoo"`
* **Output:** `false`
* **Explanation:** The characters are separated by an 'o', so they do not form a contiguous substring.

**Constraints:**

* `1 <= s1.length, s2.length <= 10^4`
* `s1` and `s2` consist of lowercase English letters.

---

## Maximum Points You Can Obtain from Cards (LeetCode 1423)

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array `cardPoints`.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly `k` cards. Your score is the sum of the points of the cards you have taken.

Given the integer array `cardPoints` and the integer `k`, return the maximum score you can obtain.

**Example 1:**

* **Input:** `cardPoints = [1,2,3,4,5,6,1]`, `k = 3`
* **Output:** `12`
* **Explanation:** After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

**Example 2:**

* **Input:** `cardPoints = [2,2,2]`, `k = 2`
* **Output:** `4`
* **Explanation:** Regardless of which two cards you take, your score will always be 4.

**Example 3:**

* **Input:** `cardPoints = [9,7,7,9,7,7,9]`, `k = 7`
* **Output:** `55`
* **Explanation:** You have to take all the cards. Your score is the sum of points of all cards.

**Constraints:**

* `1 <= cardPoints.length <= 10^5`
* `1 <= cardPoints[i] <= 10^4`
* `1 <= k <= cardPoints.length`


## Dynamic Sliding Window + Frequency Array

In these problems, the window size `k` isn't given. You must expand the right side until a condition breaks, then shrink the left side until it is valid again.

## Longest Substring Without Repeating Characters (LeetCode 3)

Given a string `s`, find the length of the longest contiguous substring without repeating characters.

**Example 1:**

* **Input:** `s = "abcabcbb"`
* **Output:** `3`
* **Explanation:** The answer is "abc", with the length of 3.

**Example 2:**

* **Input:** `s = "bbbbb"`
* **Output:** `1`
* **Explanation:** The answer is "b", with the length of 1.

**Example 3:**

* **Input:** `s = "pwwkew"`
* **Output:** `3`
* **Explanation:** The answer is "wke", with the length of 3. Notice that the answer must be a substring, "pwke" is a subsequence and not a contiguous substring.

**Constraints:**

* `0 <= s.length <= 5 * 10^4`
* `s` consists of English letters, digits, symbols, and spaces.

---

## Fruit Into Baskets (LeetCode 904)

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the type of fruit the `i`-th tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

* You only have **two** baskets, and each basket can only hold a **single type** of fruit. There is no limit on the amount of fruit each basket can hold.
* Starting from any tree of your choice, you must pick **exactly one fruit from every tree** (including the start tree) while moving to the right. The picked fruits must fit into one of your baskets.
* Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array `fruits`, return the **maximum** number of fruits you can pick.

**Example 1:**

* **Input:** `fruits = [1,2,1]`
* **Output:** `3`
* **Explanation:** We can pick from all 3 trees.

**Example 2:**

* **Input:** `fruits = [0,1,2,2]`
* **Output:** `3`
* **Explanation:** We can pick from trees [1,2,2]. If we started at the first tree, we would only pick from trees [0,1].

**Example 3:**

* **Input:** `fruits = [1,2,3,2,2]`
* **Output:** `4`
* **Explanation:** We can pick from trees [2,3,2,2]. If we started at the first tree, we would only pick from trees [1,2].

**Constraints:**

* `1 <= fruits.length <= 10^5`
* `0 <= fruits[i] < fruits.length`



## The PBDS Masterclass

When a problem asks for relative positioning (medians, ranks, strictly smaller/larger) and the constraints are massive (e.g., $10^9$), frequency arrays cause Memory Limit Exceeded errors. This is where your PBDS `ordered_set` trick becomes invaluable.

## Sliding Window Median (LeetCode 480)

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, so the median is the mean (average) of the two middle values.

* For example, if `arr = [2,3,4]`, the median is `3`.
* For example, if `arr = [1,2,3,4]`, the median is `(2 + 3) / 2 = 2.5`.

You are given an integer array `nums` and an integer `k`. There is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within `10^-5` of the actual value will be accepted.

**Example 1:**

* **Input:** `nums = [1,3,-1,-3,5,3,6,7]`, `k = 3`
* **Output:** `[1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]`
* **Explanation:**
* `[1 3 -1] -3 5 3 6 7` -> median is `1`
* `1 [3 -1 -3] 5 3 6 7` -> median is `-1`
* `1 3 [-1 -3 5] 3 6 7` -> median is `-1`
* `1 3 -1 [-3 5 3] 6 7` -> median is `3`
* `1 3 -1 -3 [5 3 6] 7` -> median is `5`
* `1 3 -1 -3 5 [3 6 7]` -> median is `6`



**Example 2:**

* **Input:** `nums = [1,2,3,4,2,3,1,4,2]`, `k = 3`
* **Output:** `[2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]`

**Constraints:**

* `1 <= k <= nums.length <= 10^5`
* `-2^31 <= nums[i] <= 2^31 - 1`

---

## Count of Smaller Numbers After Self (LeetCode 315)

Given an integer array `nums`, return an integer array `counts` where `counts[i]` is the number of strictly smaller elements to the right of `nums[i]`.

**Example 1:**

* **Input:** `nums = [5,2,6,1]`
* **Output:** `[2,1,1,0]`
* **Explanation:**
* To the right of `5` there are `2` smaller elements (`2` and `1`).
* To the right of `2` there is only `1` smaller element (`1`).
* To the right of `6` there is `1` smaller element (`1`).
* To the right of `1` there is `0` smaller element.



**Example 2:**

* **Input:** `nums = [-1]`
* **Output:** `[0]`

**Example 3:**

* **Input:** `nums = [-1,-1]`
* **Output:** `[0,0]`

**Constraints:**

* `1 <= nums.length <= 10^5`
* `-10^4 <= nums[i] <= 10^4`