class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> triple;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            int target = 0 - nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    triple = {nums[i], nums[j], nums[k]};
                    ans.push_back(triple);
                    while (j < k && nums[j] == triple[1]) j++;
                    while (j < k && nums[j] == triple[2]) k--; 
                }
            }
            while(i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};
