class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // Phase 1: Find the meeting point inside the cycle
        // (do-while so it doesn't stop immediately at 0 == 0)
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Reset one pointer to head (index 0), walk both 1 step at a time
        int entry = 0;
        while (entry != slow) {
            entry = nums[entry];
            slow = nums[slow];
        }

        return entry; // Cycle entry == the duplicate number
    }
};