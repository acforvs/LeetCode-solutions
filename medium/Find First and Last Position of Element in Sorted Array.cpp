class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool ok = binary_search(nums.begin(), nums.end(), target);
        if (!ok) return {-1, -1};
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        int second = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {first, second};
    }
};
