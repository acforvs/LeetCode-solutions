class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0];
        int h = nums[0];
        
        do {
            t = nums[t];
            h = nums[nums[h]];
        } while (t != h);
        
        t = nums[0];
        while (t != h) {
            t = nums[t];
            h = nums[h];
        }
        
        return h;
    }
};
