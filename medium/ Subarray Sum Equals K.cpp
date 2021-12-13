class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int pref_sum = 0;

        unordered_map<int, int> cnt;
        cnt[0] = 1;

        for (int i = 0; i < n; i++) {
            pref_sum += nums[i];
            if (cnt.find(pref_sum - k) != cnt.end()) {
                ans += cnt[pref_sum - k];
            }
            cnt[pref_sum]++;
        }
        return ans;
    }
};
