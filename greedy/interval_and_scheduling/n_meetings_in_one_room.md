# N Meetings in One Room (Activity Selection)

## Problem Overview
There is one meeting room in a firm. There are $N$ meetings in the form of `(start[i], end[i])` where `start[i]` is the start time of meeting $i$ and `end[i]` is the finish time of meeting $i$.
What is the **maximum number of meetings that can be accommodated in the meeting room**, assuming only one meeting can be held in the meeting room at a particular time?
*(Note: Start time and end time of consecutive meetings cannot be simultaneous: start time must be strictly greater than previous end time).*

---

## Earliest Finish Time Invariant
To maximize the number of meetings, we should always pick the meeting that **finishes as early as possible**:
- Finishing early leaves the **maximum possible remaining time** for accommodating subsequent meetings.
- (Sorting by start time or duration fails: a meeting could start early but run all day, blocking dozens of shorter meetings).

### Algorithmic Workflow:
1. Bundle each meeting as `{start, end, id}`.
2. Sort all meetings in **ascending order of their `end` times**.
3. Pick the first meeting, set `lastEndTime = meeting[0].end`, `count = 1`.
4. Iterate through remaining meetings:
   - If `meeting[i].start > lastEndTime`:
     $$\text{count}++, \quad lastEndTime = meeting[i].end$$

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N)$ to sort meetings.
- **Space Complexity:** $O(N)$ to store meeting tuples.

