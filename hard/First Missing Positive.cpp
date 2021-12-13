class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ok = true; 
                break;
            }
        }
        if (!ok) {
            return 1;
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            if (a == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[a] = -abs(nums[a]);
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }
        
        if (nums[0] > 0) {
            return n;
        }
        
        return n + 1;
    }
};
