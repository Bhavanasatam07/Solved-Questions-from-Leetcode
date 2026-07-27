class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        
        if (target <= nums[0])
            return 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] == target)
                return i;

            if (nums[i - 1] < target && target < nums[i])
                return i;
        }

        return n;
    }
};